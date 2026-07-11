#include "common.h"

Cell* word_ptr;

static Cell stack[STACK_SIZE];
static Cell* stack_ptr;

static Cell rstack[RSTACK_SIZE];
static Cell* rstack_ptr;

Cell error;
Cell base;
Cell* latest;
Cell state;

void reset() {
    stack_ptr = stack;
    rstack_ptr = rstack;
    error = 0;
    state = FORTH_FALSE;
}

void code_init(Cell data) {
    base = 10;
    latest = (Cell*)SYS_LATEST;
    reset();
}

void spush(Cell data) {
    *stack_ptr = data;
    stack_ptr++;
}

Cell spop() {
    stack_ptr--;
    Cell data = *stack_ptr;
    return data;
}

Cell speek(Cell depth) {
    return *(stack_ptr - depth - 1);
}

void sdump() {
    Cell* cur = stack_ptr;
    cur--;
    while (cur >= stack)
    {
        printf("%d ", *cur);
        cur--;
    }
}

void rpush(Cell data) {
    *rstack_ptr = data;
    rstack_ptr++;
}

Cell rpop() {
    rstack_ptr--;
    Cell data = *rstack_ptr;
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