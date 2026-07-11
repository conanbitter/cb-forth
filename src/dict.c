#include "common.h"

static const Cell sys_dict[210] = {
    (Cell)NULL,             0x434F4425, 0x22004C4F,             (Cell)&code_docol,   // DOCOL   [0, CFA:3]
    (Cell)(sys_dict + 0),   0x49584544, 0x42000054,             (Cell)&code_exit,    // EXIT    [4, CFA:7]
    (Cell)(sys_dict + 4),   0x41524246, 0x4248434E,             (Cell)&code_branch,  // BRANCH  [8, CFA:11]
    (Cell)(sys_dict + 8),   0x52423047, 0x48434E41, 0x43000000, (Cell)&code_zbranch, // 0BRANCH [12, CFA:16]
    (Cell)(sys_dict + 12),  0x54494C43, 0x42000000,             (Cell)&code_lit,     // LIT     [17, CFA:20]
    (Cell)(sys_dict + 17),  0x52524506, 0x02545354,             (Cell)&code_errtst,  // ERRTST  [21, CFA:24]
    (Cell)(sys_dict + 21),  0x01002E01,                         (Cell)&code_dot,     // .       [25, CFA:27]
    (Cell)(sys_dict + 25),  0x01532E02,                         (Cell)&code_pstack,  // .S      [28, CFA:30]
    (Cell)(sys_dict + 28),  0x45555105, 0x02005952,             (Cell)&code_query,   // QUERY   [31, CFA:34]
    (Cell)(sys_dict + 31),  0x524F5704, 0x02000044,             (Cell)&code_word,    // WORD    [35, CFA:38]
    (Cell)(sys_dict + 35),  0x59454B03, 0x02000000,             (Cell)&code_key,     // KEY     [39, CFA:42]
    (Cell)(sys_dict + 39),  0x494D4504, 0x02000054,             (Cell)&code_emit,    // EMIT    [43, CFA:46]
    (Cell)(sys_dict + 43),  0x4F524404, 0x02000050,             (Cell)&code_drop,    // DROP    [47, CFA:50]
    (Cell)(sys_dict + 47),  0x41575304, 0x02000050,             (Cell)&code_swap,    // SWAP    [51, CFA:54]
    (Cell)(sys_dict + 51),  0x50554403, 0x02000000,             (Cell)&code_dup,     // DUP     [55, CFA:58]
    (Cell)(sys_dict + 55),  0x45564F04, 0x02000052,             (Cell)&code_over,    // OVER    [59, CFA:62]
    (Cell)(sys_dict + 59),  0x544F5203, 0x02000000,             (Cell)&code_rot,     // ROT     [63, CFA:66]
    (Cell)(sys_dict + 63),  0x4F522D04, 0x02000054,             (Cell)&code_nrot,    // -ROT    [67, CFA:70]
    (Cell)(sys_dict + 67),  0x52443205, 0x0200504F,             (Cell)&code_drop2,   // 2DROP   [71, CFA:74]
    (Cell)(sys_dict + 71),  0x57533205, 0x02005041,             (Cell)&code_swap2,   // 2SWAP   [75, CFA:78]
    (Cell)(sys_dict + 75),  0x55443204, 0x02000050,             (Cell)&code_dup2,    // 2DUP    [79, CFA:82]
    (Cell)(sys_dict + 79),  0x55443F04, 0x02000050,             (Cell)&code_qdup,    // ?DUP    [83, CFA:86]
    (Cell)(sys_dict + 83),  0x012B3102,                         (Cell)&code_inc,     // 1+      [87, CFA:89]
    (Cell)(sys_dict + 87),  0x012D3102,                         (Cell)&code_dec,     // 1-      [90, CFA:92]
    (Cell)(sys_dict + 90),  0x012B3202,                         (Cell)&code_inc2,    // 2+      [93, CFA:95]
    (Cell)(sys_dict + 93),  0x012D3202,                         (Cell)&code_dec2,    // 2-      [96, CFA:98]
    (Cell)(sys_dict + 96),  0x012A3202,                         (Cell)&code_mul2,    // 2*      [99, CFA:101]
    (Cell)(sys_dict + 99),  0x012F3202,                         (Cell)&code_div2,    // 2/      [102, CFA:104]
    (Cell)(sys_dict + 102), 0x012B3402,                         (Cell)&code_inc4,    // 4+      [105, CFA:107]
    (Cell)(sys_dict + 105), 0x012D3402,                         (Cell)&code_dec4,    // 4-      [108, CFA:110]
    (Cell)(sys_dict + 108), 0x012A3402,                         (Cell)&code_mul4,    // 4*      [111, CFA:113]
    (Cell)(sys_dict + 111), 0x012F3402,                         (Cell)&code_div4,    // 4/      [114, CFA:116]
    (Cell)(sys_dict + 114), 0x01002B01,                         (Cell)&code_add,     // +       [117, CFA:119]
    (Cell)(sys_dict + 117), 0x01002D01,                         (Cell)&code_sub,     // -       [120, CFA:122]
    (Cell)(sys_dict + 120), 0x01002A01,                         (Cell)&code_mul,     // *       [123, CFA:125]
    (Cell)(sys_dict + 123), 0x01002F01,                         (Cell)&code_div,     // /       [126, CFA:128]
    (Cell)(sys_dict + 126), 0x01003D01,                         (Cell)&code_eq,      // =       [129, CFA:131]
    (Cell)(sys_dict + 129), 0x013E3C02,                         (Cell)&code_neq,     // <>      [132, CFA:134]
    (Cell)(sys_dict + 132), 0x01003C01,                         (Cell)&code_less,    // <       [135, CFA:137]
    (Cell)(sys_dict + 135), 0x01003E01,                         (Cell)&code_greater, // >       [138, CFA:140]
    (Cell)(sys_dict + 138), 0x01524302,                         (Cell)&code_cr,      // CR      [141, CFA:143]
    (Cell)(sys_dict + 141), 0x014C4202,                         (Cell)&code_bl,      // BL      [144, CFA:146]
    (Cell)(sys_dict + 144), 0x01004001,                         (Cell)&code_fetch,   // @       [147, CFA:149]
    (Cell)(sys_dict + 147), 0x01002101,                         (Cell)&code_store,   // !       [150, CFA:152]
    (Cell)(sys_dict + 150), 0x01404302,                         (Cell)&code_cfetch,  // C@      [153, CFA:155]
    (Cell)(sys_dict + 153), 0x01214302,                         (Cell)&code_cstore,  // C!      [156, CFA:158]

    (Cell)(sys_dict + 156), 0x4C454304, 0x0200004C,             (Cell)&code_docol,   // CELL    [159, CFA:162]
        (Cell)(sys_dict + 20),  // LIT
        CELL_WIDTH,           
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 159), 0x52455607, 0x4E4F4953, 0x03000000, (Cell)&code_docol,   // VERSION [166, CFA:170]
        (Cell)(sys_dict + 20),  // LIT
        VERSION,              
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 166), 0x53414204, 0x02000045,             (Cell)&code_docol,   // BASE    [174, CFA:177]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&base,          
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 174), 0x52524505, 0x0200524F,             (Cell)&code_docol,   // ERROR   [181, CFA:184]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&error,         
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 181), 0x49555104, 0x02000054,             (Cell)&code_docol,   // QUIT    [188, CFA:191]
        (Cell)(sys_dict + 20),   // LIT
        0,                     
        (Cell)(sys_dict + 162),  // CELL
        (Cell)(sys_dict + 177),  // BASE
        (Cell)(sys_dict + 149),  // @
        (Cell)(sys_dict + 125),  // *
        (Cell)(sys_dict + 58),   // DUP
        (Cell)(sys_dict + 119),  // +
        (Cell)(sys_dict + 119),  // +
        (Cell)(sys_dict + 58),   // DUP
        (Cell)(sys_dict + 27),   // .
        (Cell)(sys_dict + 58),   // DUP
        (Cell)(sys_dict + 177),  // BASE
        (Cell)(sys_dict + 152),  // !
        (Cell)(sys_dict + 11),   // BRANCH
        -13,                   
        (Cell)(sys_dict + 54),   // SWAP
        (Cell)(sys_dict + 7),    // EXIT

};

const Cell* SYS_LATEST    = sys_dict + 188;
const Cell* SYS_QUIT_CFA  = sys_dict + 191;
const Cell* SYS_DOCOL_CFA = sys_dict + 3;
