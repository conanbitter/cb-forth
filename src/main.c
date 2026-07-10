#include <stdio.h>
#include "common.h"

int main() {
    init();
    /*while (1)
    {
        code_query(0);
        while (1) {
            code_parse(0);
            if (error != ERROR_NOERROR) {
                printf("\nError: %d\n", error);
                break;
            }
        }
    }*/

    word_ptr = sys_dict + 158;
    while (1) {
        Cell* word = (Cell*)*word_ptr;
        word_ptr++;
        CodeFunc* code = (CodeFunc*)*word;
        (*code)(word);
    }
    return 0;
}