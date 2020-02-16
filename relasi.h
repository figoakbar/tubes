#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "dosen.h"
#include "tubes.h"

#define first_relasi(L) L.first_relasi
#define next_relasi(p) p->next_relasi
#define adrTomahasiswa(p) p->adrTomahasiswa
#define adrTodosen(p) p->adrTodosen

/* Single Linked List dengan InsertFirst */

using namespace std;

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next_relasi;
    adrDosen adrTodosen;
    address_mahasiswa adrTomahasiswa;
};

struct list_relasi{
    address_relasi first_relasi;
};

void createRelasi(list_relasi &L);
address_relasi alokasiRelasi(adrDosen D, address_mahasiswa M);
void insertfirst(list_relasi &L, address_relasi &R, adrDosen adrD, address_mahasiswa adrM, ListDosen P, List_mahasiswa Q, string D, string M);
bool isTwo(list_relasi L,string nama);
void deleteFirst(list_relasi &L, address_relasi &P);
address_relasi search_relasi(list_relasi L, ListDosen P, List_mahasiswa Q, string D, string M);
void deleteRelasiDosen(list_relasi &L, address_relasi &adrR, string kode);
void deleteRelasiMahasiswa(list_relasi &L, address_relasi &adrR, string nim);
void printInfo_M(list_relasi LR, ListDosen LD, string nama);
void printInfo_D(list_relasi LR, List_mahasiswa LM, string nama);
void printInfo_semua(ListDosen D, List_mahasiswa M, list_relasi R);

#endif // RELASI_H_INCLUDED
