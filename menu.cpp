#include "menu.h"
#include "dosen.h"
#include "tubes.h"
#include "relasi.h"
#include <stdlib.h>
#include <conio.h>

void MenuInsert(ListDosen &LD, List_mahasiswa &LM, list_relasi &LR){
    char jawaban;
    adrDosen P;
    address_mahasiswa Q;
    address_relasi R;
    adrDosen adrD;
    string nama;
    string kode;
    string matkul;
    string nim;
    string D,M;
    char pilihan1;
    char pilihan2;
    infotype_mhs x;
    adrDosen Trc;
    address_mahasiswa Trc2;
    jawaban = '1';

    while(jawaban != '0'){
        system("CLS");
        cout<<"     Menu Insert     "<<endl;
        cout<<"1. Tambah Mahasiswa"<<endl;
        cout<<"2. Tambah Dosen"<<endl;
        cout<<"3. Pilih Dosen Pembimbing"<<endl;
        cout<<"4. pilih Mahasiswa yang ingin Dibimbing"<<endl;
        cout<<"0. Kembali"<<endl;
        cout<<"pilihan : ";
        cin>>jawaban;

        if(jawaban == '1'){
            pilihan1 = 'z';
            while (pilihan1 != 'n'){
                system("CLS");
                x = input_data(LM);
                cout<<"apakah anda yakin ingin menambahkan data diatas ? (y/n) ";
                cin>>pilihan2;
                if(pilihan2 == 'y'){
                    address_mahasiswa adaNIM = Search_parent(LM,x.NIM);
                    if(adaNIM == NULL){
                        Q = createNewElmt(x);
                        insertTerurut(LM,Q);
                        cout<<"Data Berhasil Ditambahkan"<<endl;
                    }else{
                        cout<<"Nim sudah terdaftar"<<endl;
                    }
                }else{
                    cout<<"Data Gagal Ditambahkan"<<endl;
                }
                cout<<"apakah anda ingin lanjut menambahkan data ? (y/n) ";
                cin>>pilihan1;
            }
            break;

        }else if(jawaban == '2'){
            system("CLS");
            pilihan1 = 'z';
            while(pilihan1 != 'n'){
                system("CLS");
                cout<<"Masukkan nama dosen      : ";
                cin>>nama;
                cout<<"Masukkan kode dosen      : ";
                cin>>kode;
                cout<<"Masukkan matkul dosen    : ";
                getline(cin>>ws,matkul);
                cout<<"apakah anda yakin ingin menambahkan data diatas ? (y/n) ";
                cin>>pilihan2;
                if(pilihan2 == 'y'){
                    adrDosen adaKode = SearchDosen(LD,kode);
                    if(adaKode == NULL){
                        P = alokasiDosen(nama,kode,matkul);
                        insertlast(LD,P);
                        cout<<"Data Berhasil Ditambahkan"<<endl;
                    }else{
                        cout<<"Kode Dosen sudah terdaftar"<<endl;
                    }
                }else{
                    cout<<"Data Gagal Ditambahkan"<<endl;
                }

                cout<<"apakah anda ingin lanjut menambahkan data ? (y/n) ";
                cin>>pilihan1;
            }
            break;
        }else if(jawaban == '3'){
            pilihan1 = 'z';
            while(pilihan1 != 'n'){
                system("CLS");
                cout<<"List Dosen : "<<endl<<endl;
                Trc = first_dosen(LD);
                if(Trc != NULL){
                    while(nextDosen(Trc) != first_dosen(LD)){
                        cout<<"     Nama Dosen   : "<<info(Trc).nama<<endl;
                        cout<<"     Kode Dosen   : "<<info(Trc).kode<<endl;
                        cout<<"     Matkul       : "<<info(Trc).matkul<<endl;
                        cout<<"     ======================================================="<<endl;
                        cout<<endl;
                        Trc = nextDosen(Trc);
                    }
                    cout<<"     Nama Dosen   : "<<info(Trc).nama<<endl;
                    cout<<"     Kode Dosen   : "<<info(Trc).kode<<endl;
                    cout<<"     Matkul       : "<<info(Trc).matkul<<endl;
                    cout<<"     ======================================================="<<endl;
                    cout<<endl;
                }else{
                    cout<<"     Data Dosen Kosong"<<endl<<endl;
                }

                cout<<"List Mahasiswa : "<<endl<<endl;

                Trc2 = first_mahasiswa(LM);
                if(Trc2 != NULL){
                    while(Trc2 != NULL){
                        cout<<"     Nama Mahasiswa       : "<<info_mahasiswa(Trc2).namaMhs<<endl;
                        cout<<"     NIM Mahasiswa        : "<<info_mahasiswa(Trc2).NIM<<endl;
                        cout<<"     Jurusan Mahasiswa    : "<<info_mahasiswa(Trc2).jurusan<<endl;
                        cout<<"     ======================================================="<<endl;
                        cout<<endl;
                        Trc2 = next(Trc2);
                    }
                }else{
                    cout<<"     Data Mahasiswa Kosong"<<endl;
                }

                cout<<endl;
                cout<<"NIM Mahasiswa             : ";
                cin>>nim;
                cout<<"Kode Dosen                : ";
                cin>>kode;
                insertfirst(LR,R,adrD,Q,LD,LM,kode,nim);
                cout<<endl;
                cout<<"Apakah anda ingin lanjut penginputan ? (y/n) ";
                cin>>pilihan1;
            }
            break;
        }else if(jawaban == '4'){
           pilihan1 = 'z';
            while(pilihan1 != 'n'){
                system("CLS");
                cout<<"List Dosen : "<<endl<<endl;
                Trc = first_dosen(LD);
                if(Trc != NULL){
                    while(nextDosen(Trc) != first_dosen(LD)){
                        cout<<"     Nama Dosen   : "<<info(Trc).nama<<endl;
                        cout<<"     Kode Dosen   : "<<info(Trc).kode<<endl;
                        cout<<"     Matkul       : "<<info(Trc).matkul<<endl;
                        cout<<"     ======================================================="<<endl;
                        cout<<endl;
                        Trc = nextDosen(Trc);
                    }
                    cout<<"     Nama Dosen   : "<<info(Trc).nama<<endl;
                    cout<<"     Kode Dosen   : "<<info(Trc).kode<<endl;
                    cout<<"     Matkul       : "<<info(Trc).matkul<<endl;
                    cout<<"     ======================================================="<<endl;
                    cout<<endl;
                }else{
                    cout<<"     Data Dosen Kosong"<<endl<<endl;
                }
                cout<<"List Mahasiswa : "<<endl<<endl;

                Trc2 = first_mahasiswa(LM);
                if(Trc2 != NULL){
                    while(Trc2 != NULL){
                        cout<<"     Nama Mahasiswa       : "<<info_mahasiswa(Trc2).namaMhs<<endl;
                        cout<<"     NIM Mahasiswa        : "<<info_mahasiswa(Trc2).NIM<<endl;
                        cout<<"     Jurusan Mahasiswa    : "<<info_mahasiswa(Trc2).jurusan<<endl;
                        cout<<"     ======================================================="<<endl;
                        cout<<endl;
                        Trc2 = next(Trc2);
                    }
                }else{
                    cout<<"     Dosen Mahasiswa Kosong"<<endl;
                }
                cout<<endl;
                cout<<"Kode Dosen                              : ";
                cin>>kode;
                cout<<"NIM Mahasiswa yang ingin Dibimbing      : ";
                cin>>nim;
                insertfirst(LR,R,P,Q,LD,LM,kode,nim);
                cout<<endl;
                cout<<"Apakah anda ingin lanjut penginputan ? (y/n) ";
                cin>>pilihan1;
            }
            break;
        }else if(jawaban == '0'){
            break;
        }
    }
}

