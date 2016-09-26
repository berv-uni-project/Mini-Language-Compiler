#ifndef scanner_h
#define scanner_h

#include "mesinkarakter.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ELMAX 700

typedef char Token;
typedef struct
{
	Token Tab[ELMAX];
	int baris[ELMAX];
} ArrToken;

extern ArrToken X;

/* Pengecekan Khusus */
boolean IsLogic(char C[]);

boolean IsBilangan(char CC);

boolean IsStringBilangan(char C[]);

boolean IsVar(char CC);

/* Scanner Utama */
void scanner();

void InitialToken();

#endif
