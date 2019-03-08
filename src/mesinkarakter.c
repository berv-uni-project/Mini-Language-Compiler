#include "header/mesin_karakter.h"

//definisi states
char current_character;
boolean EOP;

static FILE *pita;

void start(const char *filename)
/* 	I.stack. sembarang
	F.stack. current_character adalah karakter pertama pita (stdin)
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/
{
    pita = fopen(filename, "r");
    if (pita == NULL) {
        fprintf(stderr, "No file\n");
        EOP = true;
    } else {
        advance();
    }
}

void advance()
/*	I.stack. current_character!=mark
	F.stack. current_character adalah karakter berikutnya yang dapat diakuisisi
		 contoh untuk pita "IF", bila current_character menunjuk 'I', maka current_character berikutnya adalah 'F'
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/
{
    current_character = fgetc(pita);
    EOP = (current_character == EOF);
    if (EOP) {
        fclose(pita);
    }
}

