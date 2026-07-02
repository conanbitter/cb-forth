import json
from math import ceil
import struct

DICT_NAME = "sys_dict"
CELL_WIDTH = 4
FLAG_IMMED = 0b10000000
FLAG_COMPONLY = 0b01000000


def encode_name(name, flags):
    byte_flags = 0
    if 'immed' in flags:
        byte_flags |= FLAG_IMMED
    if 'componly' in flags:
        byte_flags |= FLAG_COMPONLY

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
        self.prev = 0
        self.name = name
        self.flagname = encode_name(name, flags)
        self.code = code
        self.data = []

    def __len__(self):
        return 2 + len(self.flagname) + len(self.data)


latest = None
current_pos = 0
sysdict = []
wordlist = {}


def abs_address(offset):
    return f"{DICT_NAME} + {offset}"


def add_word(word):
    global current_pos, latest
    word.address = current_pos
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
    new_word = DictWord(word_entry['name'], 'lit', [])
    new_word.data.append(str(word_entry['const']))
    add_word(new_word)


def add_var(word_entry):
    new_word = DictWord(word_entry['name'], 'lit', [])
    new_word.data.append(f"(Cell)&{word_entry['var']}")
    add_word(new_word)


def get_wordcode(name):
    word = wordlist[name]
    return word.address + 1 + len(word.flagname)


def add_forth(word_entry):
    new_word = DictWord(word_entry['name'], 'docol', word_entry.get('flags', []))
    for word in word_entry['body']:
        if type(word) is str:
            new_word.data.append(abs_address(get_wordcode(word)))
        elif type(word) is int:
            new_word.data.append(str(word))
    add_word(new_word)


words = []

with open("dictionary.json", 'r') as f:
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

format_table = []
data_table = []

for word in sysdict:
    col1 = "0" if word.prev is None else abs_address(word.prev) + ", "
    col2 = ", ".join(word.flagname) + ", "
    col3 = word.code + (", " if len(word.data) > 0 else ",")
    col4 = (", ".join(word.data) + ",") if len(word.data) > 0 else None
    col5 = f" // {word.name}"
    format_table.append([col1, col2, col3, col5])
    data_table.append(col4)
    # print(word.__dict__)

cols = [0] * 5

for row in format_table:
    for i, col in enumerate(row):
        if len(col) > cols[i]:
            cols[i] = len(col)

for row, data in zip(format_table, data_table):
    for col, l in zip(row, cols):
        print(f"{col:{l}}", end='')
    print()
    if data is not None:
        print("    " + data)