void MenuView(ListDosen LD, List_mahasiswa LM, list_relasi LR){
    char jawaban;
    string nama;
    string kode;
    string nim;

    while(jawaban != '0'){
        system("CLS");
        cout<<"     Menu View       "<<endl;
        cout<<"1. Lihat Data Mahasiswa yang Dibimbing oleh Dosen X"<<endl;
        cout<<"2. Lihat Data Dosen yang Membimbing Mahasiswa X"<<endl;
        cout<<"3. Lihat seluruh Data Mahasiswa"<<endl;
        cout<<"4. Lihat Data Dosen yang memiliki bimbingan mahasiswa paling banyak"<<endl;
        cout<<"5. Lihat Data Dosen yang memiliki bimbingan mahasiswa paling sedikit"<<endl;
        cout<<"0. kembali"<<endl;
        cout<<"pilihan : ";
        cin>>jawaban;

        if(jawaban == '1'){
            system("CLS");
            cout<<"Kode Dosen          : ";
            cin>>kode;
            printInfo_M(LR,LD,kode);
            getch();
        }else if(jawaban == '2'){
            system("CLS");
            cout<<"NIM Mahasiswa           : ";
            cin>>nim;
            printInfo_D(LR,LM,nim);
            getch();
        }else if(jawaban == '3'){
            system("CLS");
            printInfo_semua(LD,LM,LR);
            getch();
        }else if(jawaban == '4'){
            system("CLS");
            printMaxDosen(LD);
            getch();
        }else if(jawaban == '5'){
            system("CLS");
            printMinDosen(LD);
            getch();
        }

    }
}

