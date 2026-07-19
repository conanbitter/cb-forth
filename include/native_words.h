#ifndef NATIVE_H
#define NATIVE_H

#include "common.h"

void code_drop(Cell* data);
void code_swap(Cell* data);
void code_dup(Cell* data);
void code_over(Cell* data);
void code_rot(Cell* data);
void code_nrot(Cell* data);
void code_drop2(Cell* data);
void code_swap2(Cell* data);
void code_dup2(Cell* data);
void code_qdup(Cell* data);
void code_inc(Cell* data);
void code_dec(Cell* data);
void code_inc2(Cell* data);
void code_dec2(Cell* data);
void code_mul2(Cell* data);
void code_div2(Cell* data);
void code_inc4(Cell* data);
void code_dec4(Cell* data);
void code_mul4(Cell* data);
void code_div4(Cell* data);
void code_add(Cell* data);
void code_sub(Cell* data);
void code_mul(Cell* data);
void code_div(Cell* data);
void code_eq(Cell* data);
void code_neq(Cell* data);
void code_less(Cell* data);
void code_greater(Cell* data);
void code_cr(Cell* data);
void code_bl(Cell* data);
void code_fetch(Cell* data);
void code_store(Cell* data);
void code_cfetch(Cell* data);
void code_cstore(Cell* data);
void code_cells(Cell* data);

Cell* find_word();
Cell* get_cfa(Cell* word);
Cell* get_wha(Cell* word_code);
void code_parse(Cell* data);

void code_dot(Cell* data);
void code_pstack(Cell* data);

Cell roundup_to_cells(Cell value);

#endif