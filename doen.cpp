#include "dosen.h"

bool isEmpty(ListDosen L){
    return(first_dosen(L) == NULL);
}

adrDosen alokasiDosen(string nama,string kode, string matkul){
    adrDosen P = new elmDosen;
    info(P).nama = nama;
    info(P).kode = kode;
    info(P).matkul = matkul;
    jml_mahasiswa(P) = 0;
    nextDosen(P) = NULL;
    prevDosen(P) = NULL;
    return P;
}

void createListDosen(ListDosen &L){
    first_dosen(L) = NULL;
    last_dosen(L) = NULL;
}

void insertlast(ListDosen &L, adrDosen P){
    if(isEmpty(L)){
        first_dosen(L) = P;
        last_dosen(L) = P;
        nextDosen(P) = first_dosen(L);
        prevDosen(P) = first_dosen(L);
    }else{
        nextDosen(last_dosen(L)) = P;
        nextDosen(P) = first_dosen(L);
        prevDosen(P) = last_dosen(L);
        last_dosen(L) = P;
        prevDosen(first_dosen(L)) = last_dosen(L);
    }
}

void deletefirst(ListDosen &L, adrDosen &P){
    if(isEmpty(L)){
        P = NULL;
    }else{
        if(nextDosen(first_dosen(L)) == first_dosen(L)){
            first_dosen(L) = NULL;
            last_dosen(L) = NULL;
        }else{
            P = first_dosen(L);
            first_dosen(L) = nextDosen(P);
            prevDosen(first_dosen(L)) = last_dosen(L);
            nextDosen(last_dosen(L)) = first_dosen(L);
            prevDosen(P) = NULL;
            nextDosen(P) = NULL;
        }
    }
}

void deletelast(ListDosen &L, adrDosen &P){
    if(isEmpty(L)){
        P = NULL;
    }else{
        if(nextDosen(first_dosen(L)) == first_dosen(L)){
            deletefirst(L,P);
        }
        P = last_dosen(L);
        last_dosen(L) = prevDosen(last_dosen(L));
        nextDosen(last_dosen(L)) = first_dosen(L);
        prevDosen(first_dosen(L)) = last_dosen(L);
        prevDosen(P) = NULL;
        nextDosen(P) = NULL;
    }
}

adrDosen SearchDosen(ListDosen L, string X){
    if(!isEmpty(L)){
        adrDosen P = first_dosen(L);
        while(nextDosen(P) != first_dosen(L) && info(P).kode != X){
            P = nextDosen(P);
        }
        if(info(P).kode == X){
            return P;
        }else{
            return NULL;
        }
    }else{
        return NULL;
    }
}

void deleteX(ListDosen &L, adrDosen &P,string X){
    if(isEmpty(L)){
        P = NULL;
    }else{
        if(info(first_dosen(L)).kode == X){
            deletefirst(L,P);
        }else if(info(last_dosen(L)).kode == X){
            deletelast(L,P);
        }else{
            P = SearchDosen(L,X);
            if(P != NULL){
                nextDosen(prevDosen(P)) = nextDosen(P);
                prevDosen(nextDosen(P)) = prevDosen(P);
                nextDosen(P) = NULL;
                prevDosen(P) = NULL;
            }
        }
    }
}

void printDosen(ListDosen L){
    if(not isEmpty(L)){
        adrDosen P = first_dosen(L);
        while(nextDosen(P) != first_dosen(L)){
            cout<<"Nama : "<<info(P).nama<<endl;
            cout<<"Kode : "<<info(P).kode<<endl;
            cout<<"Matkul : "<<info(P).matkul<<endl<<endl;
            cout<<"======================================================="<<endl;
            cout<<endl;
            P = nextDosen(P);
        }
        cout<<"Nama : "<<info(P).nama<<endl;
        cout<<"Kode : "<<info(P).kode<<endl;
        cout<<"Matkul : "<<info(P).matkul<<endl<<endl;
    }else{
        cout<<"list kosong"<<endl;
    }
}
void printMaxDosen(ListDosen L){
    int Max = -9999;
    if(isEmpty(L)){
        cout<<"Data Dosen Kosong"<<endl;
    }else{
        adrDosen P = first_dosen(L);
        while(nextDosen(P) != first_dosen(L)){
            if(jml_mahasiswa(P) > Max){
                Max = jml_mahasiswa(P);
            }
            P = nextDosen(P);
        }
        if(jml_mahasiswa(P) > Max){
            Max = jml_mahasiswa(P);
        }
        P = first_dosen(L);
        while(nextDosen(P) != first_dosen(L)){
            if(jml_mahasiswa(P) == Max){
                cout<<"Nama Dosen       : "<<info(P).nama<<endl;
                cout<<"Kode Dosen       : "<<info(P).kode<<endl;
                cout<<"Jumlah Mahasiswa : "<<Max<<endl;
                cout<<"============================================="<<endl;
            }
            P = nextDosen(P);
        }
        if(jml_mahasiswa(P) == Max){
            cout<<"Nama Dosen       : "<<info(P).nama<<endl;
            cout<<"Kode Dosen       : "<<info(P).kode<<endl;
            cout<<"Jumlah Mahasiswa : "<<Max<<endl;
            cout<<"============================================="<<endl;
        }
    }
}


void printMinDosen(ListDosen L){
    int Min = 9999;
    if(isEmpty(L)){
        cout<<"Data Dosen Kosong"<<endl;
    }else{
        adrDosen P = first_dosen(L);
        while(nextDosen(P) != first_dosen(L)){
            if(jml_mahasiswa(P) < Min){
                Min = jml_mahasiswa(P);
            }
            P = nextDosen(P);
        }
        if(jml_mahasiswa(P) < Min){
            Min = jml_mahasiswa(P);
        }
        P = first_dosen(L);
        while(nextDosen(P) != first_dosen(L)){
            if(jml_mahasiswa(P) == Min){
                cout<<"Nama Dosen       : "<<info(P).nama<<endl;
                cout<<"Kode Dosen       : "<<info(P).kode<<endl;
                cout<<"Jumlah Mahasiswa : "<<Min<<endl;
                cout<<"============================================="<<endl;
            }
            P = nextDosen(P);
        }
        if(jml_mahasiswa(P) == Min){
            cout<<"Nama Dosen       : "<<info(P).nama<<endl;
            cout<<"Kode Dosen       : "<<info(P).kode<<endl;
            cout<<"Jumlah Mahasiswa : "<<Min<<endl;
            cout<<"============================================="<<endl;
        }
    }
}
