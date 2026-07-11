#include <stdio.h>
#include "common.h"

int main() {
    print_str("CB Forth v0.1\n");
    word_ptr = (Cell*)(SYS_QUIT_CFA + 1);
    while (1) {
        Cell* word = (Cell*)*word_ptr;
        word_ptr++;
        CodeFunc* code = (CodeFunc*)*word;
        (*code)(word);
    }
    return 0;
}