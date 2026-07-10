#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

#define FORTH_TRUE (-1)
#define FORTH_FALSE (0)
#define LENGTH_MASK (0b00011111)
#define FLAG_IMMED (0b10000000)
#define FLAG_COMPONLY (0b01000000)
#define FLAG_HIDDEN (0b00100000)

typedef intptr_t Cell;
typedef void CodeFunc(Cell* data);

#define CELL_WIDTH (sizeof(Cell))
#define VERSION (1)
#define STACK_SIZE (32)
#define RSTACK_SIZE (16)

#include "core.h"
extern const Cell* SYS_LATEST;
extern const Cell* SYS_QUIT_CFA;
extern const Cell* SYS_DOCOL_CFA;

#include "errors.h"
#include "io.h"
#include "native_words.h"

#endif