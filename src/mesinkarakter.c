#include "mesinkarakter.h"

//definisi states
char CC;
boolean EOP;

static FILE *pita;
static int retval;

void START()
/* 	I.S. sembarang
	F.S. CC adalah karakter pertama pita (stdin)
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/
{
		pita = fopen("program.txt","r");
		if (pita==NULL)
		{
			fprintf(stderr, "No file\n" );
			EOP=true;
		}
		else
		{
			ADV();
		}
}

void ADV()
/*	I.S. CC!=mark
	F.S. CC adalah karakter berikutnya yang dapat diakuisisi
		 contoh untuk pita "IF", bila CC menunjuk 'I', maka CC berikutnya adalah 'F' 
		 Bila Kondisi EOP terpenuhi, nyalakan EOP
*/
{
	CC=fgetc(pita);
	EOP = (CC==EOF);
	if (EOP)	{
		fclose(pita);
	}
}

