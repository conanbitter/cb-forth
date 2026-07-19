#include "common.h"
#include <string.h>

#define USER_DICT_SIZE (1024)

static uint8_t user_dict[USER_DICT_SIZE];

uint8_t* here;

void init_userdict() {
    here = user_dict;
}

void code_newword(Cell* data) {
    get_word();
    uint8_t word_len_cells = roundup_to_cells(word_len + 2);
    *(Cell*)here = (Cell)latest;
    latest = (Cell*)here;
    here += CELL_WIDTH;
    uint8_t* flagname = here;
    *flagname = (uint8_t)word_len;
    flagname++;
    memcpy(flagname, word_buffer, word_len);
    here += word_len_cells * CELL_WIDTH;
    *(here - 1) = word_len_cells;
    *(Cell*)here = (Cell)(&code_docol);
    here += CELL_WIDTH;
}

void code_comma(Cell* data) {
    Cell value = spop();
    *(Cell*)here = value;
    here += CELL_WIDTH;
}

void code_ccomma(Cell* data) {
    Cell value = spop();
    *here = (uint8_t)value;
    here++;
}