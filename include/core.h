#ifndef CORE_H
#define CORE_H

#include "common.h"

extern Cell* word_ptr;
extern Cell error;
extern Cell base;
extern Cell* latest;
extern Cell state;

void reset();
void code_init(Cell data);

void spush(Cell data);
Cell spop();
Cell speek(Cell depth);
void sdump();

void rpush(Cell data);
Cell rpop();

void code_docol(Cell* data);
void code_exit(Cell* data);
void code_branch(Cell* data);
void code_zbranch(Cell* data);
void code_lit(Cell* data);

#endif