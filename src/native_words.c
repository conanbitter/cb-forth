#include "common.h"

Cell roundup_to_cells(Cell value) {
    return (value + (CELL_WIDTH - 1)) / CELL_WIDTH;
}

// ===========
//    BASIC
// ===========

void code_drop(Cell* data) {
    spop();
}

void code_swap(Cell* data) {
    Cell a = spop();
    Cell b = spop();
    spush(a);
    spush(b);
}

void code_dup(Cell* data) {
    Cell a = speek(0);
    spush(a);
}

void code_over(Cell* data) {
    Cell a = speek(1);
    spush(a);
}

void code_rot(Cell* data) {
    // c b a -> b a c
    Cell a = spop();
    Cell b = spop();
    Cell c = spop();
    spush(b);
    spush(a);
    spush(c);
}

void code_nrot(Cell* data) {
    // c b a -> a c b
    Cell a = spop();
    Cell b = spop();
    Cell c = spop();
    spush(a);
    spush(c);
    spush(b);
}

void code_drop2(Cell* data) {
    spop();
    spop();
}

void code_swap2(Cell* data) {
    // d c b a -> b a d c
    Cell a = spop();
    Cell b = spop();
    Cell c = spop();
    Cell d = spop();
    spush(b);
    spush(a);
    spush(d);
    spush(c);
}

void code_dup2(Cell* data) {
    // b a -> b a b a
    Cell a = spop();
    Cell b = spop();
    spush(b);
    spush(a);
    spush(b);
    spush(a);
}

void code_qdup(Cell* data) {
    Cell a = speek(0);
    if (a != 0) spush(a);
}

void code_inc(Cell* data) {
    Cell a = spop();
    spush(a + 1);
}

void code_dec(Cell* data) {
    Cell a = spop();
    spush(a - 1);
}

void code_inc2(Cell* data) {
    Cell a = spop();
    spush(a + 2);
}

void code_dec2(Cell* data) {
    Cell a = spop();
    spush(a - 2);
}

void code_mul2(Cell* data) {
    Cell a = spop();
    spush(a << 1);
}

void code_div2(Cell* data) {
    Cell a = spop();
    spush(a >> 1);
}

void code_inc4(Cell* data) {
    Cell a = spop();
    spush(a + 4);
}

void code_dec4(Cell* data) {
    Cell a = spop();
    spush(a - 1);
}

void code_mul4(Cell* data) {
    Cell a = spop();
    spush(a << 2);
}

void code_div4(Cell* data) {
    Cell a = spop();
    spush(a >> 2);
}

void code_add(Cell* data) {
    Cell a = spop();
    Cell b = spop();
    spush(b + a);
}

void code_sub(Cell* data) {
    Cell a = spop();
    Cell b = spop();
    spush(b - a);
}

void code_mul(Cell* data) {
    Cell a = spop();
    Cell b = spop();
    spush(b * a);
}

void code_div(Cell* data) {
    Cell a = spop();
    Cell b = spop();
    spush(b / a);
}

void code_eq(Cell* data) {
    Cell a = spop();
    Cell b = spop();
    spush(a == b ? FORTH_TRUE : FORTH_FALSE);
}

void code_neq(Cell* data) {
    Cell a = spop();
    Cell b = spop();
    spush(a != b ? FORTH_TRUE : FORTH_FALSE);
}

void code_less(Cell* data) {
    Cell a = spop();
    Cell b = spop();
    spush(b < a ? FORTH_TRUE : FORTH_FALSE);
}

void code_greater(Cell* data) {
    Cell a = spop();
    Cell b = spop();
    spush(b > a ? FORTH_TRUE : FORTH_FALSE);
}

void code_cr(Cell* data) {
    print_char('\n');
}

void code_bl(Cell* data) {
    spush(' ');
}

void code_fetch(Cell* data) {
    Cell* addr = (Cell*)spop();
    spush(*addr);
}

void code_store(Cell* data) {
    Cell* addr = (Cell*)spop();
    Cell value = spop();
    *addr = value;
}

void code_cfetch(Cell* data) {
    char* addr = (char*)spop();
    char value = *addr;
    spush((Cell)value);
}

void code_cstore(Cell* data) {
    char* addr = (char*)spop();
    Cell value = spop();
    *addr = (char)value;
}

void code_cells(Cell* data) {
    Cell value = spop();
    spush(value * CELL_WIDTH);
}

// ===================
//   WORD MANAGEMENT
// ===================

Cell* find_word() {
    Cell* current_word = latest;
    while (current_word != NULL) {
        Cell* prev = (Cell*)*current_word;
        Cell* this_word = current_word;
        current_word++;
        uint8_t flags = *(uint8_t*)current_word;
        if (flags & FLAG_HIDDEN) {
            current_word = prev;
            continue;
        }
        uint8_t length = flags & LENGTH_MASK;
        if (length != word_len) {
            current_word = prev;
            continue;
        }
        char* dict_word = (char*)current_word + 1;
        char* buf_word = word_buffer;
        for (int i = 0;i < length;i++) {
            if (*dict_word != *buf_word) {
                current_word = prev;
                break;
            }
            dict_word++;
            buf_word++;
        }
        if (current_word != prev) {
            return this_word;
        }
    }
    return NULL;
}

Cell* get_cfa(Cell* word) {
    uint8_t name_length = (*((uint8_t*)(word + 1))) & LENGTH_MASK;
    Cell name_length_cells = roundup_to_cells(name_length + 2);
    return word + 1 + name_length_cells;
}

Cell* get_wha(Cell* word_code) {
    uint8_t name_length_cells = (*((uint8_t*)word_code - 1));
    return word_code - 1 - name_length_cells;
}

void code_parse(Cell* data) {
    get_word();

    if (word_len == 0) {
        error = ERROR_EOF;
        return;
    }

    Cell* word = find_word();
    if (word != NULL) {
        error = ERROR_NOERROR;
        Cell* word_code = get_cfa(word);
        CodeFunc* code = (CodeFunc*)*word_code;
        //printf("Running [sys_dict + %d]\n", word - sys_dict);
        (*code)(word_code);
        return;
    }

    Cell num = str_to_int();
    if (error == 0) {
        error = ERROR_NOERROR;
        spush(num);
        return;
    }

    error = ERROR_UNKNOWN_WORD;
}

// ================
//   INPUT/OUTPUT
// ================

void code_dot(Cell* data) {
    Cell value = spop();
    print_int(value);
    print_char(' ');
}

void code_pstack(Cell* data) {
    sdump();
}