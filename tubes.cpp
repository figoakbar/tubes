#include "tubes.h"

void createlist(List_mahasiswa &L){
    first_mahasiswa(L) = NULL;
}

bool isEmpty(List_mahasiswa L){
    return (first_mahasiswa(L) == NULL);
}
infotype_mhs input_data(List_mahasiswa L){
    infotype_mhs X;
    cout<<"nama : ";
    cin>>X.namaMhs;
    cout<<"NIM : ";
    cin>>X.NIM;
    cout<<"jurusan : ";
    cin>>X.jurusan;
    return X;
}

address_mahasiswa createNewElmt(infotype_mhs x){
    address_mahasiswa p = new elmlist;
    info_mahasiswa(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}

void insertFirst(List_mahasiswa &L, address_mahasiswa p){
    if(first_mahasiswa(L) == NULL){
        first_mahasiswa(L) = p;
        last_mahasiswa(L) = p;
    }
    else{
        next(p) = first_mahasiswa(L);
        prev(first_mahasiswa(L)) = p;
        first_mahasiswa(L) = p;
    }
}

void insertLast(List_mahasiswa &L, address_mahasiswa p){
    if (first_mahasiswa(L) == NULL){
        first_mahasiswa(L) = p;
        last_mahasiswa(L) = p;
    }
    else{
        prev(p) = last_mahasiswa(L);
        next(last_mahasiswa(L)) = p;
        last_mahasiswa(L) = p;
    }
}
void deleteFirst(List_mahasiswa &L, address_mahasiswa p){
    if (first_mahasiswa(L) != last_mahasiswa(L)){
        p = first_mahasiswa(L);
        first_mahasiswa(L) = next(p);
        next(p) = NULL;
        prev(first_mahasiswa(L)) = NULL;
    }
    else if (first_mahasiswa(L) == last_mahasiswa(L)){
        p = first_mahasiswa(L);
        first_mahasiswa(L) = NULL;
        last_mahasiswa(L) = NULL;
    }

}
void deleteAfter (List_mahasiswa &L, address_mahasiswa prec, address_mahasiswa &p){
    prec = first_mahasiswa(L);
    while(next(prec) != p){
        prec = next(prec);
    }
    next(prec) = next(p);
    prev(next(p)) = prec;
    next(p) = NULL;
    prev(p) = NULL;
}
void deleteLast(List_mahasiswa &L, address_mahasiswa &p){
    if(next(first_mahasiswa(L)) == NULL) {
        deleteFirst(L,p);
    } else {
        p = last_mahasiswa(L);
        last_mahasiswa(L) = prev(p);
        next(last_mahasiswa(L)) = NULL;
        prev(p) = NULL;
    }
}
address_mahasiswa Search_parent(List_mahasiswa L, string x){
    address_mahasiswa P = first_mahasiswa(L);
    while(P != NULL && info_mahasiswa(P).NIM != x){
        P = next(P);
    }
    return P;
}

void deleteX(List_mahasiswa &L, address_mahasiswa &P, string X){
    if(isEmpty(L)){
       P = NULL;
    }
    else{
        P = Search_parent(L,X);
        if (P != NULL){
            if(P == first_mahasiswa(L)){
                deleteFirst(L,P);
            }
            else if(P == last_mahasiswa(L)){
                deleteLast(L,P);
            }
            else{
                address_mahasiswa prec;
                deleteAfter(L,prec,P);
            }
        }
    }
}

void insertTerurut(List_mahasiswa &L, address_mahasiswa P){
    if(isEmpty(L)){
        insertFirst(L,P);
    }else if(info_mahasiswa(P).NIM < info_mahasiswa(first_mahasiswa(L)).NIM){
        insertFirst(L,P);
    }else if(info_mahasiswa(P).NIM > info_mahasiswa(last_mahasiswa(L)).NIM){
        insertLast(L,P);
    }else{
        address_mahasiswa Q = first_mahasiswa(L);
        while(info_mahasiswa(P).NIM > info_mahasiswa(Q).NIM){
            Q = next(Q);
        }
        next(prev(Q)) = P;
        prev(P) = prev(Q);
        prev(Q) = P;
        next(P) = Q;
    }
}
