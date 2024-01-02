#include <iostream>
#include "relasi.h"
#include "parent.h"
#include "child.h"
#include "utils.cpp"

using namespace std;

Utils utils;

void createListRelasi_4(RelasiList &L) {
    firstr(L) = NULL;
    lastr(L) = NULL;
}

RelasiAddress createNewElmtRelasi_4() {
    RelasiAddress P = new RelasiElement;
    P -> nextr = P;  // Menyambungkan P dengan dirinya sendiri
    prevr(P) = P;
    relasi_parent(P) = NULL;
    relasi_child(P) = NULL;
    return P;
}

void dealokasiRelasi_4(RelasiAddress &P) {
    delete P;
}

void insertLastRelasi_4(RelasiList &L, RelasiAddress P) {
    if (firstr(L) == NULL) {
        firstr(L) = P;
        lastr(L) = P;
    } else {
        nextr(P) = nextr(lastr(L));
        prevr(P) = lastr(L);
        prevr(firstr(L)) = P;
        nextr(lastr(L)) = P;
        lastr(L) = P;
    }
}

void deleteFirstRelasi_4(RelasiList &L, RelasiAddress &P) {
    if (firstr(L) == NULL) {
        cout<<"list kosong"<<endl;
    }else if (nextr(P) == P) {
        P = firstr(L);
        firstr(L) = NULL;
        lastr(L) = NULL;
    }else{
        firstr(L) = nextr(P);
        nextr(lastr(L)) = firstr(L);
        prevr(firstr(L))= lastr(L);
        nextr(P) = NULL;
        prevr(P) = NULL;
    }
}

void deleteAfterRelasi_4(RelasiList &L, RelasiAddress &P, RelasiAddress &prec) {
    P = nextr(prec);
    if (firstr(L) == NULL) {
        cout<<"list kosong"<<endl;
    }else if (P == lastr(L)) {
        lastr(L) = prec;
        nextr(lastr(L)) = firstr(L);
        prevr(firstr(L)) = lastr(L);
        nextr(P) = NULL;
        prevr(P) = NULL;
    }else{
        nextr(prec) = nextr(P);
        prevr(nextr(P)) = prec;
        nextr(P) = NULL;
        prevr(P) = NULL;
    }
}

void deleteLastRelasi_4(RelasiList &L, RelasiAddress &P) {
    RelasiAddress X = firstr(L);
    if (X == NULL) {
        cout<<"list kosong"<<endl;
    }else if ( X == lastr(L)) {
        P = lastr(L);
        firstr(L) = NULL;
        lastr(L) = NULL;
    }else {
        while (nextr(X) != lastr(L)) {
            X = nextr(X);
        }
        P = nextr(X);
        lastr(L) = X;
        nextr(X) = firstr(L);
        prevr(firstr(L)) = X;
        prevr(P) = NULL;
        nextr(P) = NULL;
    }
}

void deleteRelasi_4(RelasiList &L,RelasiAddress r){
    if (r == firstr(L)){
        deleteFirstRelasi_4(L,r);
    }else if(nextr(r)== NULL){
        deleteLastRelasi_4(L,r);
    }else{
        RelasiAddress q;
        q = firstr(L);
        while (nextr(q) != r){
            q = nextr(q);
        }
        deleteAfterRelasi_4(L,q,r);
    }
}

void deleteRelParent_4(RelasiList &Lr,StasiunList &Lp,KeretaList &Lc){
    string id_stasiun;
    RelasiAddress r;
    StasiunAddress p;
    showKodeStasiun_4(Lp);
    cout << "Hapus stasiun by ID : ";
    cin >>id_stasiun;
     r = findRelasi_4(Lr,Lc,Lp,id_stasiun);
        cout << r << endl;
     /* do {
        r = findRelasi_4(Lr,Lc,Lp,id_stasiun);
        cout << r << endl;
        if (r != NULL) {
            deleteRelasi_4(Lr,r);
        }
    } while (r != NULL);
    */

    deleteParent_4(Lp,p,id_stasiun);
}

