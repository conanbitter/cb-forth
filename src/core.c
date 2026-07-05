#include "common.h"

Cell* word_ptr;

static Cell stack[STACK_SIZE];
static Cell* stack_ptr;

static Cell rstack[RSTACK_SIZE];
static Cell* rstack_ptr;

Cell error;
Cell base;
Cell* latest;

void init() {
    stack_ptr = stack;
    rstack_ptr = rstack;
    base = 10;
    error = 0;
    latest = (Cell*)SYS_LATEST;
}

void spush(Cell data) {
    *stack_ptr = data;
    stack_ptr++;
}

Cell spop() {
    Cell data = *stack_ptr;
    stack_ptr--;
    return data;
}

Cell speek(Cell depth) {
    return *(stack_ptr - depth);
}

void rpush(Cell data) {
    *rstack_ptr = data;
    rstack_ptr++;
}

Cell rpop() {
    Cell data = *rstack_ptr;
    rstack_ptr--;
    return data;
}

void code_docol(Cell* data) {
    rpush((Cell)word_ptr);
    word_ptr = data + 1;
}

void code_exit(Cell* data) {
    word_ptr = (Cell*)rpop();
}

void code_branch(Cell* data) {
    Cell offset = *word_ptr;
    word_ptr += offset;
}

void code_zbranch(Cell* data) {
    if (spop() == 0) {
        Cell offset = *word_ptr;
        word_ptr += offset;
    } else {
        word_ptr++;
    }
}

void code_lit(Cell* data) {
    spush(*word_ptr);
    word_ptr++;
}