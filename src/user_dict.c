#include "common.h"
#include <string.h>

#define USER_DICT_SIZE (1024)

static Cell user_dict[USER_DICT_SIZE];

Cell* here;

void init_userdict() {
    here = user_dict;
}

void code_newword() {
    get_word();
    uint8_t word_len_cells = roundup_to_cells(word_len);
    *here = (Cell)latest;
    latest = here;
    here++;
    uint8_t* flagname = (uint8_t*)here;
    *flagname = (uint8_t)word_len;
    flagname++;
    memcpy(flagname, word_buffer, word_len);
    here += word_len_cells;
    *((uint8_t*)here - 1) = word_len_cells;
    *here = (Cell)(&code_docol);
    here++;
}