#include "common.h"

const Cell sys_dict[155] = {
    (Cell)NULL,             0x434F4425, 0x22004C4F,             (Cell)&code_docol,   // DOCOL   [0]  
    (Cell)(sys_dict + 0),   0x49584544, 0x42000054,             (Cell)&code_exit,    // EXIT    [4]  
    (Cell)(sys_dict + 4),   0x41524246, 0x4248434E,             (Cell)&code_branch,  // BRANCH  [8]  
    (Cell)(sys_dict + 8),   0x52423047, 0x48434E41, 0x43000000, (Cell)&code_zbranch, // 0BRANCH [12] 
    (Cell)(sys_dict + 12),  0x54494C43, 0x42000000,             (Cell)&code_lit,     // LIT     [17] 
    (Cell)(sys_dict + 17),  0x01002E01,                         (Cell)&code_dot,     // .       [21] 
    (Cell)(sys_dict + 21),  0x01532E02,                         (Cell)&code_pstack,  // .S      [24] 
    (Cell)(sys_dict + 24),  0x4F524404, 0x02000050,             (Cell)&code_drop,    // DROP    [27] 
    (Cell)(sys_dict + 27),  0x41575304, 0x02000050,             (Cell)&code_swap,    // SWAP    [31] 
    (Cell)(sys_dict + 31),  0x50554403, 0x02000000,             (Cell)&code_dup,     // DUP     [35] 
    (Cell)(sys_dict + 35),  0x45564F04, 0x02000052,             (Cell)&code_over,    // OVER    [39] 
    (Cell)(sys_dict + 39),  0x544F5203, 0x02000000,             (Cell)&code_rot,     // ROT     [43] 
    (Cell)(sys_dict + 43),  0x4F522D04, 0x02000054,             (Cell)&code_nrot,    // -ROT    [47] 
    (Cell)(sys_dict + 47),  0x52443205, 0x0200504F,             (Cell)&code_drop2,   // 2DROP   [51] 
    (Cell)(sys_dict + 51),  0x57533205, 0x02005041,             (Cell)&code_swap2,   // 2SWAP   [55] 
    (Cell)(sys_dict + 55),  0x55443204, 0x02000050,             (Cell)&code_dup2,    // 2DUP    [59] 
    (Cell)(sys_dict + 59),  0x55443F04, 0x02000050,             (Cell)&code_qdup,    // ?DUP    [63] 
    (Cell)(sys_dict + 63),  0x012B3102,                         (Cell)&code_inc,     // 1+      [67] 
    (Cell)(sys_dict + 67),  0x012D3102,                         (Cell)&code_dec,     // 1-      [70] 
    (Cell)(sys_dict + 70),  0x012B3202,                         (Cell)&code_inc2,    // 2+      [73] 
    (Cell)(sys_dict + 73),  0x012D3202,                         (Cell)&code_dec2,    // 2-      [76] 
    (Cell)(sys_dict + 76),  0x012A3202,                         (Cell)&code_mul2,    // 2*      [79] 
    (Cell)(sys_dict + 79),  0x012F3202,                         (Cell)&code_div2,    // 2/      [82] 
    (Cell)(sys_dict + 82),  0x012B3402,                         (Cell)&code_inc4,    // 4+      [85] 
    (Cell)(sys_dict + 85),  0x012D3402,                         (Cell)&code_dec4,    // 4-      [88] 
    (Cell)(sys_dict + 88),  0x012A3402,                         (Cell)&code_mul4,    // 4*      [91] 
    (Cell)(sys_dict + 91),  0x012F3402,                         (Cell)&code_div4,    // 4/      [94] 
    (Cell)(sys_dict + 94),  0x01002B01,                         (Cell)&code_add,     // +       [97] 
    (Cell)(sys_dict + 97),  0x01002D01,                         (Cell)&code_sub,     // -       [100]
    (Cell)(sys_dict + 100), 0x01002A01,                         (Cell)&code_mul,     // *       [103]
    (Cell)(sys_dict + 103), 0x01002F01,                         (Cell)&code_div,     // /       [106]
    (Cell)(sys_dict + 106), 0x01003D01,                         (Cell)&code_eq,      // =       [109]
    (Cell)(sys_dict + 109), 0x013E3C02,                         (Cell)&code_neq,     // <>      [112]
    (Cell)(sys_dict + 112), 0x01003C01,                         (Cell)&code_less,    // <       [115]
    (Cell)(sys_dict + 115), 0x01003E01,                         (Cell)&code_greater, // >       [118]
    (Cell)(sys_dict + 118), 0x01524302,                         (Cell)&code_cr,      // CR      [121]
    (Cell)(sys_dict + 121), 0x4C454304, 0x0200004C,             (Cell)&code_lit,     // CELL    [124]
        CELL_WIDTH,
    (Cell)(sys_dict + 124), 0x52455607, 0x4E4F4953, 0x03000000, (Cell)&code_lit,     // VERSION [129]
        VERSION,
    (Cell)(sys_dict + 129), 0x53414204, 0x02000045,             (Cell)&code_lit,     // BASE    [135]
        (Cell)&base,
    (Cell)(sys_dict + 135), 0x52524507, 0x45444F43, 0x03000000, (Cell)&code_lit,     // ERRCODE [140]
        (Cell)&error,
    (Cell)(sys_dict + 140), 0x49555104, 0x02000054,             (Cell)&code_docol,   // QUIT    [146]
        (Cell)(sys_dict + 38), (Cell)(sys_dict + 11), 4, (Cell)(sys_dict + 34), (Cell)(sys_dict + 7),
};

const Cell* SYS_LATEST = sys_dict + 146;