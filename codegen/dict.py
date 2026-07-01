import json

DICT_NAME = "sys_dict"
CELL_WIDTH = 4

dict = []
first = True
latest = 0


def add_native(name, code, immed):
    print("native", name, code, immed)


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
