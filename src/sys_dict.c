#include "common.h"

static const Cell sys_dict[271] = {
    (Cell)NULL,             0x494E4924, 0x02000054,             (Cell)&code_init,      // INIT      [0, CFA:3]
    (Cell)(sys_dict + 0),   0x49584544, 0x02000054,             (Cell)&code_exit,      // EXIT      [4, CFA:7]
    (Cell)(sys_dict + 4),   0x41524246, 0x0248434E,             (Cell)&code_branch,    // BRANCH    [8, CFA:11]
    (Cell)(sys_dict + 8),   0x52423047, 0x48434E41, 0x03000000, (Cell)&code_zbranch,   // 0BRANCH   [12, CFA:16]
    (Cell)(sys_dict + 12),  0x54494C43, 0x02000000,             (Cell)&code_lit,       // LIT       [17, CFA:20]
    (Cell)(sys_dict + 17),  0x52524526, 0x02545354,             (Cell)&code_errtst,    // ERRTST    [21, CFA:24]
    (Cell)(sys_dict + 21),  0x52415025, 0x02004553,             (Cell)&code_parse,     // PARSE     [25, CFA:28]
    (Cell)(sys_dict + 25),  0x57454E07, 0x44524F57, 0x03000000, (Cell)&code_newword,   // NEWWORD   [29, CFA:33]
    (Cell)(sys_dict + 29),  0x01002C01,                         (Cell)&code_comma,     // ,         [34, CFA:36]
    (Cell)(sys_dict + 34),  0x012C4302,                         (Cell)&code_ccomma,    // C,        [37, CFA:39]
    (Cell)(sys_dict + 37),  0x01005B01,                         (Cell)&code_lbrac,     // [         [40, CFA:42]
    (Cell)(sys_dict + 40),  0x01005D01,                         (Cell)&code_rbrac,     // ]         [43, CFA:45]
    (Cell)(sys_dict + 43),  0x4D4D4909, 0x41494445, 0x03004554, (Cell)&code_immediate, // IMMEDIATE [46, CFA:50]
    (Cell)(sys_dict + 46),  0x44494806, 0x024E4544,             (Cell)&code_hidden,    // HIDDEN    [51, CFA:54]
    (Cell)(sys_dict + 51),  0x01002E01,                         (Cell)&code_dot,       // .         [55, CFA:57]
    (Cell)(sys_dict + 55),  0x01532E02,                         (Cell)&code_pstack,    // .S        [58, CFA:60]
    (Cell)(sys_dict + 58),  0x45555105, 0x02005952,             (Cell)&code_query,     // QUERY     [61, CFA:64]
    (Cell)(sys_dict + 61),  0x524F5704, 0x02000044,             (Cell)&code_word,      // WORD      [65, CFA:68]
    (Cell)(sys_dict + 65),  0x59454B03, 0x02000000,             (Cell)&code_key,       // KEY       [69, CFA:72]
    (Cell)(sys_dict + 69),  0x494D4504, 0x02000054,             (Cell)&code_emit,      // EMIT      [73, CFA:76]
    (Cell)(sys_dict + 73),  0x4F524404, 0x02000050,             (Cell)&code_drop,      // DROP      [77, CFA:80]
    (Cell)(sys_dict + 77),  0x41575304, 0x02000050,             (Cell)&code_swap,      // SWAP      [81, CFA:84]
    (Cell)(sys_dict + 81),  0x50554403, 0x02000000,             (Cell)&code_dup,       // DUP       [85, CFA:88]
    (Cell)(sys_dict + 85),  0x45564F04, 0x02000052,             (Cell)&code_over,      // OVER      [89, CFA:92]
    (Cell)(sys_dict + 89),  0x544F5203, 0x02000000,             (Cell)&code_rot,       // ROT       [93, CFA:96]
    (Cell)(sys_dict + 93),  0x4F522D04, 0x02000054,             (Cell)&code_nrot,      // -ROT      [97, CFA:100]
    (Cell)(sys_dict + 97),  0x52443205, 0x0200504F,             (Cell)&code_drop2,     // 2DROP     [101, CFA:104]
    (Cell)(sys_dict + 101), 0x57533205, 0x02005041,             (Cell)&code_swap2,     // 2SWAP     [105, CFA:108]
    (Cell)(sys_dict + 105), 0x55443204, 0x02000050,             (Cell)&code_dup2,      // 2DUP      [109, CFA:112]
    (Cell)(sys_dict + 109), 0x55443F04, 0x02000050,             (Cell)&code_qdup,      // ?DUP      [113, CFA:116]
    (Cell)(sys_dict + 113), 0x012B3102,                         (Cell)&code_inc,       // 1+        [117, CFA:119]
    (Cell)(sys_dict + 117), 0x012D3102,                         (Cell)&code_dec,       // 1-        [120, CFA:122]
    (Cell)(sys_dict + 120), 0x012B3202,                         (Cell)&code_inc2,      // 2+        [123, CFA:125]
    (Cell)(sys_dict + 123), 0x012D3202,                         (Cell)&code_dec2,      // 2-        [126, CFA:128]
    (Cell)(sys_dict + 126), 0x012A3202,                         (Cell)&code_mul2,      // 2*        [129, CFA:131]
    (Cell)(sys_dict + 129), 0x012F3202,                         (Cell)&code_div2,      // 2/        [132, CFA:134]
    (Cell)(sys_dict + 132), 0x012B3402,                         (Cell)&code_inc4,      // 4+        [135, CFA:137]
    (Cell)(sys_dict + 135), 0x012D3402,                         (Cell)&code_dec4,      // 4-        [138, CFA:140]
    (Cell)(sys_dict + 138), 0x012A3402,                         (Cell)&code_mul4,      // 4*        [141, CFA:143]
    (Cell)(sys_dict + 141), 0x012F3402,                         (Cell)&code_div4,      // 4/        [144, CFA:146]
    (Cell)(sys_dict + 144), 0x01002B01,                         (Cell)&code_add,       // +         [147, CFA:149]
    (Cell)(sys_dict + 147), 0x01002D01,                         (Cell)&code_sub,       // -         [150, CFA:152]
    (Cell)(sys_dict + 150), 0x01002A01,                         (Cell)&code_mul,       // *         [153, CFA:155]
    (Cell)(sys_dict + 153), 0x01002F01,                         (Cell)&code_div,       // /         [156, CFA:158]
    (Cell)(sys_dict + 156), 0x01003D01,                         (Cell)&code_eq,        // =         [159, CFA:161]
    (Cell)(sys_dict + 159), 0x013E3C02,                         (Cell)&code_neq,       // <>        [162, CFA:164]
    (Cell)(sys_dict + 162), 0x01003C01,                         (Cell)&code_less,      // <         [165, CFA:167]
    (Cell)(sys_dict + 165), 0x01003E01,                         (Cell)&code_greater,   // >         [168, CFA:170]
    (Cell)(sys_dict + 168), 0x01524302,                         (Cell)&code_cr,        // CR        [171, CFA:173]
    (Cell)(sys_dict + 171), 0x014C4202,                         (Cell)&code_bl,        // BL        [174, CFA:176]
    (Cell)(sys_dict + 174), 0x01004001,                         (Cell)&code_fetch,     // @         [177, CFA:179]
    (Cell)(sys_dict + 177), 0x01002101,                         (Cell)&code_store,     // !         [180, CFA:182]
    (Cell)(sys_dict + 180), 0x01404302,                         (Cell)&code_cfetch,    // C@        [183, CFA:185]
    (Cell)(sys_dict + 183), 0x01214302,                         (Cell)&code_cstore,    // C!        [186, CFA:188]
    (Cell)(sys_dict + 186), 0x4C454305, 0x0200534C,             (Cell)&code_cells,     // CELLS     [189, CFA:192]
    (Cell)(sys_dict + 189), 0x52454804, 0x02000045,             (Cell)&code_here,      // HERE      [193, CFA:196]

    (Cell)(sys_dict + 193), 0x434F4405, 0x02004C4F,             (Cell)&code_docol,     // DOCOL     [197, CFA:200]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&code_docol,    
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 197), 0x52455607, 0x4E4F4953, 0x03000000, (Cell)&code_docol,     // VERSION   [204, CFA:208]
        (Cell)(sys_dict + 20),  // LIT
        VERSION,              
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 204), 0x53414204, 0x02000045,             (Cell)&code_docol,     // BASE      [212, CFA:215]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&base,          
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 212), 0x52524505, 0x0200524F,             (Cell)&code_docol,     // ERROR     [219, CFA:222]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&error,         
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 219), 0x41545305, 0x02004554,             (Cell)&code_docol,     // STATE     [226, CFA:229]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&state,         
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 226), 0x54414C06, 0x02545345,             (Cell)&code_docol,     // LATEST    [233, CFA:236]
        (Cell)(sys_dict + 20),  // LIT
        (Cell)&latest,        
        (Cell)(sys_dict + 7),   // EXIT

    (Cell)(sys_dict + 233), 0x544E4909, 0x52505245, 0x03005445, (Cell)&code_docol,     // INTERPRET [240, CFA:244]
        (Cell)(sys_dict + 28),   // PARSE
        (Cell)(sys_dict + 222),  // ERROR
        (Cell)(sys_dict + 179),  // @
        (Cell)(sys_dict + 116),  // ?DUP
        (Cell)(sys_dict + 16),   // 0BRANCH
        -5,                    
        (Cell)(sys_dict + 24),   // ERRTST
        (Cell)(sys_dict + 7),    // EXIT

    (Cell)(sys_dict + 240), 0x49555104, 0x02000054,             (Cell)&code_docol,     // QUIT      [253, CFA:256]
        (Cell)(sys_dict + 3),    // INIT
        (Cell)(sys_dict + 64),   // QUERY
        (Cell)(sys_dict + 244),  // INTERPRET
        (Cell)(sys_dict + 173),  // CR
        (Cell)(sys_dict + 11),   // BRANCH
        -4,                    

    (Cell)(sys_dict + 253), 0x554F4406, 0x02454C42,             (Cell)&code_docol,     // DOUBLE    [263, CFA:266]
        (Cell)(sys_dict + 20),   // LIT
        2,                     
        (Cell)(sys_dict + 155),  // *
        (Cell)(sys_dict + 7),    // EXIT

};

const Cell* SYS_LATEST   = sys_dict + 263;
const Cell* SYS_QUIT_CFA = sys_dict + 256;
const Cell* SYS_LIT_CFA  = sys_dict + 20;
