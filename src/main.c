#include <stdio.h>
#include "common.h"

int main() {
    base = 10;
    while (1)
    {
        print_int(105);
        code_query();
        while (1) {
            get_word();
            if (word_len == 0) break;
            Cell num = str_to_int();
            if (error == 0) {
                printf("number: %d\n", num);
            } else {
                print_word();
            }
        }
    }

    /*init();

    word_ptr = CONST_SYS_LAST;
    while (1) {
        Cell* word = (Cell*)*word_ptr;
        word_ptr++;
        CodeFunc* code = (CodeFunc*)*word;
        (*code)(word);
    }*/
    return 0;
}