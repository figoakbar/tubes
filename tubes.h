#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define info(p) p->info
#define next(p) p->next


using namespace std;

struct mahasiswa{
    string namaMhs;
    string NIM;
    string jurusan;
    string dosen;
};

typedef mahasiswa infotype_mhs;
typedef struct elmlist *address;

struct elmlist{
    mahasiswa info;
    address next;
};

struct List{
    address first;
};

bool isEmpty(List L);
void createlist(List &L);
address allocation();
void deallocation(address &p);
void printinfo(List L);
void insertfirst(List &L, address p);
void deletefirst(List &L, address &p);


#endif // TUBES_STD_H_INCLUDED

