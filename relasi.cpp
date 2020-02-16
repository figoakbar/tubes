#include "relasi.h"

void createRelasi(list_relasi &L){
    first_relasi(L) = NULL;
}

address_relasi alokasiRelasi(adrDosen D, address_mahasiswa M){
    address_relasi P = new elmlist_relasi;
    adrTodosen(P) = D;
    adrTomahasiswa(P) = M;
    next_relasi(P) = NULL;
    return P;
}

void insertfirst(list_relasi &L, address_relasi &R, adrDosen adrD, address_mahasiswa adrM, ListDosen P, List_mahasiswa Q, string kode, string NIM){
    address_mahasiswa adaM = Search_parent(Q,NIM);
    adrDosen adaD = SearchDosen(P,kode);
    address_relasi adaR = search_relasi(L,P,Q,kode,NIM);
    if(adaM != NULL && adaD != NULL){
            if(adaR != NULL)
                cout<<"Dosen yang bernama "<<info(adaD).nama<<"("<<info(adaD).kode<<")"<<" sudah membimbimbing mahasiswa ini "<<info_mahasiswa(adaM).namaMhs<<"("<<info_mahasiswa(adaM).NIM<<")"<<endl;
            else if(isTwo(L,NIM)){
                cout<<"Mahasiswa sudah memiliki 2 dosen pembimbing"<<endl;
            }else{
                R = alokasiRelasi(adrD,adrM);
                next_relasi(R) = first_relasi(L);
                first_relasi(L) = R;
                adrTodosen(R) = adaD;
                adrTomahasiswa(R) = adaM;
                jml_mahasiswa(adaD) = jml_mahasiswa(adaD) + 1;
                cout<<"Data Berhasil Ditambahkan"<<endl;
            }
    }else if(adaM == NULL){
        cout<<"Mahasiswa Tidak Ditemukan"<<endl;
    }else if(adaD == NULL){
        cout<<"Dosen Tidak Ditemukan"<<endl;
    }
}

void deleteFirst(list_relasi &L, address_relasi &P){
    P = first_relasi(L);
    first_relasi(L) = next_relasi(P);
    next_relasi(P) = NULL;
    adrTodosen(P) = NULL;
    adrTomahasiswa(P) = NULL;
}

bool isTwo(list_relasi L, string NIM){
    address_relasi P = first_relasi(L);
    int jml = 0;
    while(P != NULL){
        if(info_mahasiswa(adrTomahasiswa(P)).NIM == NIM){
            jml++;
        }
        P = next_relasi(P);
    }
    if(jml >= 2){
        return true;
    }else{
        return false;
    }
}

void printInfo_M(list_relasi LR, ListDosen LD, string kode){
    adrDosen P = SearchDosen(LD,kode);
    if(P == NULL){
        cout<<"Dosen Tidak Ditemukan"<<endl;
    }else if(jml_mahasiswa(P) == 0){
        cout<<"Dosen belum Mempunyai mahasiswa bimbingan"<<endl;
    }
    else{
        address_relasi R = first_relasi(LR);
        while(R != NULL){
            if(info(adrTodosen(R)).kode == kode){
                cout<<"Nama Mahasiswa   : "<<info_mahasiswa(adrTomahasiswa(R)).namaMhs<<endl;
                cout<<"NIM mahasiswa    : "<<info_mahasiswa(adrTomahasiswa(R)).NIM<<endl;
                cout<<"Jurusan Mahasiswa: "<<info_mahasiswa(adrTomahasiswa(R)).jurusan<<endl;
                cout<<endl;
                cout<<"======================================================="<<endl;
                cout<<endl;
            }
            R = next_relasi(R);
        }
    }
}

