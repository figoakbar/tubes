#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>

#define first_mahasiswa(L) L.first_mahasiswa
#define last_mahasiswa(L) L.last_mahasiswa
#define info_mahasiswa(p) p->info_mahasiswa
#define next(p) p->next
#define prev(p) p->prev

/* Double Linked LIst dengan Insert Terurut */


using namespace std;

struct mahasiswa{
    string namaMhs;
    string NIM;
    string jurusan;
};

typedef mahasiswa infotype_mhs;
typedef struct elmlist *address_mahasiswa;

struct elmlist{
    infotype_mhs info_mahasiswa;
    address_mahasiswa next;
    address_mahasiswa prev;
};

struct List_mahasiswa{
    address_mahasiswa first_mahasiswa;
    address_mahasiswa last_mahasiswa;
};

bool isEmpty(List_mahasiswa L);
void createlist(List_mahasiswa &L);
infotype_mhs input_data(List_mahasiswa L);
address_mahasiswa createNewElmt(infotype_mhs x);
void insertFirst(List_mahasiswa &L, address_mahasiswa p);
void insertLast(List_mahasiswa &L, address_mahasiswa p);
void insertTerurut(List_mahasiswa &L, address_mahasiswa P);
void deleteFirst(List_mahasiswa &L, address_mahasiswa p);
void deleteAfter (List_mahasiswa &L, address_mahasiswa &p);
void deleteLast(List_mahasiswa &L, address_mahasiswa &p);
void deleteX(List_mahasiswa &L, address_mahasiswa&P, string X);
address_mahasiswa Search_parent(List_mahasiswa L, string x);


#endif // TUBES_STD_H_INCLUDED

