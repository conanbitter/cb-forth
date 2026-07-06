#include "common.h"

const Cell sys_dict[143] = {
    (Cell)NULL,             0x434F4425, 0x22004C4F,             (Cell)&code_docol,   // DOCOL   [0]  
    (Cell)(sys_dict + 0),   0x49584544, 0x42000054,             (Cell)&code_exit,    // EXIT    [4]  
    (Cell)(sys_dict + 4),   0x41524246, 0x4248434E,             (Cell)&code_branch,  // BRANCH  [8]  
    (Cell)(sys_dict + 8),   0x52423047, 0x48434E41, 0x43000000, (Cell)&code_zbranch, // 0BRANCH [12] 
    (Cell)(sys_dict + 12),  0x54494C43, 0x42000000,             (Cell)&code_lit,     // LIT     [17] 
    (Cell)(sys_dict + 17),  0x4F524404, 0x02000050,             (Cell)&code_drop,    // DROP    [21] 
    (Cell)(sys_dict + 21),  0x41575304, 0x02000050,             (Cell)&code_swap,    // SWAP    [25] 
    (Cell)(sys_dict + 25),  0x50554403, 0x02000000,             (Cell)&code_dup,     // DUP     [29] 
    (Cell)(sys_dict + 29),  0x45564F04, 0x02000052,             (Cell)&code_over,    // OVER    [33] 
    (Cell)(sys_dict + 33),  0x544F5203, 0x02000000,             (Cell)&code_rot,     // ROT     [37] 
    (Cell)(sys_dict + 37),  0x4F522D04, 0x02000054,             (Cell)&code_nrot,    // -ROT    [41] 
    (Cell)(sys_dict + 41),  0x52443205, 0x0200504F,             (Cell)&code_drop2,   // 2DROP   [45] 
    (Cell)(sys_dict + 45),  0x57533205, 0x02005041,             (Cell)&code_swap2,   // 2SWAP   [49] 
    (Cell)(sys_dict + 49),  0x55443204, 0x02000050,             (Cell)&code_dup2,    // 2DUP    [53] 
    (Cell)(sys_dict + 53),  0x55443F04, 0x02000050,             (Cell)&code_qdup,    // ?DUP    [57] 
    (Cell)(sys_dict + 57),  0x012B3102,                         (Cell)&code_inc,     // 1+      [61] 
    (Cell)(sys_dict + 61),  0x012D3102,                         (Cell)&code_dec,     // 1-      [64] 
    (Cell)(sys_dict + 64),  0x012B3202,                         (Cell)&code_inc2,    // 2+      [67] 
    (Cell)(sys_dict + 67),  0x012D3202,                         (Cell)&code_dec2,    // 2-      [70] 
    (Cell)(sys_dict + 70),  0x012A3202,                         (Cell)&code_mul2,    // 2*      [73] 
    (Cell)(sys_dict + 73),  0x012F3202,                         (Cell)&code_div2,    // 2/      [76] 
    (Cell)(sys_dict + 76),  0x012B3402,                         (Cell)&code_inc4,    // 4+      [79] 
    (Cell)(sys_dict + 79),  0x012D3402,                         (Cell)&code_dec4,    // 4-      [82] 
    (Cell)(sys_dict + 82),  0x012A3402,                         (Cell)&code_mul4,    // 4*      [85] 
    (Cell)(sys_dict + 85),  0x012F3402,                         (Cell)&code_div4,    // 4/      [88] 
    (Cell)(sys_dict + 88),  0x01002B01,                         (Cell)&code_add,     // +       [91] 
    (Cell)(sys_dict + 91),  0x01002D01,                         (Cell)&code_sub,     // -       [94] 
    (Cell)(sys_dict + 94),  0x01003D01,                         (Cell)&code_eq,      // =       [97] 
    (Cell)(sys_dict + 97),  0x013E3C02,                         (Cell)&code_neq,     // <>      [100]
    (Cell)(sys_dict + 100), 0x01003C01,                         (Cell)&code_less,    // <       [103]
    (Cell)(sys_dict + 103), 0x01003E01,                         (Cell)&code_greater, // >       [106]
    (Cell)(sys_dict + 106), 0x01524302,                         (Cell)&code_cr,      // CR      [109]
    (Cell)(sys_dict + 109), 0x4C454304, 0x0200004C,             (Cell)&code_lit,     // CELL    [112]
        CELL_WIDTH,
    (Cell)(sys_dict + 112), 0x52455607, 0x4E4F4953, 0x03000000, (Cell)&code_lit,     // VERSION [117]
        VERSION,
    (Cell)(sys_dict + 117), 0x53414204, 0x02000045,             (Cell)&code_lit,     // BASE    [123]
        (Cell)&base,
    (Cell)(sys_dict + 123), 0x52524507, 0x45444F43, 0x03000000, (Cell)&code_lit,     // ERRCODE [128]
        (Cell)&error,
    (Cell)(sys_dict + 128), 0x49555104, 0x02000054,             (Cell)&code_docol,   // QUIT    [134]
        (Cell)(sys_dict + 32), (Cell)(sys_dict + 11), 4, (Cell)(sys_dict + 28), (Cell)(sys_dict + 7),
};

const Cell* SYS_LATEST = sys_dict + 134;