#include <iostream>
#include "relasi.h"
#include "parent.h"
#include "child.h"

using namespace std;

void createListRelasi_4(list_relasi &L) {
    firstr(L) = NULL;
    lastr(L) = NULL;
}

void createNewElmtRelasi_4(adr_relasi &P) {
    adr_relasi P;
    P = new Elmt_relasi;
    nextr(P) = P;  // Menyambungkan P dengan dirinya sendiri
    prevr(P) = P;
    relasi_parent(P) = NULL;
    relasi_child(P) = NULL;
}

void dealokasiRelasi_4(adr_relasi &P) {
    delete P;
}





void insertLastRelasi_4(list_relasi &L,list_child Lc,list_parent Lp, adr_relasi P,string kode_kereta, string kode_stasiun) {
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


adr_child searchKereta_4(list_child L,string id_kereta) {
    adr_child x;
    x = firstch(L);
    while (x != NULL){
        if (info(x).id_kereta == id_kereta) {
            return x;
        }else {
            x = next(x);
        }
        return NULL;
    }
}

adr_parent searchParent_4(list_parent L,string id_stasiun) {
    adr_parent x;
    x = firstpr(L);
    while (x != NULL){
        if (info(x).id_stasiun == id_stasiun) {
            return x;
        }else {
            x = next(x);
        }
        return NULL;
    }
}

void hubungkan_4(list_relasi &L,list_child &Lc,list_parent &Lp, adr_relasi P){
    createNewElmtRelasi_4(P);
    adr_parent Y;
    adr_child X;
    //print info kereta
    //input id kereta
    X = searchKereta_4(Lc,id_kereta);
    //show info stasiun sesuai
    //input id stasiun
    Y = searchStasiun_4(Lp,id_stasiun);
    if (Y == NULL) {
        cout <<"id stasiun salah"<<endl;
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
