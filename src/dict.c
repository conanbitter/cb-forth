#include "common.h"

static const Cell sys_dict[206] = {
    (Cell)NULL,             0x434F4425, 0x22004C4F,             (Cell)&code_docol,   // DOCOL   [0, CFA:3]
    (Cell)(sys_dict + 0),   0x49584544, 0x42000054,             (Cell)&code_exit,    // EXIT    [4, CFA:7]
    (Cell)(sys_dict + 4),   0x41524246, 0x4248434E,             (Cell)&code_branch,  // BRANCH  [8, CFA:11]
    (Cell)(sys_dict + 8),   0x52423047, 0x48434E41, 0x43000000, (Cell)&code_zbranch, // 0BRANCH [12, CFA:16]
    (Cell)(sys_dict + 12),  0x54494C43, 0x42000000,             (Cell)&code_lit,     // LIT     [17, CFA:20]
    (Cell)(sys_dict + 17),  0x01002E01,                         (Cell)&code_dot,     // .       [21, CFA:23]
    (Cell)(sys_dict + 21),  0x01532E02,                         (Cell)&code_pstack,  // .S      [24, CFA:26]
    (Cell)(sys_dict + 24),  0x45555105, 0x02005952,             (Cell)&code_query,   // QUERY   [27, CFA:30]
    (Cell)(sys_dict + 27),  0x524F5704, 0x02000044,             (Cell)&code_word,    // WORD    [31, CFA:34]
    (Cell)(sys_dict + 31),  0x59454B03, 0x02000000,             (Cell)&code_key,     // KEY     [35, CFA:38]
    (Cell)(sys_dict + 35),  0x494D4504, 0x02000054,             (Cell)&code_emit,    // EMIT    [39, CFA:42]
    (Cell)(sys_dict + 39),  0x4F524404, 0x02000050,             (Cell)&code_drop,    // DROP    [43, CFA:46]
    (Cell)(sys_dict + 43),  0x41575304, 0x02000050,             (Cell)&code_swap,    // SWAP    [47, CFA:50]
    (Cell)(sys_dict + 47),  0x50554403, 0x02000000,             (Cell)&code_dup,     // DUP     [51, CFA:54]
    (Cell)(sys_dict + 51),  0x45564F04, 0x02000052,             (Cell)&code_over,    // OVER    [55, CFA:58]
    (Cell)(sys_dict + 55),  0x544F5203, 0x02000000,             (Cell)&code_rot,     // ROT     [59, CFA:62]
    (Cell)(sys_dict + 59),  0x4F522D04, 0x02000054,             (Cell)&code_nrot,    // -ROT    [63, CFA:66]
    (Cell)(sys_dict + 63),  0x52443205, 0x0200504F,             (Cell)&code_drop2,   // 2DROP   [67, CFA:70]
    (Cell)(sys_dict + 67),  0x57533205, 0x02005041,             (Cell)&code_swap2,   // 2SWAP   [71, CFA:74]
    (Cell)(sys_dict + 71),  0x55443204, 0x02000050,             (Cell)&code_dup2,    // 2DUP    [75, CFA:78]
    (Cell)(sys_dict + 75),  0x55443F04, 0x02000050,             (Cell)&code_qdup,    // ?DUP    [79, CFA:82]
    (Cell)(sys_dict + 79),  0x012B3102,                         (Cell)&code_inc,     // 1+      [83, CFA:85]
    (Cell)(sys_dict + 83),  0x012D3102,                         (Cell)&code_dec,     // 1-      [86, CFA:88]
    (Cell)(sys_dict + 86),  0x012B3202,                         (Cell)&code_inc2,    // 2+      [89, CFA:91]
    (Cell)(sys_dict + 89),  0x012D3202,                         (Cell)&code_dec2,    // 2-      [92, CFA:94]
    (Cell)(sys_dict + 92),  0x012A3202,                         (Cell)&code_mul2,    // 2*      [95, CFA:97]
    (Cell)(sys_dict + 95),  0x012F3202,                         (Cell)&code_div2,    // 2/      [98, CFA:100]
    (Cell)(sys_dict + 98),  0x012B3402,                         (Cell)&code_inc4,    // 4+      [101, CFA:103]
    (Cell)(sys_dict + 101), 0x012D3402,                         (Cell)&code_dec4,    // 4-      [104, CFA:106]
    (Cell)(sys_dict + 104), 0x012A3402,                         (Cell)&code_mul4,    // 4*      [107, CFA:109]
    (Cell)(sys_dict + 107), 0x012F3402,                         (Cell)&code_div4,    // 4/      [110, CFA:112]
    (Cell)(sys_dict + 110), 0x01002B01,                         (Cell)&code_add,     // +       [113, CFA:115]
    (Cell)(sys_dict + 113), 0x01002D01,                         (Cell)&code_sub,     // -       [116, CFA:118]
    (Cell)(sys_dict + 116), 0x01002A01,                         (Cell)&code_mul,     // *       [119, CFA:121]
    (Cell)(sys_dict + 119), 0x01002F01,                         (Cell)&code_div,     // /       [122, CFA:124]
    (Cell)(sys_dict + 122), 0x01003D01,                         (Cell)&code_eq,      // =       [125, CFA:127]
    (Cell)(sys_dict + 125), 0x013E3C02,                         (Cell)&code_neq,     // <>      [128, CFA:130]
    (Cell)(sys_dict + 128), 0x01003C01,                         (Cell)&code_less,    // <       [131, CFA:133]
    (Cell)(sys_dict + 131), 0x01003E01,                         (Cell)&code_greater, // >       [134, CFA:136]
    (Cell)(sys_dict + 134), 0x01524302,                         (Cell)&code_cr,      // CR      [137, CFA:139]
    (Cell)(sys_dict + 137), 0x014C4202,                         (Cell)&code_bl,      // BL      [140, CFA:142]
    (Cell)(sys_dict + 140), 0x01004001,                         (Cell)&code_fetch,   // @       [143, CFA:145]
    (Cell)(sys_dict + 143), 0x01002101,                         (Cell)&code_store,   // !       [146, CFA:148]
    (Cell)(sys_dict + 146), 0x01404302,                         (Cell)&code_cfetch,  // C@      [149, CFA:151]
    (Cell)(sys_dict + 149), 0x01214302,                         (Cell)&code_cstore,  // C!      [152, CFA:154]

    (Cell)(sys_dict + 152), 0x4C454304, 0x0200004C,             (Cell)&code_docol,   // CELL    [155, CFA:158]
        (Cell)(sys_dict + 20),  // LIT
        CELL_WIDTH,           
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 155), 0x52455607, 0x4E4F4953, 0x03000000, (Cell)&code_docol,   // VERSION [162, CFA:166]
        (Cell)(sys_dict + 20),  // LIT
        VERSION,              
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 162), 0x53414204, 0x02000045,             (Cell)&code_docol,   // BASE    [170, CFA:173]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&base,          
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 170), 0x52524505, 0x0200524F,             (Cell)&code_docol,   // ERROR   [177, CFA:180]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&error,         
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 177), 0x49555104, 0x02000054,             (Cell)&code_docol,   // QUIT    [184, CFA:187]
        (Cell)(sys_dict + 20),   // LIT
        0,                     
        (Cell)(sys_dict + 158),  // CELL
        (Cell)(sys_dict + 173),  // BASE
        (Cell)(sys_dict + 145),  // @
        (Cell)(sys_dict + 121),  // *
        (Cell)(sys_dict + 54),   // DUP
        (Cell)(sys_dict + 115),  // +
        (Cell)(sys_dict + 115),  // +
        (Cell)(sys_dict + 54),   // DUP
        (Cell)(sys_dict + 23),   // .
        (Cell)(sys_dict + 54),   // DUP
        (Cell)(sys_dict + 173),  // BASE
        (Cell)(sys_dict + 148),  // !
        (Cell)(sys_dict + 11),   // BRANCH
        -13,                   
        (Cell)(sys_dict + 50),   // SWAP
        (Cell)(sys_dict + 7),    // EXIT

};

const Cell* SYS_LATEST    = sys_dict + 184;
const Cell* SYS_QUIT_CFA  = sys_dict + 187;
const Cell* SYS_DOCOL_CFA = sys_dict + 3;
