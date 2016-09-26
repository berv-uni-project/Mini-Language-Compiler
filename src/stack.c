/* Nama/ NIM		: Jeremia Jason Lasiman / 13514021
 * Nama file		: stack.c
 * Topik		    : Stack & Queue Denga Reprensentasi List
 * Tanggal		    : 5 November 2015
 * Deskripsi		: *c ADT stack
*/

#include "boolean.h"
#include "stack.h"


/** Konstruktor/Kreator **/
void CreateEmpty (Stack *S)
/*	I.S. Sembarang 
	F.S. Membuat sebuah stack S yang kosong 
	Ciri stack kosong : TOP bernilai Nil 
*/
{
	Top(*S) = Nil;
}

/* Prototype manajemen memori */
void Alokasi (Address *P, Infotype X)
/*	I.S. P Sembarang, X terdefinisi
	F.S. Alamat P dialokasi, jika berhasil maka Info(P) = X dan Next(P) = Nil
	P = Nil jika alokasi gagal 
*/
{
	/*Algoritma*/
	*P = malloc(sizeof(Infotype));
	if (*P != Nil)
	{
		Info(*P)=X;
		Next(*P)=Nil;
	}
	else
		*P = Nil;
}

void Dealokasi (Address *P)
/*	I.S. P adalah hasil alokasi, P <> Nil
	F.S. Alamat P didealokasi, dikembalikan ke sistem
*/
{
	free(*P);
}

/* Predikat Untuk test keadaan KOLEKSI */
boolean IsEmpty (Stack S)
/*	Mengirim true jika Stack kosong : lihat definisi di atas */
{

	if (Top(S)==Nil)
		return true;
	else
		return false;
}

/* Operator Dasar Stack */
void Push (Stack *S, Infotype X)
/*	Menambahkan X sebagai elemen Stack S.
	I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh
	F.S. X menjadi TOP yang baru, jika alokasi elemen baru berhasil.
	Jika alokasi gagal, S tetap.
*/
{
	/*Kamus*/
	Address P;

	/*Algoritma*/
	Alokasi (&P,X);
	if (P!=Nil)
	{
		Next(P) = Top(*S);
		Top(*S) = P;
	}
}

void Pop (Stack *S, Infotype *X)
/*	Menghapus X dari Stack S.
	I.S. S tidak kosong
	F.S. X adalah nilai elemen TOP yang lama, elemen top yang lama didealokasi,
	TOP(S) = Next(TOP(S)).
*/
{
	/*Kamus*/
	Address P;
	/*Algoritma*/
	P = Top(*S);
	*X = InfoTop(*S);

	Top(*S) = Next(Top(*S));
	Next(P) = Nil;
	Dealokasi(&P);
}
