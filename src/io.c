#include <stdio.h>
#include <stdbool.h>
#include "common.h"

#define INPUT_BUFFER_SIZE 256
#define INPUT_WORD_SIZE 32

static char input_buffer[INPUT_BUFFER_SIZE];
char word_buffer[INPUT_WORD_SIZE];
Cell word_len = 0;
char* caret;

void code_query() {
    while (1) {
        fflush(stdout);

        if (fgets(input_buffer, INPUT_BUFFER_SIZE, stdin) == NULL) {
            continue;
        }

        if (input_buffer[0] == '\n') {
            continue;
        }

        if (input_buffer[strlen(input_buffer) - 1] != '\n') {
            int ch;
            while (((ch = getchar()) != '\n') && (ch != EOF)) {
            }
            input_buffer[INPUT_BUFFER_SIZE - 1] = '\0';
            return;
        }

        input_buffer[strlen(input_buffer) - 1] = '\0';
        caret = input_buffer;
        return;
    }
}

char get_key() {
    if (*caret == '\0') return '\0';
    return *(caret++);
}

void code_key() {
    spush((Cell)get_key());
}

void get_word() {
    word_len = 0;
    char letter = get_key();
    if (letter == '\\') return;
    while (letter == ' ' || letter == '\t') letter = get_key();
    while (letter != '\0' && letter != ' ' && letter != '\t')
    {
        if (word_len < (INPUT_WORD_SIZE - 1)) {
            if (letter >= 'a' && letter <= 'z') {
                word_buffer[word_len] = letter + ('A' - 'a');
            } else {
                word_buffer[word_len] = letter;
            }
            word_len++;
        }
        letter = get_key();
    }
    word_buffer[word_len] = '\0';
}

void code_word() {
    get_word();
    spush((Cell)word_buffer);
    spush(word_len);
}

void print_word() {
    printf(">%s<\n", word_buffer);
}

Cell get_digit(char input) {
    Cell result = -1;
    if (input >= '0' && input <= '1') {
        result = input - '0';
    } else if (input >= 'A' && input <= 'Z') {
        result = input - 'A' + 10;
    } else if (input != '\0') {
        error = 1;
    }
    if (result < base) {
        return result;
    } else {
        error = 1;
        return -1;
    }
}

Cell str_to_int() {
    error = 0;
    bool negative = false;
    char* cur = word_buffer;

    if (*cur == '-') {
        negative = true;
        cur++;
    }

    Cell result = 0;
    Cell digit;
    while ((digit = get_digit(*cur)) != -1) {
        result = result * base + digit;
        cur++;
    }

    return negative ? -result : result;
}

void print_int(Cell value) {
    static const char letters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static char buffer[CELL_WIDTH * 8 + 1];

    int index = 0;

    if (value == 0) {
        putchar('0');
        return;
    }

    while (value > 0) {
        buffer[index++] = letters[value % base];
        value /= base;
    }

    for (int i = index - 1; i >= 0; i--) {
        putchar(buffer[i]);
    }
}

void print_char(char value) {
    putchar(value);
}

void print_str(const char* value) {
    printf(value);
}

void print_str_fixed(const char* value, Cell length) {
    printf("%.*s", length, value);
}