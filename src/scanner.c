#include "header/scanner.h"

ArrToken tokens;

boolean is_variable(char current_character) {
    if ((current_character == '+') || (current_character == '-') || (current_character == '*') ||
        (current_character == '<') || (current_character == '>') || (current_character == '=')) {
        return false;
    } else {
        return true;
    }
}

boolean is_number(char current_character) {
    if ((current_character >= '0') && (current_character <= '9')) {
        return true;
    } else {
        return false;
    }
}

boolean is_number_string(char *currentString) {
    boolean found;
    int i;
    i = 0;
    found = false;
    while ((currentString[i] != '\0') && (!found)) {
        if (!is_number(currentString[i])) {
            found = true;
        } else {
            i++;
        }
    }
    if (found) {
        return false;
    } else {
        return true;
    }
}

boolean is_logic(char *current_character) {
    int num;
    num = strlen(current_character);
    if (num == 2) {
        if ((((current_character[0] == '<') || (current_character[0] == '>')) && (current_character[1] == '=')) ||
            ((current_character[0] == '<') && (current_character[1] == '>'))) {
            return true;
        } else {
            return false;
        }
    } else if (num == 1) {
        if ((current_character[0] == '<') || (current_character[0] == '>')) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void scanner(const char *filename) {
    char Temp[30];
    int i, j, row;
    start(filename);
    i = 0;
    row = 1;
    while (!EOP) {
        if (current_character == '(') {
            tokens.tab[i] = '(';
            tokens.row[i] = row;
            i++;
            advance();
        } else if (current_character == ')') {
            tokens.tab[i] = ')';
            tokens.row[i] = row;
            i++;
            advance();
        } else if (current_character == '\n') {
            row++;
            advance();
        } else if (current_character == 'b') {
            j = 0;
            while ((current_character != ' ') && (current_character != '(') && (current_character != ')') &&
                   (current_character != '\n') && (current_character != EOF)) {
                Temp[j] = current_character;
                advance();
                j++;
            }
            Temp[j] = '\0';
            if (strcmp(Temp, "begin") == 0) {
                tokens.tab[i] = 'b';
                tokens.row[i] = row;
                i++;
            } else {
                tokens.tab[i] = 'v';
                tokens.row[i] = row;
                i++;
            }
        } else if (current_character == 'e') {
            j = 0;
            while ((current_character != ' ') && (current_character != '(') && (current_character != ')') &&
                   (current_character != '\n') && (current_character != EOF)) {
                Temp[j] = current_character;
                advance();
                j++;
            }
            Temp[j] = '\0';
            if (strcmp(Temp, "end") == 0) {
                tokens.tab[i] = 'e';
                tokens.row[i] = row;
                i++;
            } else if (strcmp(Temp, "else") == 0) {
                tokens.tab[i] = 'l';
                tokens.row[i] = row;
                i++;
            } else {
                tokens.tab[i] = 'v';
                tokens.row[i] = row;
                i++;
            }
        } else if (current_character == 'i') {
            j = 0;
            while ((current_character != '(') && (current_character != ' ') && (current_character != ')') &&
                   (current_character != '\n') && (current_character != EOF)) {
                Temp[j] = current_character;
                advance();
                j++;
            }
            Temp[j] = '\0';
            if (strcmp(Temp, "if") == 0) {
                tokens.tab[i] = 'i';
                tokens.row[i] = row;
                i++;
            } else if (strcmp(Temp, "input") == 0) {
                tokens.tab[i] = 'n';
                tokens.row[i] = row;
                i++;
            } else {
                tokens.tab[i] = 'v';
                tokens.row[i] = row;
                i++;
            }
        } else if (current_character == 'd') {
            j = 0;
            while ((current_character != ' ') && (current_character != '(') && (current_character != ')') &&
                   (current_character != '\n') && (current_character != EOF)) {
                Temp[j] = current_character;
                advance();
                j++;
            }
            Temp[j] = '\0';
            if (strcmp(Temp, "do") == 0) {
                tokens.tab[i] = 'd';
                tokens.row[i] = row;
                i++;
            } else {
                tokens.tab[i] = 'v';
                tokens.row[i] = row;
                i++;
            }
        } else if (current_character == 'f') {
            j = 0;
            while ((current_character != ' ') && (current_character != '(') && (current_character != ')') &&
                   (current_character != '\n') && (current_character != EOF)) {
                Temp[j] = current_character;
                advance();
                j++;
            }
            Temp[j] = '\0';
            if (strcmp(Temp, "for") == 0) {
                tokens.tab[i] = 'f';
                tokens.row[i] = row;
                i++;
            } else {
                tokens.tab[i] = 'v';
                tokens.row[i] = row;
                i++;
            }
        } else if (current_character == 'o') {
            j = 0;
            while ((current_character != '(') && (current_character != ')') && (current_character != ' ') &&
                   (current_character != '\n') && (current_character != EOF)) {
                Temp[j] = current_character;
                advance();
                j++;
            }
            Temp[j] = '\0';
            if (strcmp(Temp, "output") == 0) {
                tokens.tab[i] = 'o';
                tokens.row[i] = row;
                i++;
            } else {
                tokens.tab[i] = 'v';
                tokens.row[i] = row;
                i++;
            }
        } else if ((current_character == 'w')) {
            j = 0;
            while ((current_character != '(') && (current_character != ')') && (current_character != ' ') &&
                   (current_character != '\n') && (current_character != EOF)) {
                Temp[j] = current_character;
                advance();
                j++;
            }
            Temp[j] = '\0';
            if (strcmp(Temp, "while") == 0) {
                tokens.tab[i] = 'w';
                tokens.row[i] = row;
                i++;
            } else {
                tokens.tab[i] = 'v';
                tokens.row[i] = row;
                i++;
            }
        } else if ((current_character == 't')) {
            j = 0;
            while ((current_character != '(') && (current_character != ')') && (current_character != ' ') &&
                   (current_character != '\n') && (current_character != EOF)) {
                Temp[j] = current_character;
                advance();
                j++;
            }
            Temp[j] = '\0';
            if (strcmp(Temp, "to") == 0) {
                tokens.tab[i] = 't';
                tokens.row[i] = row;
                i++;
            } else if (strcmp(Temp, "then") == 0) {
                tokens.tab[i] = 'h';
                tokens.row[i] = row;
                i++;
            } else {
                tokens.tab[i] = 'v';
                tokens.row[i] = row;
                i++;
            }
        } else if ((current_character == '\t') || (current_character == ' ')) {
            while (((current_character == '\t') || (current_character == ' ')) && (current_character != EOF)) {
                advance();
            }
        } else if (current_character == '{') {
            while ((current_character != '}') && (current_character != EOF)) {
                if (current_character == '\n') {
                    row++;
                }
                advance();
            }
            if (current_character == '}') {
                advance();
            }
        } else if (is_number(current_character)) {
            j = 0;
            while ((current_character != EOF) && (current_character != ' ') && (current_character != ')') &&
                   (current_character != '\n')) {
                Temp[j] = current_character;
                advance();
                j++;
            }
            Temp[j] = '\0';
            if (is_number_string(Temp)) {
                tokens.tab[i] = 'c';
                tokens.row[i] = row;
                i++;
            } else {
                tokens.tab[i] = 'z'; // unknown identifier
                tokens.row[i] = row;
                i++;
            }
        } else if ((current_character == '+') || (current_character == '-') || (current_character == '*')) {
            tokens.tab[i] = 'a';
            tokens.row[i] = row;
            advance();
            i++;
        } else if ((current_character == '<') || (current_character == '>')) {
            j = 0;
            while ((current_character == '<') || (current_character == '>') || (current_character == '=')) {
                Temp[j] = current_character;
                advance();
                j++;
            }
            Temp[j] = '\0';
            if (is_logic(Temp)) {
                tokens.tab[i] = 'x';
                tokens.row[i] = row;
                i++;
            } else {
                tokens.tab[i] = 'z'; //unknown var
                tokens.row[i] = row;
                i++;
            }
        } else if (current_character == '=') {
            advance();
            tokens.tab[i] = '=';
            tokens.row[i] = row;
            i++;
        } else {
            while ((!EOP) && (current_character != ' ') && (current_character != '\n') && (current_character != '(') &&
                   (current_character != ')') && (is_variable(current_character))) {
                advance();
            }
            tokens.tab[i] = 'v';
            tokens.row[i] = row;
            i++;
        }
    }
}

void initial_tokens() {
    int i;
    for (i = 0; i <= ELMAX - 1; i++) {
        tokens.tab[i] = '|';
        tokens.row[i] = 1;
    }
}
