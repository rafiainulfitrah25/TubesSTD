#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
//circular DLL
#include <iostream>
#define firstr(L) L.firstr
#define lastr(L) L.lastr
#define nextr(P) P -> nextr
#define prevr(P) P -> prevr
#define infor(P) P -> infor
using namespace std;

typedef struct Elmt_relasi *adr_relasi;
struct Elmt_relasi {
    adr_relasi nextr,prevr;
};
struct list_relasi {
    adr_relasi firstr,lastr;
};

void createListRelasi_4(list_relasi &L);
void createNewElmtRelasi_4(adr_relasi &P);
void dealokasiRelasi_4(adr_relasi &P);
//void insertFirstRelasi_4(List &L,address P);
//void insertAfterRelasi_4(List &L,address prec,address P);
void insertLastRelasi_4(list_relasi &L,adr_relasi P);
//void findElmRelasi_4(List L,infotype x);
void deleteFirstRelasi_4(list_relasi L, adr_relasi P);
void deleteAfterRelasi_4(list_relasi L,adr_relasi prec,adr_relasi P);
void deleteLastRelasi_4(list_relasi L,adr_relasi P);







#endif // RELASI_H_INCLUDED