void showParentCocok_4(StasiunList L,string asal,string tujuan){
    StasiunAddress x;
    x = firstpr(L);
    bool found = false;
    cout << "-data stasiun-" <<endl;
    while (x != NULL){
        if (infopr(x).kabkot == asal || infopr(x).kabkot == tujuan){
            cout << infopr(x).id <<endl;
            cout << infopr(x).nama << endl;
            cout <<infopr(x).kabkot<<endl;
            found = true;
        }
        x = nextpr(x);
    }
    if (found == false){
        cout<<"tidak ada yang cocok"<< endl;
    }
    cout << "---------" <<endl;
}

void hubungkan_4(RelasiList &L,KeretaList &Lc,StasiunList &Lp){
    StasiunAddress Y;
    KeretaAddress X;
    string id_kereta,id_stasiun;
    showkodekereta_4(Lc);
    cout <<" Pilih kereta by ID : " <<endl;
    cin >> id_kereta;
    X = searchKereta_4(Lc,id_kereta);
    if (X != NULL){
        showParentCocok_4(Lp,infoch(X).keberangkatan,infoch(X).tujuan);
        cout <<"Pilih Stasiun by ID : " <<endl;
        cin >> id_stasiun;
        Y = searchStasiun_4(Lp,id_stasiun);
    }else{
        cout <<"ID kereta salah"<<endl;
        utils.waitForNavigation();
    }
    if (Y == NULL) {
        cout <<"ID stasiun salah"<<endl;
        utils.waitForNavigation();
    }else{
        RelasiAddress P = createNewElmtRelasi_4();
        relasi_child(P) = X;
        relasi_parent(P) = Y;
        insertLastRelasi_4(L,P);
    }
}

RelasiAddress findRelasi_4(RelasiList L,KeretaList Lc,StasiunList Lp,string id_stasiun){
    RelasiAddress X;
    X = firstr(L);

    if (X != NULL) {
        do {
            if (infopr(relasi_parent(X)).id == id_stasiun && relasi_child(X) != NULL){
                return X;
            }
            else {
               X = nextr(X);
            }
        }while (X != firstr(L));

    }
    return X;
}

int countchild_4(RelasiList L,KeretaList Lc,StasiunList Lp,string id_stasiun){
    StasiunAddress X = searchStasiun_4(Lp,id_stasiun);
    RelasiAddress Y = firstr(L);
    int jml = 0;

    if (Y != NULL) {
        do {
            if (relasi_parent(Y) == X && relasi_child(Y) != NULL){
                jml++;
            }
            Y = nextr(Y);
        }while (Y != firstr(L));
    }

    return jml;
}

int countparent_4(RelasiList L,KeretaList Lc,StasiunList Lp,string id_kereta){
    KeretaAddress X = searchKereta_4(Lc,id_kereta);
    RelasiAddress Y = firstr(L);
    int jml = 0;

    if (Y != NULL) {
        do {
            if (relasi_child(Y) == X && relasi_parent(Y) != NULL){
                jml++;
            }
            Y = nextr(Y);
        }while (Y != firstr(L));
    }

    return jml;
}

int countnonchild_4(RelasiList L,KeretaList Lc,StasiunList Lp){
    StasiunAddress X;
    int jml = 0;
    X = firstpr(Lp);
    while (X != NULL){
        if (countchild_4(L,Lc,Lp,infopr(X).id)== 0){
            jml++;
        }
        X = nextpr(X);
    }
    return jml;
}

int countnonparent_4(RelasiList L,KeretaList Lc,StasiunList Lp){
    KeretaAddress X;
    int jml = 0;
    X = firstch(Lc);
    while (X != NULL){
        if (countparent_4(L,Lc,Lp,infoch(X).id)== 0){
            jml++;
        }
        X = nextch(X);
    }
    return jml;
}