void MenuDelete(ListDosen &LD, List_mahasiswa &LM, list_relasi &LR){
    char jawaban;
    string kode,nim;
    string namaMhs,namaDsn;
    address_relasi adrR;
    adrDosen adrD;
    address_mahasiswa adrM;
    char pilihan,pilihan2;

    while(jawaban != '0'){
        system("CLS");
        cout<<"     Menu Delete     "<<endl;
        cout<<"1. Delete Data Dosen"<<endl;
        cout<<"2. Delete Data Mahasiswa"<<endl;
        cout<<"0. kembali"<<endl;
        cout<<"pilihan : ";
        cin>>jawaban;

        if(jawaban == '1'){
            pilihan2 = 'z';
            while(pilihan2 != 'n'){
                system("CLS");
                cout<<"Kode Dosen yang Ingin Dihapus    : ";
                cin>>kode;
                adrD = SearchDosen(LD,kode);
                if(adrD == NULL){
                    cout<<"Dosen Tidak Ditemukan"<<endl;
                }else{
                    cout<<"Apakah anda yakin ingin menghapus "<<info(adrD).nama<<"("<<info(adrD).kode<<")"<<" dari data Dosen ? (y/n) ";
                    cin>>pilihan;
                    if(pilihan == 'y'){
                        if(jml_mahasiswa(adrD) != 0){
                            deleteRelasiDosen(LR, adrR, kode);
                        }
                        deleteX(LD,adrD,kode);
                        cout<<endl;
                        cout<<"Data berhasil dihapus"<<endl;
                    }else{
                        cout<<"Pengahapusan Data Digagalkan"<<endl;
                    }
                }
            cout<<"apakah anda ingin lanjut penghapusan data ? (y/n) ";
            cin>>pilihan2;
            }
        }else if(jawaban == '2'){
            pilihan2 = 'z';
            while(pilihan2 != 'n'){
                system("CLS");
                cout<<"NIM yang Ingin Dihapus    : ";
                cin>>nim;
                adrM = Search_parent(LM,nim);
                if(adrM == NULL){
                    cout<<"Mahasiswa Tidak Ditemukan"<<endl;
                }else{
                    cout<<"Apakah anda yakin ingin menghapus "<<info_mahasiswa(adrM).namaMhs<<"("<<info_mahasiswa(adrM).NIM<<")"<<" dari data Mahasiswa ? (y/n) ";
                    cin>>pilihan;
                    if(pilihan == 'y'){
                        deleteRelasiMahasiswa(LR, adrR, nim);
                        deleteX(LM,adrM,nim);
                        cout<<endl;
                        cout<<"Data berhasil dihapus"<<endl;
                    }else{
                        cout<<"Pengahapusan Data Digagalkan"<<endl;
                    }
                }
                cout<<"apakah anda ingin lanjut penghapusan data ? (y/n) ";
                cin>>pilihan2;
            }
        }
    }
}


void Menu(){
    char jawaban;
    ListDosen LD;
    List_mahasiswa LM;
    list_relasi LR;
    jawaban = 1;

    createListDosen(LD);
    createlist(LM);
    createRelasi(LR);

    while(jawaban != '0'){
        system("CLS");
        cout<<"     Menu    "<<endl;
        cout<<"1. Tambah Data"<<endl;
        cout<<"2. View Data"<<endl;
        cout<<"3. Delete Data"<<endl;
        cout<<"0. Quit"<<endl;
        cout<<"pilihan : ";
        cin>>jawaban;


        if(jawaban == '1'){
            MenuInsert(LD,LM,LR);
        }else if(jawaban == '2'){
            MenuView(LD,LM,LR);
        }else if(jawaban == '3'){
            MenuDelete(LD,LM,LR);
        }else{
            break;
        }
    }
}
