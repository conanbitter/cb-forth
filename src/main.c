#include <stdio.h>
#include "common.h"

typedef intptr_t Cell;
#define CELL_WIDTH (sizeof(Cell))
typedef void CodeFunc(Cell* data);

Cell* code_ptr = NULL;

inline void next() {
    code_ptr++;
}

void rpush(Cell data) {
}

Cell rpop() {
    return 0;
}

void c_docol(Cell* data) {
    rpush((Cell)code_ptr);
    code_ptr = data + 1;
}

void c_exit(Cell* data) {
    code_ptr = (Cell*)rpop();
}

const Cell static_dict[] = {
    (Cell)&c_docol
};

int main() {
    code_ptr = &static_dict;
    while (1) {
        (**(CodeFunc**)code_ptr)(code_ptr);
    }
    return 0;
}