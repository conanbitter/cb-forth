#include <stdio.h>
#include "common.h"

int main() {
    init();
    while (1)
    {
        code_query(0);
        while (1) {
            code_parse(0);
            if (error != ERROR_NOERROR) {
                printf("Error: %d\n", error);
                break;
            }
            printf("word_ptr = sys_dict + %d\n", word_ptr - sys_dict);
            printf("stack: ");
            sdump();
            printf("\n\n");
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