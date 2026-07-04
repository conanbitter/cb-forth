#ifndef NATIVE_H
#define NATIVE_H

#include "common.h"

void code_drop(Cell data);
void code_swap(Cell data);
void code_dup(Cell data);
void code_over(Cell data);
void code_rot(Cell data);
void code_nrot(Cell data);
void code_drop2(Cell data);
void code_swap2(Cell data);
void code_dup2(Cell data);
void code_qdup(Cell data);
void code_inc(Cell data);
void code_dec(Cell data);
void code_inc2(Cell data);
void code_dec2(Cell data);
void code_mul2(Cell data);
void code_div2(Cell data);
void code_inc4(Cell data);
void code_dec4(Cell data);
void code_mul4(Cell data);
void code_div4(Cell data);
void code_add(Cell data);
void code_sub(Cell data);
void code_eq(Cell data);
void code_neq(Cell data);
void code_cr(Cell data);


#endif