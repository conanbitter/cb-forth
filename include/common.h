#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

typedef intptr_t Cell;
typedef void CodeFunc(Cell* data);

#define CELL_WIDTH (sizeof(Cell))
#define STACK_SIZE (32)
#define RSTACK_SIZE (16)

#include "core.h"
extern Cell* const CONST_SYS_LAST;

#include "io.h"
#include "native_words.h"

#endif