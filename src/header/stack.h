/* Nama/ NIM		: Jeremia Jason Lasiman / 13514021
 * Nama file		: stack.h
 * Topik		    : Stack & Queue Dengan Reprensentasi List
 * Tanggal		    : 5 November 2015
 * Deskripsi		: header ADT stack
*/

#ifndef    STACK_H
#define STACK_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/*	MODUL STACK 
	Deklarasi stack yang diimplementasi dengan list linier 
	dengan representasi fisik pointer 
	TOP adalah alamat elemen puncak 
	
	Definisi stack kosong, top adalah Nil
*/
#define Nil NULL

/* Definisi Type Stack */
typedef char InfoType;
typedef struct tElmtStack *Address;
typedef struct tElmtStack {
    InfoType info;
    Address next;
} ElmtStack;

typedef struct {
    Address top;
} Stack;

/*	TOP(stack) = Nil adalah stack dengan elemen kosong
	Definisi stack dengan representasi berkait : 
	Jika stack adalah Stack maka akses elemen : */

#define top(S) (S).top
#define info(S) (S)->info
#define next(S) (S)->next
#define info_top(S) info(top(S))

/** Konstruktor/Kreator **/
void create_empty(Stack *S);
/*	I.stack. Sembarang
	F.stack. Membuat sebuah stack stack yang kosong
	Ciri stack kosong : TOP bernilai Nil
*/

/* Prototype manajemen memori */
void allocate(Address *P, InfoType X);

/*	I.stack. P Sembarang, tokens terdefinisi
	F.stack. Alamat P dialokasi, jika berhasil maka info(P) = tokens dan next(P) = Nil
	P = Nil jika alokasi gagal 
*/

void dealloc(Address *P);
/*	I.stack. P adalah hasil alokasi, P <> Nil
	F.stack. Alamat P didealokasi, dikembalikan ke sistem
*/


/* Predikat Untuk test keadaan KOLEKSI */
boolean is_empty(Stack S);
/*	Mengirim true jika Stack kosong : lihat definisi di atas */

/* Operator Dasar Stack */
void push(Stack *S, InfoType X);

/*	Menambahkan tokens sebagai elemen Stack stack.
	I.stack. stack mungkin kosong, tabel penampung elemen stack TIDAK penuh
	F.stack. tokens menjadi TOP yang baru, jika alokasi elemen baru berhasil.
	Jika alokasi gagal, stack tetap.
*/

void pop(Stack *S, InfoType *X);
/*	Menghapus tokens dari Stack stack.
	I.stack. stack tidak kosong
	F.stack. tokens adalah nilai elemen TOP yang lama, elemen top yang lama didealokasi,
	TOP(stack) = next(TOP(stack)).
*/

#endif
