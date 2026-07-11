#include "common.h"

static const Cell sys_dict[222] = {
    (Cell)NULL,             0x494E4924, 0x22000054,             (Cell)&code_init,    // INIT      [0, CFA:3]
    (Cell)(sys_dict + 0),   0x49584544, 0x42000054,             (Cell)&code_exit,    // EXIT      [4, CFA:7]
    (Cell)(sys_dict + 4),   0x41524246, 0x4248434E,             (Cell)&code_branch,  // BRANCH    [8, CFA:11]
    (Cell)(sys_dict + 8),   0x52423047, 0x48434E41, 0x43000000, (Cell)&code_zbranch, // 0BRANCH   [12, CFA:16]
    (Cell)(sys_dict + 12),  0x54494C43, 0x42000000,             (Cell)&code_lit,     // LIT       [17, CFA:20]
    (Cell)(sys_dict + 17),  0x52524526, 0x22545354,             (Cell)&code_errtst,  // ERRTST    [21, CFA:24]
    (Cell)(sys_dict + 21),  0x52415025, 0x22004553,             (Cell)&code_parse,   // PARSE     [25, CFA:28]
    (Cell)(sys_dict + 25),  0x01002E01,                         (Cell)&code_dot,     // .         [29, CFA:31]
    (Cell)(sys_dict + 29),  0x01532E02,                         (Cell)&code_pstack,  // .S        [32, CFA:34]
    (Cell)(sys_dict + 32),  0x45555105, 0x02005952,             (Cell)&code_query,   // QUERY     [35, CFA:38]
    (Cell)(sys_dict + 35),  0x524F5704, 0x02000044,             (Cell)&code_word,    // WORD      [39, CFA:42]
    (Cell)(sys_dict + 39),  0x59454B03, 0x02000000,             (Cell)&code_key,     // KEY       [43, CFA:46]
    (Cell)(sys_dict + 43),  0x494D4504, 0x02000054,             (Cell)&code_emit,    // EMIT      [47, CFA:50]
    (Cell)(sys_dict + 47),  0x4F524404, 0x02000050,             (Cell)&code_drop,    // DROP      [51, CFA:54]
    (Cell)(sys_dict + 51),  0x41575304, 0x02000050,             (Cell)&code_swap,    // SWAP      [55, CFA:58]
    (Cell)(sys_dict + 55),  0x50554403, 0x02000000,             (Cell)&code_dup,     // DUP       [59, CFA:62]
    (Cell)(sys_dict + 59),  0x45564F04, 0x02000052,             (Cell)&code_over,    // OVER      [63, CFA:66]
    (Cell)(sys_dict + 63),  0x544F5203, 0x02000000,             (Cell)&code_rot,     // ROT       [67, CFA:70]
    (Cell)(sys_dict + 67),  0x4F522D04, 0x02000054,             (Cell)&code_nrot,    // -ROT      [71, CFA:74]
    (Cell)(sys_dict + 71),  0x52443205, 0x0200504F,             (Cell)&code_drop2,   // 2DROP     [75, CFA:78]
    (Cell)(sys_dict + 75),  0x57533205, 0x02005041,             (Cell)&code_swap2,   // 2SWAP     [79, CFA:82]
    (Cell)(sys_dict + 79),  0x55443204, 0x02000050,             (Cell)&code_dup2,    // 2DUP      [83, CFA:86]
    (Cell)(sys_dict + 83),  0x55443F04, 0x02000050,             (Cell)&code_qdup,    // ?DUP      [87, CFA:90]
    (Cell)(sys_dict + 87),  0x012B3102,                         (Cell)&code_inc,     // 1+        [91, CFA:93]
    (Cell)(sys_dict + 91),  0x012D3102,                         (Cell)&code_dec,     // 1-        [94, CFA:96]
    (Cell)(sys_dict + 94),  0x012B3202,                         (Cell)&code_inc2,    // 2+        [97, CFA:99]
    (Cell)(sys_dict + 97),  0x012D3202,                         (Cell)&code_dec2,    // 2-        [100, CFA:102]
    (Cell)(sys_dict + 100), 0x012A3202,                         (Cell)&code_mul2,    // 2*        [103, CFA:105]
    (Cell)(sys_dict + 103), 0x012F3202,                         (Cell)&code_div2,    // 2/        [106, CFA:108]
    (Cell)(sys_dict + 106), 0x012B3402,                         (Cell)&code_inc4,    // 4+        [109, CFA:111]
    (Cell)(sys_dict + 109), 0x012D3402,                         (Cell)&code_dec4,    // 4-        [112, CFA:114]
    (Cell)(sys_dict + 112), 0x012A3402,                         (Cell)&code_mul4,    // 4*        [115, CFA:117]
    (Cell)(sys_dict + 115), 0x012F3402,                         (Cell)&code_div4,    // 4/        [118, CFA:120]
    (Cell)(sys_dict + 118), 0x01002B01,                         (Cell)&code_add,     // +         [121, CFA:123]
    (Cell)(sys_dict + 121), 0x01002D01,                         (Cell)&code_sub,     // -         [124, CFA:126]
    (Cell)(sys_dict + 124), 0x01002A01,                         (Cell)&code_mul,     // *         [127, CFA:129]
    (Cell)(sys_dict + 127), 0x01002F01,                         (Cell)&code_div,     // /         [130, CFA:132]
    (Cell)(sys_dict + 130), 0x01003D01,                         (Cell)&code_eq,      // =         [133, CFA:135]
    (Cell)(sys_dict + 133), 0x013E3C02,                         (Cell)&code_neq,     // <>        [136, CFA:138]
    (Cell)(sys_dict + 136), 0x01003C01,                         (Cell)&code_less,    // <         [139, CFA:141]
    (Cell)(sys_dict + 139), 0x01003E01,                         (Cell)&code_greater, // >         [142, CFA:144]
    (Cell)(sys_dict + 142), 0x01524302,                         (Cell)&code_cr,      // CR        [145, CFA:147]
    (Cell)(sys_dict + 145), 0x014C4202,                         (Cell)&code_bl,      // BL        [148, CFA:150]
    (Cell)(sys_dict + 148), 0x01004001,                         (Cell)&code_fetch,   // @         [151, CFA:153]
    (Cell)(sys_dict + 151), 0x01002101,                         (Cell)&code_store,   // !         [154, CFA:156]
    (Cell)(sys_dict + 154), 0x01404302,                         (Cell)&code_cfetch,  // C@        [157, CFA:159]
    (Cell)(sys_dict + 157), 0x01214302,                         (Cell)&code_cstore,  // C!        [160, CFA:162]

    (Cell)(sys_dict + 160), 0x434F4405, 0x02004C4F,             (Cell)&code_docol,   // DOCOL     [163, CFA:166]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&code_docol,    
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 163), 0x52455607, 0x4E4F4953, 0x03000000, (Cell)&code_docol,   // VERSION   [170, CFA:174]
        (Cell)(sys_dict + 20),  // LIT
        VERSION,              
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 170), 0x53414204, 0x02000045,             (Cell)&code_docol,   // BASE      [178, CFA:181]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&base,          
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 178), 0x52524505, 0x0200524F,             (Cell)&code_docol,   // ERROR     [185, CFA:188]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&error,         
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 185), 0x41545305, 0x02004554,             (Cell)&code_docol,   // STATE     [192, CFA:195]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&state,         
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 192), 0x544E4909, 0x52505245, 0x03005445, (Cell)&code_docol,   // INTERPRET [199, CFA:203]
        (Cell)(sys_dict + 28),   // PARSE
        (Cell)(sys_dict + 188),  // ERROR
        (Cell)(sys_dict + 153),  // @
        (Cell)(sys_dict + 90),   // ?DUP
        (Cell)(sys_dict + 16),   // 0BRANCH
        -5,                    
        (Cell)(sys_dict + 24),   // ERRTST
        (Cell)(sys_dict + 7),    // EXIT

    (Cell)(sys_dict + 199), 0x49555104, 0x02000054,             (Cell)&code_docol,   // QUIT      [212, CFA:215]
        (Cell)(sys_dict + 3),    // INIT
        (Cell)(sys_dict + 38),   // QUERY
        (Cell)(sys_dict + 203),  // INTERPRET
        (Cell)(sys_dict + 147),  // CR
        (Cell)(sys_dict + 11),   // BRANCH
        -4,                    

};

const Cell* SYS_LATEST   = sys_dict + 212;
const Cell* SYS_QUIT_CFA = sys_dict + 215;
const Cell* SYS_LIT_CFA  = sys_dict + 20;
