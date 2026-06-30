#ifndef CORE_H
#define CORE_H

#include "common.h"

extern Cell* word_ptr;

void init();

void spush(Cell data);
Cell spop();

void rpush(Cell data);
Cell rpop();

void code_docol(Cell* data);
void code_exit(Cell* data);
void code_branch(Cell* data);
void code_zbranch(Cell* data);
void code_lit(Cell* data);

#endif