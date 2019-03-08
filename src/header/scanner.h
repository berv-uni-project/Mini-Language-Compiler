#ifndef scanner_h
#define scanner_h

#include "mesin_karakter.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ELMAX 700

typedef char Token;
typedef struct {
    Token tab[ELMAX];
    int row[ELMAX];
} ArrToken;

extern ArrToken tokens;

/* Pengecekan Khusus */
boolean is_logic(char *current_character);

boolean is_number(char current_character);

boolean is_number_string(char *currentString);

boolean is_variable(char current_character);

/* Scanner Utama */
void scanner(const char *filename);

void initial_tokens();

#endif
