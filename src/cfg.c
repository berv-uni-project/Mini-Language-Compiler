/*
	Jadi yang dibutuhkan scannernya adalah mengubah input :

	begin -> b
	end -> e
	if -> i
	then -> h
	else -> l
	do -> d
	while -> w
	to -> t
	operator logika (<, >, <>, <=, >=) -> x
	operator aritmatika (+, -, *) -> a
	sama dengan (=) -> = (sama dengan juga)
	input -> n
	output -> o
	variabel -> v
	constanta -> c
	kurung buka ( -> ( (tetap)
	kurung tutup ) -> ) (tetap)


	Jangan lupa tambahkan kesalahan ada pada line berapa..
	ini tidak tahu ada di line berapa sekarang,
	kecuali jika NEWLINE diubah menjadi TERMINAL juga, misalkan N

	KOMENTAR saat scan di IGNORE saja, ini tidak dapat memproses komentar

*/

#include "header/stack.h"
#include "header/scanner.h"

/* Kamus */
ArrToken tokens;

Stack stack;
char dictionary[30][12];
char currentToken;
boolean success;

void input_matrix_stack() {
    int i, j;

    for (i = 0; i <= 25; i++) {
        for (j = 0; j <= 11; j++) {
            dictionary[i][j] = '|';
        }
    }

    dictionary[1][1] = 'e';
    dictionary[1][2] = 'B';
    dictionary[1][3] = 'b';
    dictionary[2][1] = 'e';
    dictionary[2][2] = 'B';
    dictionary[3][1] = 'I';
    dictionary[4][1] = 'D';
    dictionary[5][1] = 'F';
    dictionary[6][1] = 'M';
    dictionary[7][1] = 'K';
    dictionary[8][1] = 'H';
    dictionary[8][2] = 'E';
    dictionary[8][3] = 'v';
    dictionary[9][1] = 'S';
    dictionary[9][2] = 'h';
    dictionary[9][3] = 'P';
    dictionary[9][4] = 'i';
    dictionary[10][1] = 'S';
    dictionary[10][2] = 'l';
    dictionary[10][1] = 'B';
    dictionary[11][2] = 'P';
    dictionary[11][3] = 'w';
    dictionary[11][4] = '~';
    dictionary[11][5] = 'B';
    dictionary[11][6] = 'd';
    dictionary[12][1] = 'S';
    dictionary[12][2] = 'd';
    dictionary[12][3] = ')';
    dictionary[12][4] = 'c';
    dictionary[12][5] = 't';
    dictionary[12][6] = 'c';
    dictionary[12][7] = 'E';
    dictionary[12][8] = 'v';
    dictionary[12][9] = '(';
    dictionary[12][10] = 'f';
    dictionary[13][1] = ')';
    dictionary[13][2] = '_';
    dictionary[13][3] = 'L';
    dictionary[13][4] = '_';
    dictionary[13][5] = '(';
    dictionary[14][1] = 'c';
    dictionary[15][1] = 'v';
    dictionary[16][1] = 'x';
    dictionary[17][1] = 'E';
    dictionary[18][1] = '_';
    dictionary[18][2] = 'a';
    dictionary[18][3] = '_';
    dictionary[19][1] = ')';
    dictionary[19][2] = 'v';
    dictionary[19][3] = '(';
    dictionary[19][4] = 'n';
    dictionary[20][1] = ')';
    dictionary[20][2] = 'v';
    dictionary[20][3] = '(';
    dictionary[20][4] = 'o';
    dictionary[21][1] = ')';
    dictionary[21][2] = 'H';
    dictionary[21][3] = '(';
    dictionary[21][4] = 'o';
    dictionary[22][1] = '=';
}

