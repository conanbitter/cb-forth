#ifndef USERDICT_H
#define USERDICT_H

extern uint8_t* here;

void init_userdict();

void code_newword(Cell* data);
void code_comma(Cell* data);
void code_ccomma(Cell* data);
void code_here(Cell* data);
void code_immediate(Cell* data);
void code_hidden(Cell* data);

#endif