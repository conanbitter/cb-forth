import json
from math import ceil
import struct

DICT_NAME = "sys_dict"
CELL_WIDTH = 4
FLAG_IMMED = 0b10000000

dict = []
first = True
latest = 0
latest_prev = 0


def encode_name(name, immed):
    first_byte = len(name)
    if immed:
        first_byte |= FLAG_IMMED
    name_cells = ceil((len(name) + 2) / CELL_WIDTH)
    last_byte = name_cells
    if immed:
        last_byte |= FLAG_IMMED
    name_sector = bytearray()
    name_sector.append(first_byte)
    name_sector.extend(name.encode("utf-8"))
    for _ in range(name_cells * CELL_WIDTH - len(name) - 2):
        name_sector.append(0)
    name_sector.append(last_byte)
    cells = struct.unpack(f'<{name_cells}I', name_sector)
    return [f"0x{i:0{CELL_WIDTH*2}X}" for i in cells]


def get_prev():
    global first, latest, latest_prev
    result = ''
    if first:
        first = False
        result = '0'
        latest = 0
    else:
        result = f"{DICT_NAME} + {latest_prev}"
    latest_prev = latest
    return result


def add_native(name, code, immed):
    global latest
    data = []
    data.append(get_prev())
    data.extend(encode_name(name, False))
    data.append(f"(Cell)&code_{code}")
    dict.append(data)
    latest += len(data)
    # print("native", name, code, immed, data)


words = []

with open("dictionary.json", 'r') as f:
    js = json.load(f)
    words = js['words']

for entry in words:
    if entry['type'] == 'native':
        if 'words' in entry:
            for word in entry['words']:
                add_native(word['name'], word['code'], word.get('immed', False))
        elif 'name' in entry and 'code' in entry:
            add_native(entry['name'], entry['code'], entry.get('immed', False))

max_prev_len = 0
for word in dict:
    if len(word[0]) > max_prev_len:
        max_prev_len = len(word[0])

print(max_prev_len)

for word in dict:
    print(f"{word[0]}, {' '*(max_prev_len-len(word[0]))}", end='')
    print(", ".join(word[1:]))
