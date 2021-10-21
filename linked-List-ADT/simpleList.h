#ifndef SIMPLELIST_H_INCLUDED
#define SIMPLELIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define boolean unsigned char
#define Nil NULL

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
	infotype Info;
	address Next;
} ElmtList;
typedef struct {
	address First;
} List;

#define Info(P)  (P)->Info
#define Next(P)  (P)->Next
#define First(L) ((L).First)

/* PROTOTYPE */

/* ---Test List Kosong--- */
boolean ListEmpty(List L);
/* Mengirim true jika list kosong */

/* ---Pembuatan List Kosong--- */
void CreateList(List *L);
/* I.S. : Sembarang             */
/* F.S. : Terbentuk list kosong */

/* ---Manajemen Memory--- */
address Alokasi(infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi(address *P);
/* I.S. : P terdefinisi */
/* F.S. : P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

void PrintInfo(List L);
/* I.S. : List mungkin kosong */
/* F.S. : Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */

/* ---Penambahan Elemen--- */
void InsertFirst(List *L, address P);
/* I.S. : Sembarang, P sudah dialokasi */
/* F.S. : Menambahkan elemen ber-address P sebagai elemen pertama */

void InsVFirst(List *L, infotype X);
/* I.S.   : L mungkin kosong */
/* F.S.   : X ditambahkan sebagai elemen pertama L */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan nilai X */
/* jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/* ---Penambahan Elemen--- */
void InsertLast(List *L, infotype X);
/* I.S. : Sembarang, P sudah dialokasi */
/* F.S. : Menambahkan elemen ber-address P sebagai elemen pertama */

void insertNth(List *L,infotype X, int nth);

void deleteBegin(List *L);

int menu();


#endif // SIMPLELIST_H_INCLUDED
