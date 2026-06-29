#include <stdio.h>
#include "common.h"

typedef intptr_t Cell;
#define CELL_WIDTH (sizeof(Cell))
typedef void CodeFunc(Cell* data);
#define STACK_SIZE (32)
#define RSTACK_SIZE (16)

Cell* code_ptr = NULL;
Cell stack[STACK_SIZE];
Cell* stack_ptr = &stack;
Cell rstack[RSTACK_SIZE];
Cell* rstack_ptr = &stack;

inline void next() {
    code_ptr++;
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
    rpush((Cell)code_ptr);
    code_ptr = data + 1;
}

void code_exit(Cell* data) {
    code_ptr = (Cell*)rpop();
}

void code_branch(Cell* data) {

}

void code_zbranch(Cell* data) {

}

void code_lit(Cell* data) {

}

const Cell static_dict[] = {
    (Cell)&code_docol
};

int main() {
    code_ptr = &static_dict;
    while (1) {
        (**(CodeFunc**)code_ptr)(code_ptr);
    }
    return 0;
}