void showchildrelasi_4(RelasiList L,StasiunList Lp,string id_stasiun){
    StasiunAddress X;
    X = searchStasiun_4(Lp,id_stasiun);
    RelasiAddress Y;
    Y = firstr(L);
    cout << "Kereta yang berelasi : " << endl;
    cout << "------------------------------" << endl;
    do {
        if (relasi_parent(Y) == X && relasi_child(Y) != NULL){
            cout << "ID : " <<infoch(relasi_child(Y)).id << endl;
            cout << "Nama : " <<infoch(relasi_child(Y)).nama << endl;
            cout << "Keberangkatan : " <<infoch(relasi_child(Y)).keberangkatan << endl;
            cout << "Tujuan : " <<infoch(relasi_child(Y)).tujuan << endl;
            cout << "Pemberhentian : " <<infoch(relasi_child(Y)).pemberhentian < endl;
        }
        Y = nextr(Y);
    }while (Y != firstr(L));
}

void showparentrelasi_4(RelasiList L,KeretaList Lc,string id_kereta){
    KeretaAddress X;
    X = searchKereta_4(Lc,id_kereta);
    RelasiAddress Y;
    Y = firstr(L);

    cout << "Stasiun yang berelasi : " << endl;
    cout << "------------------------------" << endl;
    do {
        if (relasi_child(Y) == X && relasi_parent(Y) != NULL){
            cout << "ID : " << infopr(relasi_parent(Y)).id << endl;
            cout << "Nama : " << infopr(relasi_parent(Y)).nama << endl;
            cout << "Kabkot : " << infopr(relasi_parent(Y)).kabkot << endl;
            cout << "Provinsi : " << infopr(relasi_parent(Y)).provinsi << endl;
            cout << "Traffic : " << infopr(relasi_parent(Y)).traffic << endl;
        }
        Y = nextr(Y);
    }while (Y != firstr(L));
}

void editRelasitoPr_4(RelasiList &L,KeretaList &Lc,StasiunList &Lp){
    string id_kereta,stasiun_awal,stasiun_pengganti;
    cout << "edit relasi" <<endl;
    showChild_4(Lc);
    cout <<"pilih kereta"<<endl;
    cin>>id_kereta;
    KeretaAddress x = searchKereta_4(Lc,id_kereta);

    if (x != NULL) {
        showparentrelasi_4(L,Lc,id_kereta);
        cout << "pilih stasiun untuk diubah" <<endl;
        StasiunAddress y = searchStasiun_4 (Lp,stasiun_awal);
        cin >> stasiun_awal;

        if (y != NULL) {
            showParent_4(Lp);
            cout <<"inputkan id stasiun baru"<<endl;
            cin >> stasiun_pengganti;
            StasiunAddress P = searchStasiun_4(Lp,stasiun_pengganti);

            if (P != NULL) {
                RelasiAddress R;
                R = firstr(L);
                do {
                    if (relasi_child(R) == x && relasi_parent(R) == y){
                        relasi_parent(R) = P;
                    }
                    R = nextr(R);
                } while (R != firstr(L));
            } else {
                cout << "Stasiun pengganti tidak ada" << endl;
                utils.waitForNavigation();
            }
        } else {
            cout << "Stasiun tidak ada" << endl;
            utils.waitForNavigation();
        }
    } else {
        cout << "Kereta tidak ada" << endl;
        utils.waitForNavigation();
    }
}

void editRelasitoCh_4(RelasiList &L,KeretaList &Lc,StasiunList &Lp){
    string id_stasiun,kereta_awal,kereta_pengganti;
    cout << "---edit relasi---" <<endl;
    showParent_4(Lp);
    cout <<"Pilih stasiun by ID : "<<endl;
    cin>>id_stasiun;
    showchildrelasi_4(L,Lp,id_stasiun);
    cout << "pilih kereta untuk diubah by ID : " <<endl;
    cin >> kereta_awal;
    showChild_4(Lc);
    cout <<"inputkan ID kereta baru : "<<endl;
    cin >> kereta_pengganti;
    StasiunAddress x = searchStasiun_4(Lp,id_stasiun);
    KeretaAddress y = searchKereta_4 (Lc,kereta_awal);
    KeretaAddress P = searchKereta_4(Lc,kereta_pengganti);
    RelasiAddress R;
    R = firstr(L);
    do {
        if (relasi_parent(R) == x && relasi_child(R) == y){
            relasi_child(R) = P;
        }
        R = nextr(R);
    }while (R != firstr(L));
}








