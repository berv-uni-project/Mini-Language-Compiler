#ifndef MESIN_KARAKTER_H
#define MESIN_KARAKTER_H

#include "boolean.h"
#include <stdio.h>

#define mark '.'

// States Definition
extern char current_character;
extern boolean EOP;

/* 	I.stack. sembarang
	F.stack. current_character adalah karakter pertama pita (stdin)
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/
void start(const char *filename);

/*	I.stack. current_character!=mark
	F.stack. current_character adalah karakter berikutnya yang dapat diakuisisi
		 contoh untuk pita "IF", bila current_character menunjuk 'I', maka current_character berikutnya adalah 'F'
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/
void advance();

#endif

