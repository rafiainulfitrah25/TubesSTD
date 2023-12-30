#include <iostream>
#include "relasi.h"
#include "parent.h"
#include "child.h"

using namespace std;

void createListRelasi_4(list_relasi &L) {
    firstr(L) = NULL;
    lastr(L) = NULL;
}

adr_relasi createNewElmtRelasi_4() {
    adr_relasi P = new Elmt_relasi;
    P -> nextr = P;  // Menyambungkan P dengan dirinya sendiri
    prevr(P) = P;
    relasi_parent(P) = NULL;
    relasi_child(P) = NULL;
    return P;
}

void dealokasiRelasi_4(adr_relasi &P) {
    delete P;
}

void insertLastRelasi_4(list_relasi &L, adr_relasi P) {
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

void deleteFirstRelasi_4(list_relasi &L, adr_relasi &P) {
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

void deleteAfter_1301223470(list_relasi &L, adr_relasi &P, adr_relasi &prec) {
    P = next(prec);
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

void deleteLastRelasi_4(list_relasi &L, adr_relasi &P) {
    adr_relasi X = firstr(L);
    if (X == NULL) {
        cout<<"list kosong"<<endl;
    }else if ( X == lastr(L)) {
        P = lastr(L);
        firstr(L) = NULL;
        lastr(L) = NULL;
    }else {
        while (nextr(X) != lastr(L)) {
            X = next(X);
        }
        P = nextr(X);
        lastr(L) = X;
        nextr(X) = firstr(L);
        prevr(firstr(L)) = X;
        prevr(P) = NULL;
        nextr(P) = NULL;
    }
}

void deleterelasi_4(list_relasi &L,adr_relasi r){
    if (r== firstr(L)){
        deleteFirstRelasi_4(L,r);
    }else if(nextr(r)== NULL){
        deleteLastRelasi_4(L,r);
    }else{
        adr_relasi q;
        q = firstr(L);
        while (nextr(q) != r){
            q = nextr(q);
        }
        deleteAfterRelasi_4(L,q,r);
    }
}

void deleterelparent_4(list_relasi &Lr,list_parent &Lp,list_child &Lc){
    string id_stasiun;
    adr_relasi r;
    adr_parent p;
    showkodestasiun_4(Lp);
    cout<<"pIlih yang dihapus"<<endl;
    cin >>id_stasiun;
    r =findRelasi_4(Lr,Lc,Lp,id_stasiun);
    deleterelasi_4(Lr,r);
    deleteParent_4(Lp,p,id_stasiun)
}

void showParentCocok_4(list_parent L,string asal,string tujuan){
    adr_parent x;
    x = Firstpr(L);
    bool found = false;
    cout << "-data stasiun-" <<endl;
    while (x != NULL){
        if (infopr(x).kabkot == asal || infopr(x).kabkot == tujuan){
            cout << infopr(x).id_stasiun <<endl;
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

void hubungkan_4(list_relasi &L,list_child &Lc,list_parent &Lp, adr_relasi P){
    adr_parent Y;
    adr_child X;
    string id_kereta,id_stasiun;
    showkodekereta_4(Lc);
    cout <<" pilih kereta :" <<endl;
    cin >> id_kereta;
    X = searchKereta_4(Lc,id_kereta);
    if (X != NULL){
        showParentCocok_4(Lp,infoch(X).asal_perjalanan,infoch(X).tujuan_perjalanan);
        cout <<"pilih Stasiun :" <<endl;
        cin >> id_stasiun;
        Y = searchStasiun_4(Lp,id_stasiun);
    }else{
        cout <<"id kereta salah"<<endl;
    }
    if (Y == NULL) {
        cout <<"id stasiun salah"<<endl;
    }else{
        P = createNewElmtRelasi_4();
        relasi_child(P) = X;
        relasi_parent(P) = Y;
        insertLastRelasi_4(L,P);
    }
}

bool findRelasi_4(list_relasi L,list_child Lc,list_parent Lp,string id_stasiun){
    adr_relasi X;
    X = firstr(L);
    do {
        if (infopr(relasi_parent(X)).id_stasiun == id_stasiun && relasi_child(X) != NULL){
            return true;
        }
        else {
           X = nextr(X);
        }
    }while (X != firstr(L));
    return false;
}

int countchild_4(list_relasi L,list_child Lc,list_parent Lp,string id_stasiun){
    adr_parent X;
    X = searchStasiun_4(Lp,id_stasiun);
    adr_relasi Y;
    Y = firstr(L);
    int jml = 0;
    do {
        if (relasi_parent(Y) == X && relasi_child(Y) != NULL){
            jml++;
        }
        Y = next(Y);
    }while (Y != firstr(L));
    return jml;
}

int countparent_4(list_relasi L,list_child Lc,list_parent Lp,string id_kereta){
    adr_child X;
    X = searchKereta_4(Lc,id_kereta);
    adr_relasi Y;
    Y = firstr(L);
    int jml = 0;
    do {
        if (relasi_child(Y) == X && relasi_parent(Y) != NULL){
            jml++;
        }
        Y = next(Y);
    }while (Y != firstr(L));
    return jml;
}

int countnonchild_4(list_relasi L,list_child Lc,list_parent Lp){
    adr_parent X;
    int jml = 0;
    X = Firstpr(Lp);
    while (X != NULL){
        if (countchild_4(L,Lc,Lp,infopr(X).id_stasiun)== 0){
            jml++;
        }
        X = nextpr(X);
    }
    return jml;
}

int countnonparent_4(list_relasi L,list_child Lc,list_parent Lp){
    adr_child X;
    int jml = 0;
    X = firstch(Lc);
    while (X != NULL){
        if (countparent_4(L,Lc,Lp,infoch(X).id_kereta)== 0){
            jml++;
        }
        X = nextch(X);
    }
    return jml;
}

void showchildrelasi_4(list_relasi L,list_parent Lp,string id_stasiun){
    adr_parent X;
    X = searchStasiun_4(Lp,id_stasiun);
    adr_relasi Y;
    Y = firstr(L);
    do {
        if (relasi_parent(Y) == X && relasi_child(Y) != NULL){
            cout<<infoch(relasi_child(Y)).id_kereta;
        }
        Y = nextr(Y);
    }while (Y != firstr(L));
}

void showparentrelasi_4(list_relasi L,list_child Lc,string id_kereta){
    adr_child X;
    X = searchKereta_4(Lc,id_kereta);
    adr_relasi Y;
    Y = firstr(L);
    do {
        if (relasi_child(Y) == X && relasi_parent(Y) != NULL){
            cout<<infopr(relasi_parent(Y)).id_stasiun;
        }
        Y = nextr(Y);
    }while (Y != firstr(L));
}

void editRelasitoPr_4(list_relasi &L,list_child &Lc,list_parent &Lp){
    string id_kereta,stasiun_awal,stasiun_pengganti;
    cout << "edit relasi" <<endl;
    showChild_4(Lc);
    cout <<"pilih kereta"<<endl;
    cin>>id_kereta;
    showparentrelasi_4(L,Lc,id_kereta);
    cout << "pilih stasiun untuk diubah" <<endl;
    cin >> stasiun_awal;
    showParent_4(Lp);
    cout <<"inputkan id stasiun baru"<<endl;
    cin >> stasiun_pengganti;
    adr_child x = searchKereta_4(Lc,id_kereta);
    adr_parent y = searchStasiun_4 (Lp,stasiun_awal);
    adr_parent P = searchStasiun_4(Lp,stasiun_pengganti);
    adr_relasi R;
    R = firstr(L);
    do {
        if (relasi_child(R) == x && relasi_parent(R) == y){
            relasi_parent(R) = P;
        }
        R = nextr(R);
    }while (R != firstr(L));
}

void editRelasitoCh_4(list_relasi &L,list_child &Lc,list_parent &Lp){
    string id_stasiun,kereta_awal,kereta_pengganti;
    cout << "edit relasi" <<endl;
    showParent_4(Lp);
    cout <<"pilih stasiun"<<endl;
    cin>>id_stasiun;
    showchildrelasi_4(L,Lp,id_stasiun);
    cout << "pilih kereta untuk diubah" <<endl;
    cin >> kereta_awal;
    showChild_4(Lc);
    cout <<"inputkan id kereta baru"<<endl;
    cin >> kereta_pengganti;
    adr_parent x = searchStasiun_4(Lp,id_stasiun);
    adr_child y = searchKereta_4 (Lc,kereta_awal);
    adr_child P = searchKereta_4(Lc,kereta_pengganti);
    adr_relasi R;
    R = firstr(L);
    do {
        if (relasi_parent(R) == x && relasi_child(R) == y){
            relasi_child(R) = P;
        }
        R = nextr(R);
    }while (R != firstr(L));
}








