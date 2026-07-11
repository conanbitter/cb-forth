#include "common.h"

static const char* ERROR_LIST[] = {
    " error: word expected",
};

#define ERRLIST_LENGTH (sizeof(ERROR_LIST)/sizeof(ERROR_LIST[0]))

void code_errtst(Cell* data) {
    Cell err_code = spop();
    switch (err_code)
    {
    case ERROR_NOERROR:
        return;

    case ERROR_EOF:
        if (state == FORTH_FALSE) {
            printf(" ok");
        }
        break;

    case ERROR_UNKNOWN_WORD:
        printf(" ? '%s'", word_buffer);
        break;

    default:
        err_code -= 3;
        if (err_code < ERRLIST_LENGTH) {
            print_str(ERROR_LIST[err_code]);
        } else {
            printf(" error");
        }
        break;
    }
}