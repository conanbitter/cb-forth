#include <stdio.h>
#include "common.h"

int main() {
    init();
    while (1)
    {
        code_query();
        while (1) {
            get_word();
            if (word_len == 0) break;
            Cell* word = find_word();
            if (word == NULL) {
                printf("Not found");
            } else {
                printf("Found: sys_dict + %d", word - sys_dict);
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