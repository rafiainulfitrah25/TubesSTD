#include <iostream>
#include "relasi.h"
using namespace std;

void createListRelasi_4(list_relasi &L) {
    firstr(L) = NULL;
    lastr(L) = NULL;
}

void createNewElmtRelasi_4(adr_relasi &P) {
    P = new Elmt_relasi;
    nextr(P) = P;  // Menyambungkan P dengan dirinya sendiri
    prevr(P) = P;
}

void dealokasiRelasi_4(adr_relasi &P) {
    delete P;
}

/*
void insertFirst_1301223470(List &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        next(last(L)) = P;
        first(L) = P;
    }
}
*/
/*
void insertAfter_1301223470(List &L, address prec, address P) {
    next(P) = next(prec);
    next(prec) = P;
    if (prec == last(L)) {
        last(L) = P;
    }
}
*/

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

/*
address findElm_1301223470(List L, infotype x) {
    if (first(L) == NULL) {
        return NULL;
    }
    address P = first(L);
    do {
        if (info(P) == x) {
            return P;
        }
        P = next(P);
    } while (P != first(L));
    return NULL;
}
*/

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
