#include <stdio.h>
#include "common.h"

int main() {
    init();
    while (1)
    {
        code_query(0);
        while (1) {
            code_parse(0);
            spush(error);
            code_errtst(0);
            if (error != ERROR_NOERROR) {
                break;
            }
        }
    }

    /*word_ptr = (Cell*)(SYS_QUIT_CFA + 1);
    while (1) {
        Cell* word = (Cell*)*word_ptr;
        word_ptr++;
        CodeFunc* code = (CodeFunc*)*word;
        (*code)(word);
    }*/
    return 0;
}