void printInfo_D(list_relasi LR, List_mahasiswa LM, string NIM){
    address_mahasiswa P = Search_parent(LM,NIM);
    if(P == NULL){
        cout<<"Mahasiswa Tidak Ditemukan"<<endl;
    }
    else{
        address_relasi Q = first_relasi(LR);
        int jml = 0;
        while(Q != NULL){
            if(info_mahasiswa(adrTomahasiswa(Q)).NIM == NIM){
                jml++;
            }
            Q = next_relasi(Q);
        }
        if(jml == 0){
            cout<<"Mahasiswa belum mempunyai Dosen Bimbingan"<<endl;
        }
        else{
            address_relasi R = first_relasi(LR);
            while(R != NULL){
                if(info_mahasiswa(adrTomahasiswa(R)).NIM == NIM){
                    cout<<"Nama Dosen   : "<<info(adrTodosen(R)).nama<<endl;
                    cout<<"Kode Dosen   : "<<info(adrTodosen(R)).kode<<endl;
                    cout<<"Matkul       : "<<info(adrTodosen(R)).matkul<<endl;
                    cout<<"======================================================="<<endl;
                    cout<<endl;
                }
                R = next_relasi(R);
            }
        }
    }
}

void printInfo_semua(ListDosen D, List_mahasiswa M, list_relasi R){
    if(first_mahasiswa(M) == NULL){
        cout<<"Data Kosong"<<endl;
    }
    else{
        address_mahasiswa mhs = first_mahasiswa(M);
        while(mhs != NULL){
            cout<<"Nama Mahasiswa       : "<<info_mahasiswa(mhs).namaMhs<<endl;
            cout<<"NIM Mahasiswa        : "<<info_mahasiswa(mhs).NIM<<endl;
            cout<<"Jurusan Mahasiswa    : "<<info_mahasiswa(mhs).jurusan<<endl;
            address_relasi rls = first_relasi(R);
            cout<<"Dosen Pembimbing : ";
            while(rls != NULL){
                if(info_mahasiswa(adrTomahasiswa(rls)).NIM == info_mahasiswa(mhs).NIM){
                    cout<<info(adrTodosen(rls)).nama<<"("<<info(adrTodosen(rls)).kode<<")"<<" , ";
                }
                rls = next_relasi(rls);
            }
            mhs = next(mhs);
            cout<<endl;
            cout<<"======================================================="<<endl;
            cout<<endl;
        }
    }
}

address_relasi search_relasi(list_relasi L, ListDosen P, List_mahasiswa Q, string kode, string NIM){
    adrDosen S = SearchDosen(P,kode);
    address_mahasiswa O = Search_parent(Q,NIM);
    address_relasi R = first_relasi(L);
    if(S != NULL && O != NULL){
        while(R != NULL){
            if (S == adrTodosen(R) && O == adrTomahasiswa(R)){
                return R;
            }
            R = next_relasi(R);
        }
    }
    return NULL;
}

void deleteRelasiDosen(list_relasi &L, address_relasi &adrR, string kode){
    address_relasi P = first_relasi(L);
    while(P != NULL){
        if(info(adrTodosen(P)).kode == kode){
            if(P == first_relasi(L)){
                P = next_relasi(P);
                deleteFirst(L,adrR);
            }else{
                address_relasi a = first_relasi(L);
                while(next_relasi(a) != P){
                    a = next_relasi(a);
                }
                adrR = P;
                P = next_relasi(P);
                next_relasi(a) = next_relasi(adrR);
                adrTodosen(adrR) = NULL;
                adrTomahasiswa(adrR) = NULL;
            }
        }else{
            P = next_relasi(P);
        }
    }
}


void deleteRelasiMahasiswa(list_relasi &L, address_relasi &adrR, string nim){
    address_relasi P = first_relasi(L);
    while(P != NULL){
        if(info_mahasiswa(adrTomahasiswa(P)).NIM == nim){
            if(P == first_relasi(L)){
                P = next_relasi(P);
                jml_mahasiswa(adrTodosen(P))--;
                deleteFirst(L,adrR);
            }else{
                address_relasi a = first_relasi(L);
                while(next_relasi(a) != P){
                    a = next_relasi(a);
                }
                adrR = P;
                jml_mahasiswa(adrTodosen(adrR))--;
                P = next_relasi(P);
                next_relasi(a) = next_relasi(adrR);
                next_relasi(adrR) = NULL;
                adrTodosen(adrR) = NULL;
                adrTomahasiswa(adrR) = NULL;
            }
        }else{
            P = next_relasi(P);
        }
    }
}
