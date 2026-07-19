#include "common.h"

static const Cell sys_dict[237] = {
    (Cell)NULL,             0x494E4924, 0x02000054,             (Cell)&code_init,    // INIT      [0, CFA:3]
    (Cell)(sys_dict + 0),   0x49584544, 0x02000054,             (Cell)&code_exit,    // EXIT      [4, CFA:7]
    (Cell)(sys_dict + 4),   0x41524246, 0x0248434E,             (Cell)&code_branch,  // BRANCH    [8, CFA:11]
    (Cell)(sys_dict + 8),   0x52423047, 0x48434E41, 0x03000000, (Cell)&code_zbranch, // 0BRANCH   [12, CFA:16]
    (Cell)(sys_dict + 12),  0x54494C43, 0x02000000,             (Cell)&code_lit,     // LIT       [17, CFA:20]
    (Cell)(sys_dict + 17),  0x52524526, 0x02545354,             (Cell)&code_errtst,  // ERRTST    [21, CFA:24]
    (Cell)(sys_dict + 21),  0x52415025, 0x02004553,             (Cell)&code_parse,   // PARSE     [25, CFA:28]
    (Cell)(sys_dict + 25),  0x57454E07, 0x44524F57, 0x03000000, (Cell)&code_newword, // NEWWORD   [29, CFA:33]
    (Cell)(sys_dict + 29),  0x01002C01,                         (Cell)&code_comma,   // ,         [34, CFA:36]
    (Cell)(sys_dict + 34),  0x012C4302,                         (Cell)&code_ccomma,  // C,        [37, CFA:39]
    (Cell)(sys_dict + 37),  0x01002E01,                         (Cell)&code_dot,     // .         [40, CFA:42]
    (Cell)(sys_dict + 40),  0x01532E02,                         (Cell)&code_pstack,  // .S        [43, CFA:45]
    (Cell)(sys_dict + 43),  0x45555105, 0x02005952,             (Cell)&code_query,   // QUERY     [46, CFA:49]
    (Cell)(sys_dict + 46),  0x524F5704, 0x02000044,             (Cell)&code_word,    // WORD      [50, CFA:53]
    (Cell)(sys_dict + 50),  0x59454B03, 0x02000000,             (Cell)&code_key,     // KEY       [54, CFA:57]
    (Cell)(sys_dict + 54),  0x494D4504, 0x02000054,             (Cell)&code_emit,    // EMIT      [58, CFA:61]
    (Cell)(sys_dict + 58),  0x4F524404, 0x02000050,             (Cell)&code_drop,    // DROP      [62, CFA:65]
    (Cell)(sys_dict + 62),  0x41575304, 0x02000050,             (Cell)&code_swap,    // SWAP      [66, CFA:69]
    (Cell)(sys_dict + 66),  0x50554403, 0x02000000,             (Cell)&code_dup,     // DUP       [70, CFA:73]
    (Cell)(sys_dict + 70),  0x45564F04, 0x02000052,             (Cell)&code_over,    // OVER      [74, CFA:77]
    (Cell)(sys_dict + 74),  0x544F5203, 0x02000000,             (Cell)&code_rot,     // ROT       [78, CFA:81]
    (Cell)(sys_dict + 78),  0x4F522D04, 0x02000054,             (Cell)&code_nrot,    // -ROT      [82, CFA:85]
    (Cell)(sys_dict + 82),  0x52443205, 0x0200504F,             (Cell)&code_drop2,   // 2DROP     [86, CFA:89]
    (Cell)(sys_dict + 86),  0x57533205, 0x02005041,             (Cell)&code_swap2,   // 2SWAP     [90, CFA:93]
    (Cell)(sys_dict + 90),  0x55443204, 0x02000050,             (Cell)&code_dup2,    // 2DUP      [94, CFA:97]
    (Cell)(sys_dict + 94),  0x55443F04, 0x02000050,             (Cell)&code_qdup,    // ?DUP      [98, CFA:101]
    (Cell)(sys_dict + 98),  0x012B3102,                         (Cell)&code_inc,     // 1+        [102, CFA:104]
    (Cell)(sys_dict + 102), 0x012D3102,                         (Cell)&code_dec,     // 1-        [105, CFA:107]
    (Cell)(sys_dict + 105), 0x012B3202,                         (Cell)&code_inc2,    // 2+        [108, CFA:110]
    (Cell)(sys_dict + 108), 0x012D3202,                         (Cell)&code_dec2,    // 2-        [111, CFA:113]
    (Cell)(sys_dict + 111), 0x012A3202,                         (Cell)&code_mul2,    // 2*        [114, CFA:116]
    (Cell)(sys_dict + 114), 0x012F3202,                         (Cell)&code_div2,    // 2/        [117, CFA:119]
    (Cell)(sys_dict + 117), 0x012B3402,                         (Cell)&code_inc4,    // 4+        [120, CFA:122]
    (Cell)(sys_dict + 120), 0x012D3402,                         (Cell)&code_dec4,    // 4-        [123, CFA:125]
    (Cell)(sys_dict + 123), 0x012A3402,                         (Cell)&code_mul4,    // 4*        [126, CFA:128]
    (Cell)(sys_dict + 126), 0x012F3402,                         (Cell)&code_div4,    // 4/        [129, CFA:131]
    (Cell)(sys_dict + 129), 0x01002B01,                         (Cell)&code_add,     // +         [132, CFA:134]
    (Cell)(sys_dict + 132), 0x01002D01,                         (Cell)&code_sub,     // -         [135, CFA:137]
    (Cell)(sys_dict + 135), 0x01002A01,                         (Cell)&code_mul,     // *         [138, CFA:140]
    (Cell)(sys_dict + 138), 0x01002F01,                         (Cell)&code_div,     // /         [141, CFA:143]
    (Cell)(sys_dict + 141), 0x01003D01,                         (Cell)&code_eq,      // =         [144, CFA:146]
    (Cell)(sys_dict + 144), 0x013E3C02,                         (Cell)&code_neq,     // <>        [147, CFA:149]
    (Cell)(sys_dict + 147), 0x01003C01,                         (Cell)&code_less,    // <         [150, CFA:152]
    (Cell)(sys_dict + 150), 0x01003E01,                         (Cell)&code_greater, // >         [153, CFA:155]
    (Cell)(sys_dict + 153), 0x01524302,                         (Cell)&code_cr,      // CR        [156, CFA:158]
    (Cell)(sys_dict + 156), 0x014C4202,                         (Cell)&code_bl,      // BL        [159, CFA:161]
    (Cell)(sys_dict + 159), 0x01004001,                         (Cell)&code_fetch,   // @         [162, CFA:164]
    (Cell)(sys_dict + 162), 0x01002101,                         (Cell)&code_store,   // !         [165, CFA:167]
    (Cell)(sys_dict + 165), 0x01404302,                         (Cell)&code_cfetch,  // C@        [168, CFA:170]
    (Cell)(sys_dict + 168), 0x01214302,                         (Cell)&code_cstore,  // C!        [171, CFA:173]
    (Cell)(sys_dict + 171), 0x4C454305, 0x0200534C,             (Cell)&code_cells,   // CELLS     [174, CFA:177]

    (Cell)(sys_dict + 174), 0x434F4405, 0x02004C4F,             (Cell)&code_docol,   // DOCOL     [178, CFA:181]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&code_docol,    
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 178), 0x52455607, 0x4E4F4953, 0x03000000, (Cell)&code_docol,   // VERSION   [185, CFA:189]
        (Cell)(sys_dict + 20),  // LIT
        VERSION,              
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 185), 0x53414204, 0x02000045,             (Cell)&code_docol,   // BASE      [193, CFA:196]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&base,          
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 193), 0x52524505, 0x0200524F,             (Cell)&code_docol,   // ERROR     [200, CFA:203]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&error,         
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 200), 0x41545305, 0x02004554,             (Cell)&code_docol,   // STATE     [207, CFA:210]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&state,         
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 207), 0x544E4909, 0x52505245, 0x03005445, (Cell)&code_docol,   // INTERPRET [214, CFA:218]
        (Cell)(sys_dict + 28),   // PARSE
        (Cell)(sys_dict + 203),  // ERROR
        (Cell)(sys_dict + 164),  // @
        (Cell)(sys_dict + 101),  // ?DUP
        (Cell)(sys_dict + 16),   // 0BRANCH
        -5,                    
        (Cell)(sys_dict + 24),   // ERRTST
        (Cell)(sys_dict + 7),    // EXIT

    (Cell)(sys_dict + 214), 0x49555104, 0x02000054,             (Cell)&code_docol,   // QUIT      [227, CFA:230]
        (Cell)(sys_dict + 3),    // INIT
        (Cell)(sys_dict + 49),   // QUERY
        (Cell)(sys_dict + 218),  // INTERPRET
        (Cell)(sys_dict + 158),  // CR
        (Cell)(sys_dict + 11),   // BRANCH
        -4,                    

};

const Cell* SYS_LATEST   = sys_dict + 227;
const Cell* SYS_QUIT_CFA = sys_dict + 230;
const Cell* SYS_LIT_CFA  = sys_dict + 20;
