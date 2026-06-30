#include <stdio.h>
#include "common.h"

typedef intptr_t Cell;
#define CELL_WIDTH (sizeof(Cell))
typedef void CodeFunc(Cell* data);
#define STACK_SIZE (32)
#define RSTACK_SIZE (16)

Cell* word_ptr = NULL;
Cell stack[STACK_SIZE];
Cell* stack_ptr = stack;
Cell rstack[RSTACK_SIZE];
Cell* rstack_ptr = rstack;

void spush(Cell data) {
    *stack_ptr = data;
    stack_ptr++;
}

Cell spop() {
    Cell data = *stack_ptr;
    stack_ptr--;
    return data;
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

const Cell static_dict[5] = {
    1,
    2,
    (Cell)&code_docol,
    3,
    (Cell)(static_dict + 2),
};

int main() {
    word_ptr = (Cell*)(static_dict + 4);
    while (1) {
        Cell* word = (Cell*)*word_ptr;
        word_ptr++;
        CodeFunc* code = (CodeFunc*)*word;
        (*code)(word);
    }
    return 0;
}