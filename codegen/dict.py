import json
from math import ceil
import struct

DICT_NAME = "sys_dict"
LATEST_NAME = "SYS_LATEST"
CELL_WIDTH = 4
FLAG_IMMED = 0b10000000
FLAG_COMPONLY = 0b01000000
FLAG_HIDDEN = 0b00100000


def encode_name(name, flags):
    byte_flags = 0
    if 'immed' in flags:
        byte_flags |= FLAG_IMMED
    if 'componly' in flags:
        byte_flags |= FLAG_COMPONLY
    if 'hidden' in flags:
        byte_flags |= FLAG_HIDDEN

    first_byte = len(name) | byte_flags
    name_cells = ceil((len(name) + 2) / CELL_WIDTH)
    last_byte = name_cells | byte_flags

    name_sector = bytearray()
    name_sector.append(first_byte)
    name_sector.extend(name.encode("utf-8"))
    for _ in range(name_cells * CELL_WIDTH - len(name) - 2):
        name_sector.append(0)
    name_sector.append(last_byte)
    cells = struct.unpack(f'<{name_cells}I', name_sector)
    return [f"0x{i:0{CELL_WIDTH*2}X}" for i in cells]


class DictWord:
    def __init__(self, name, code, flags):
        self.address = 0
        self.cfa = 0
        self.prev = 0
        self.name = name
        self.flagname = encode_name(name, flags)
        self.code = code
        self.data = []

    def __len__(self):
        return 2 + len(self.flagname) + len(self.data)


class FormatTable:
    def __init__(self, cols: int) -> None:
        self.col_count = cols
        self.col_widths = [0] * (cols - 1)
        self.rows = []

    def add_row(self, row: list[str]) -> None:
        self.rows.append(row)

    def __iter__(self):
        self._index = 0
        for row in self.rows:
            for i, col in enumerate(row[:-1]):
                if len(col) > self.col_widths[i]:
                    self.col_widths[i] = len(col)
        return self

    def __next__(self):
        if self._index >= len(self.rows):
            raise StopIteration

        row = "".join([f"{col:{l}}" for col, l in zip(self.rows[self._index][:-1], self.col_widths)])
        row += self.rows[self._index][-1]
        self._index += 1
        return row


latest = None
current_pos = 0
sysdict = []
wordlist = {}


def abs_address(offset):
    return f"{DICT_NAME} + {offset}"


def comp_word(name):
    return f"(Cell)({abs_address(wordlist[name].cfa)})"


def add_word(word):
    global current_pos, latest
    word.address = current_pos
    word.cfa = word.address + 1 + len(word.flagname)
    if latest is None:
        word.prev = None
    else:
        word.prev = latest.address
    current_pos += len(word)
    latest = word
    sysdict.append(word)
    wordlist[word.name] = word


def add_native(entry):
    new_word = DictWord(entry['name'], entry['code'], entry.get('flags', []))
    add_word(new_word)


def add_const(word_entry):
    new_word = DictWord(word_entry['name'], 'docol', [])
    new_word.data.extend([comp_word('LIT'), str(word_entry['const']), comp_word('EXIT')])
    add_word(new_word)


def add_var(word_entry):
    new_word = DictWord(word_entry['name'], 'docol', [])
    new_word.data.extend([comp_word('LIT'), f"(Cell)&{word_entry['var']}", comp_word('EXIT')])
    add_word(new_word)


def add_forth(word_entry):
    new_word = DictWord(word_entry['name'], 'docol', word_entry.get('flags', []))
    for word in word_entry['body']:
        if type(word) is str:
            new_word.data.append(comp_word(word))
        elif type(word) is int:
            new_word.data.append(str(word))
    add_word(new_word)


words = []

with open("codegen/dictionary.json", 'r') as f:
    js = json.load(f)
    words = js['words']

for entry in words:
    proc_fun = None
    if entry['type'] == 'native':
        proc_fun = add_native
    elif entry['type'] == 'const':
        proc_fun = add_const
    elif entry['type'] == 'var':
        proc_fun = add_var
    elif entry['type'] == 'forth':
        proc_fun = add_forth
    else:
        continue

    if 'words' in entry:
        for word in entry['words']:
            proc_fun(word)
    else:
        proc_fun(entry)

main_table = FormatTable(6)
data_table = []
total_cells = 0
addresses = {}

for word in sysdict:
    addresses[f"(Cell)({abs_address(word.address)})"] = word.name + "(head)"
    addresses[f"(Cell)({abs_address(word.cfa)})"] = word.name

for word in sysdict:
    col_prev = "(Cell)NULL," if word.prev is None else f"(Cell)({abs_address(word.prev)}), "
    col_flagname = ", ".join(word.flagname) + ", "
    col_code = "(Cell)&code_" + word.code + (", " if len(word.data) > 0 else ",")
    col_rem_name = f" // {word.name}"
    col_rem_address = f" [{word.address}, CFA:{word.cfa}]"

    col_data = None
    if len(word.data) > 0:
        col_data = FormatTable(2)
        for item in word.data:
            col_data.add_row([item + ",", "" if item not in addresses else "  // " + addresses[item]])

    main_table.add_row([col_prev, col_flagname, col_code, col_rem_name, col_rem_address])
    data_table.append(col_data)

    total_cells += 1 + len(word.flagname) + 1 + len(word.data)

was_space = False

consts = FormatTable(2)
consts.add_row([f"const Cell* {LATEST_NAME}", f" = {abs_address(latest.address)};\n"])  # type: ignore
consts.add_row(["const Cell* SYS_QUIT_CFA", f" = {abs_address(wordlist['QUIT'].cfa)};\n"])
consts.add_row(["const Cell* SYS_DOCOL_CFA", f" = {abs_address(wordlist['DOCOL'].cfa)};\n"])

with open("src/dict.c", 'w') as f:
    f.write("#include \"common.h\"\n\n")
    f.write(f"static const Cell {DICT_NAME}[{total_cells}] = {{\n")
    for row, data in zip(main_table, data_table):
        if data is not None and not was_space:
            f.write("\n")
        f.write("    ")
        f.write(row)
        f.write("\n")
        if data is not None:
            for data_item in data:
                f.write("        " + data_item + "\n")
            f.write("\n")
            was_space = True
        else:
            was_space = False

    f.write("};\n\n")
    for const_line in consts:
        f.write(const_line)
