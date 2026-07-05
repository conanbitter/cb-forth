#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

#define FORTH_TRUE (-1)
#define FORTH_FALSE (0)
#define LENGTH_MASK (0b00011111)

typedef intptr_t Cell;
typedef void CodeFunc(Cell* data);

#define CELL_WIDTH (sizeof(Cell))
#define VERSION (1)
#define STACK_SIZE (32)
#define RSTACK_SIZE (16)

#include "core.h"
extern const Cell* SYS_LATEST;
extern const Cell sys_dict[];

#include "io.h"
#include "native_words.h"

#endif