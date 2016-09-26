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

#include "stack.h"
#include "scanner.h"

/*Kamus*/
ArrToken X;

Stack S;
char D[30][12];
char A;
int baris;
boolean sukses;



void InputMatrixStack()
{
	int i,j;

	for (i=0;i<=25;i++)
	{
		for(j=0;j<=11;j++)
		{
			D[i][j]='|';
		}
	}

	D[1][1] = 'e';	D[1][2] = 'B';	D[1][3] = 'b';
	D[2][1] = 'e';	D[2][2] = 'B';
	D[3][1] = 'I';
	D[4][1] = 'D';
	D[5][1] = 'F';
	D[6][1] = 'M';
	D[7][1] = 'K';
	D[8][1] = 'H';	D[8][2] = 'E';	D[8][3] = 'v';
	D[9][1] = 'S';	D[9][2] = 'h';	D[9][3] = 'P';	D[9][4] = 'i';
	D[10][1] = 'S';	D[10][2] = 'l';
	D[10][1] = 'B';	D[11][2] = 'P';	D[11][3] = 'w';	D[11][4] = '~';	D[11][5] = 'B';	D[11][6] = 'd';
	D[12][1] = 'S';	D[12][2] = 'd';	D[12][3] = ')';	D[12][4] = 'c';	D[12][5] = 't';	D[12][6] = 'c';	D[12][7] = 'E';	D[12][8] = 'v';	D[12][9] = '(';	D[12][10] = 'f';
	D[13][1] = ')';	D[13][2] = '_';	D[13][3] = 'L';	D[13][4] = '_';	D[13][5] = '(';
	D[14][1] = 'c';
	D[15][1] = 'v';
	D[16][1] = 'x';
	D[17][1] = 'E';
	D[18][1] = '_';	D[18][2] = 'a';	D[18][3] = '_';
	D[19][1] = ')';	D[19][2] = 'v';	D[19][3] = '(';	D[19][4] = 'n';
	D[20][1] = ')';	D[20][2] = 'v';	D[20][3] = '(';	D[20][4] = 'o';
	D[21][1] = ')';	D[21][2] = 'H';	D[21][3] = '(';	D[21][4] = 'o';
	D[22][1] = '=';
}

void Pushing(int i)
{
	int j = 1;

	while (D[i][j]!='|')
	{
		Push(&S,D[i][j]);
		j = j + 1;
	}
}



int main()
{
	int i;
	InputMatrixStack();
	InitialToken();

	scanner();
	printf("Scan Success\n");
	sukses=true;
	i=0;
	//CreateEmpty(&S);
	Push(&S,'Z');
	Push(&S,'S'); 
	/*while (X.Tab[i]!='|')
	{
		printf("%c\n",X.Tab[i]);
		i++;
	}
	*/
	while ((X.Tab[i]!='|')&&(sukses==true))
	{
		printf("%c\n", X.Tab[i]);
		//printf("%c\n", InfoTop(S));
		if (InfoTop(S)=='S')
		{
			Pop(&S,&A);
			if (X.Tab[i+1]=='e')
			{
				Pushing(2);
			}
			else
			{
				Pushing(1);
			}
		}
		else if (InfoTop(S)=='B')
		{
			if (X.Tab[i]=='i')
			{
				Pushing(3);
			}
			else if (X.Tab[i]=='d')
			{
				Pop(&S,&A);
				Pushing(4);
			}
			else if (X.Tab[i]=='f')
			{
				Pushing(5);
			}
			else if (X.Tab[i]=='n')
			{
				Pushing(6);
			}
			else if (X.Tab[i]=='o')
			{
				Pushing(7);
			}
			else if (X.Tab[i]=='v')
			{
				Pushing(8);
			}
			else if ((X.Tab[i]=='e')||(X.Tab[i]=='w'))
			{
				Pop(&S,&A);
				if (X.Tab[i]=='w')
				{
					Pop(&S,&A);
					Push(&S,'B');
					if (A!='~')
					{
						sukses=false;
					}
				}
			}
		}
		else if (InfoTop(S)=='I')
		{
			Pop(&S,&A);
			Push(&S,'+');
			Pushing(9);
		}
		else if (InfoTop(S)=='+')
		{
			Pop(&S,&A);
			if (X.Tab[i]=='l')
			{
				Pushing(10);
			}
		}
		else if (InfoTop(S)=='D')
		{
			Pop(&S,&A);
			Pushing(11);
		}
		else if (InfoTop(S)=='F')
		{
			Pop(&S,&A);
			Pushing(12);
		}
		else if (InfoTop(S)=='P')
		{
			Pop(&S,&A);
			Pushing(13);
		}
		else if (InfoTop(S)=='_')
		{
			Pop(&S,&A);
			if (X.Tab[i]=='c')
			{
				Pushing(14);
			}
			else if (X.Tab[i]=='v')
			{
				Pushing(15);
			}
		}
		else if (InfoTop(S)=='L')
		{
			Pop(&S,&A);
			if(X.Tab[i]=='x')
			{
				Pushing(16);
			}
			else
			{
				Pushing(17);
			}
		}
		else if (InfoTop(S)=='H')
		{
			Pop(&S,&A);
			Pushing(18);
		}
		else if (InfoTop(S)=='M')
		{
			Pop(&S,&A);
			Pushing(19);
		}
		else if (InfoTop(S)=='K')
		{
			Pop(&S,&A);
			if (X.Tab[i+3]==')')
			{
				Pushing(20);
			}
			else
			{
				Pushing(21);
			}
		}
		else if (InfoTop(S)=='E')
		{
			Pop(&S,&A);
			Pushing(22);
		}
		else if(InfoTop(S)==X.Tab[i])
		{
			Pop(&S,&A);
			i=i+1;
		}
		else
		{
			sukses = false;
		}

		if (A=='Z')
		{
			sukses = false;
		}


	}

	if ((sukses == true)&&(!IsEmpty(S)))
	{
		Pop(&S,&A);
		if (A=='Z')
		{
			printf("Compile success\n");
		}
		else
		{
			printf("Compile failed\n");
			if (i>0)
			{
				printf("Expected end of file at line - %d\n", X.baris[i-1]);
			}
			else
			{
				printf("Expected end of file at line - %d\n", X.baris[0]);
			}
		}
	}
	else
	{
		printf("Compile failed\n");
		if (i>0)
		{
			printf("Syntax error at line - %d\n", X.baris[i-1]);
		}
		else
		{
			printf("Syntax error at line - %d\n", X.baris[0]);	
		}
	}
	
	while(!IsEmpty(S))
	{
		Pop(&S,&A);
	}
	
	return 0;
}
