#ifndef ERRORS_H
#define ERRORS_H

#define ERROR_NOERROR       (0)
#define ERROR_EOF           (1)
#define ERROR_UNKNOWN_WORD  (2)
#define ERROR_WORD_EXPECTED (3)
#define ERROR_OTHER         (1000)

void code_errtst(Cell* data);

#endif