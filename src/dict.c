#include "common.h"

static const Cell sys_dict[5] = {
    1,
    2,
    (Cell)&code_docol,
    3,
    (Cell)(sys_dict + 2),
};

Cell* const CONST_SYS_LAST = (Cell*)sys_dict + 4;