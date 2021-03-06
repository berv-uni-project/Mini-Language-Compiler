/* Nama/ NIM		: Jeremia Jason Lasiman / 13514021
 * Nama file		: stack.c
 * Topik		    : Stack & Queue Denga Reprensentasi List
 * Tanggal		    : 5 November 2015
 * Deskripsi		: *c ADT stack
*/

#include "header/boolean.h"
#include "header/stack.h"


/** Konstruktor/Kreator **/
void create_empty(Stack *S)
/*	I.stack. Sembarang
	F.stack. Membuat sebuah stack stack yang kosong
	Ciri stack kosong : TOP bernilai Nil
*/
{
    top(*S) = Nil;
}

/* Prototype manajemen memori */
void allocate(Address *P, InfoType X)
/*	I.stack. P Sembarang, tokens terdefinisi
	F.stack. Alamat P dialokasi, jika berhasil maka info(P) = tokens dan next(P) = Nil
	P = Nil jika alokasi gagal 
*/
{
    /*Algoritma*/
    *P = malloc(sizeof(InfoType));
    if (*P != Nil) {
        info(*P) = X;
        next(*P) = Nil;
    } else
        *P = Nil;
}

void dealloc(Address *P)
/*	I.stack. P adalah hasil alokasi, P <> Nil
	F.stack. Alamat P didealokasi, dikembalikan ke sistem
*/
{
    free(*P);
}

/* Predikat Untuk test keadaan KOLEKSI */
boolean is_empty(Stack S)
/*	Mengirim true jika Stack kosong : lihat definisi di atas */
{

    if (top(S) == Nil) {
        return true;
    } else {
        return false;
    }
}

/* Operator Dasar Stack */
void push(Stack *S, InfoType X)
/*	Menambahkan tokens sebagai elemen Stack stack.
	I.stack. stack mungkin kosong, tabel penampung elemen stack TIDAK penuh
	F.stack. tokens menjadi TOP yang baru, jika alokasi elemen baru berhasil.
	Jika alokasi gagal, stack tetap.
*/
{
    /*Kamus*/
    Address P;

    /*Algoritma*/
    allocate(&P, X);
    if (P != Nil) {
        next(P) = top(*S);
        top(*S) = P;
    }
}

void pop(Stack *S, InfoType *X)
/*	Menghapus tokens dari Stack stack.
	I.stack. stack tidak kosong
	F.stack. tokens adalah nilai elemen TOP yang lama, elemen top yang lama didealokasi,
	TOP(stack) = next(TOP(stack)).
*/
{
    /*Kamus*/
    Address P;
    /*Algoritma*/
    P = top(*S);
    *X = info_top(*S);

    top(*S) = next(top(*S));
    next(P) = Nil;
    dealloc(&P);
}
