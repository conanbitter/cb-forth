#include <stdio.h>
#include "common.h"

int main() {
    init();

    word_ptr = CONST_SYS_LAST;
    while (1) {
        Cell* word = (Cell*)*word_ptr;
        word_ptr++;
        CodeFunc* code = (CodeFunc*)*word;
        (*code)(word);
    }
    return 0;
}