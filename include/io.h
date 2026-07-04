#ifndef IO_H
#define IO_H

void code_query();
void code_key();

char get_key();
void get_word();
void print_word();

Cell str_to_int();
void print_int(Cell value);
void print_char(char value);
void print_str(const char* value);
void print_str_fixed(const char* value, Cell length);

extern Cell word_len;

#endif