#ifndef MESINKAR_H
#define MESINKAR_H
#include "boolean.h"
#include <stdio.h>
#define mark '.'

//definisi states
extern char CC;
extern boolean EOP;

void START();
/* 	I.S. sembarang
	F.S. CC adalah karakter pertama pita (stdin)
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/

void ADV();
/*	I.S. CC!=mark
	F.S. CC adalah karakter berikutnya yang dapat diakuisisi
		 contoh untuk pita "IF", bila CC menunjuk 'I', maka CC berikutnya adalah 'F' 
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/
#endif

