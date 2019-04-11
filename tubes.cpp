#include "tubes.h"

void createlist(List &L){
    first(L) = NULL;
}

bool isEmpty(List L){
    return (first(L) == NULL);
}
address allocation(){
    address P;
    char pilih;
    P = new elmlist;
        cout<<"nama : ";
        cin>>info(P).namaMhs;
        cout<<"NIM : ";
        cin>>info(P).NIM;
        cout<<"jurusan : ";
        cin>>info(P).jurusan;
    return P;
}

void deallocation(address &P){
    delete P;
}

void insertfirst(List L, address P){
    if(isEmpty(L))
        {
       first(L) = P;
    }
    else{
        next(P) = first(L);
        first(L) = P;
    }
}

// testestes