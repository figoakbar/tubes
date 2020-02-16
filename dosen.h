#ifndef DOSEN_H_INCLUDED
#define DOSEN_H_INCLUDED
#include <iostream>
#define info(P) P->info
#define jml_mahasiswa(P) P->jml_mahasiswa
#define nextDosen(P) P->nextDosen
#define prevDosen(P) P->prevDosen
#define first_dosen(L) L.first_dosen
#define last_dosen(L) L.last_dosen

/* Double Sircular Linked List dengan InsertLast */

using namespace std;

struct Dosen{
    string nama;
    string kode;
    string matkul;
};
typedef struct elmDosen *adrDosen;
struct elmDosen{
    Dosen info;
    adrDosen nextDosen;
    adrDosen prevDosen;
    int jml_mahasiswa;
};
struct ListDosen{
    adrDosen first_dosen;
    adrDosen last_dosen;
};

bool isEmpty(ListDosen L);
adrDosen alokasiDosen(string nama,string kode,string matkul);
void createListDosen(ListDosen &L);
void insertlast(ListDosen &L,adrDosen P);
void deletefirst(ListDosen &L,adrDosen &P);
void deletelast(ListDosen &L, adrDosen &P);
void deleteX(ListDosen &L, adrDosen &P,string X);
adrDosen SearchDosen(ListDosen L,string X);
void printMaxDosen(ListDosen L);
void printMinDosen(ListDosen L);

#endif // DOSEN_H_INCLUDED