void pushing(int i) {
    int j = 1;

    while (dictionary[i][j] != '|') {
        push(&stack, dictionary[i][j]);
        j = j + 1;
    }
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Call with cfg <filename>");
        return 0;
    }

    int i;
    input_matrix_stack();
    initial_tokens();

    scanner(argv[1]);
    printf("Scan Success\n");
    success = true;
    i = 0;
    //create_empty(&stack);
    push(&stack, 'Z');
    push(&stack, 'S');
    /*while (tokens.tab[i]!='|')
    {
        printf("%c\n",tokens.tab[i]);
        i++;
    }
    */
    while ((tokens.tab[i] != '|') && (success == true)) {
        printf("%c\n", tokens.tab[i]);
        // printf("%c\n", info_top(stack));
        if (info_top(stack) == 'S') {
            pop(&stack, &currentToken);
            if (tokens.tab[i + 1] == 'e') {
                pushing(2);
            } else {
                pushing(1);
            }
        } else if (info_top(stack) == 'B') {
            if (tokens.tab[i] == 'i') {
                pushing(3);
            } else if (tokens.tab[i] == 'd') {
                pop(&stack, &currentToken);
                pushing(4);
            } else if (tokens.tab[i] == 'f') {
                pushing(5);
            } else if (tokens.tab[i] == 'n') {
                pushing(6);
            } else if (tokens.tab[i] == 'o') {
                pushing(7);
            } else if (tokens.tab[i] == 'v') {
                pushing(8);
            } else if ((tokens.tab[i] == 'e') || (tokens.tab[i] == 'w')) {
                pop(&stack, &currentToken);
                if (tokens.tab[i] == 'w') {
                    pop(&stack, &currentToken);
                    push(&stack, 'B');
                    if (currentToken != '~') {
                        success = false;
                    }
                }
            }
        } else if (info_top(stack) == 'I') {
            pop(&stack, &currentToken);
            push(&stack, '+');
            pushing(9);
        } else if (info_top(stack) == '+') {
            pop(&stack, &currentToken);
            if (tokens.tab[i] == 'l') {
                pushing(10);
            }
        } else if (info_top(stack) == 'D') {
            pop(&stack, &currentToken);
            pushing(11);
        } else if (info_top(stack) == 'F') {
            pop(&stack, &currentToken);
            pushing(12);
        } else if (info_top(stack) == 'P') {
            pop(&stack, &currentToken);
            pushing(13);
        } else if (info_top(stack) == '_') {
            pop(&stack, &currentToken);
            if (tokens.tab[i] == 'c') {
                pushing(14);
            } else if (tokens.tab[i] == 'v') {
                pushing(15);
            }
        } else if (info_top(stack) == 'L') {
            pop(&stack, &currentToken);
            if (tokens.tab[i] == 'x') {
                pushing(16);
            } else {
                pushing(17);
            }
        } else if (info_top(stack) == 'H') {
            pop(&stack, &currentToken);
            pushing(18);
        } else if (info_top(stack) == 'M') {
            pop(&stack, &currentToken);
            pushing(19);
        } else if (info_top(stack) == 'K') {
            pop(&stack, &currentToken);
            if (tokens.tab[i + 3] == ')') {
                pushing(20);
            } else {
                pushing(21);
            }
        } else if (info_top(stack) == 'E') {
            pop(&stack, &currentToken);
            pushing(22);
        } else if (info_top(stack) == tokens.tab[i]) {
            pop(&stack, &currentToken);
            i = i + 1;
        } else {
            success = false;
        }

        if (currentToken == 'Z') {
            success = false;
        }


    }

    if ((success == true) && (!is_empty(stack))) {
        pop(&stack, &currentToken);
        if (currentToken == 'Z') {
            printf("Compile success\n");
        } else {
            printf("Compile failed\n");
            if (i > 0) {
                printf("Expected end of file at line - %d\n", tokens.row[i - 1]);
            } else {
                printf("Expected end of file at line - %d\n", tokens.row[0]);
            }
        }
    } else {
        printf("Compile failed\n");
        if (i > 0) {
            printf("Syntax error at line - %d\n", tokens.row[i - 1]);
        } else {
            printf("Syntax error at line - %d\n", tokens.row[0]);
        }
    }

    while (!is_empty(stack)) {
        pop(&stack, &currentToken);
    }

    return 0;
}
