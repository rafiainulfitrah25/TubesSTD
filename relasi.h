#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
//circular DLL
#include <iostream>
#include "parent.h"
#include "child.h"
#define firstr(L) L.firstr
#define lastr(L) L.lastr
#define nextr(P) P -> nextr
#define prevr(P) P -> prevr
#define infor(P) P -> infor
#define relasi_child(P) P -> relasi_child
#define relasi_parent(P) P -> relasi_parent
using namespace std;

typedef struct Elmt_relasi *adr_relasi;


struct Elmt_relasi {
    adr_relasi nextr,prevr;
    adr_child relasi_child;
    adr_parent relasi_parent;
};
struct list_relasi {
    adr_relasi firstr,lastr;
};

void createListRelasi_4(list_relasi &L);
void createNewElmtRelasi_4(adr_relasi &P);
void dealokasiRelasi_4(adr_relasi &P);
void insertLastRelasi_4(list_relasi &L,adr_relasi P);
void deleteFirstRelasi_4(list_relasi L, adr_relasi P);
void deleteAfterRelasi_4(list_relasi L,adr_relasi prec,adr_relasi P);
void deleteLastRelasi_4(list_relasi L,adr_relasi P);
adr_parent searchStasiun_4(list_parent L,string id_stasiun);
adr_child searchKereta_4(list_child LC,string id_kereta);
void showParentCocok_4(list_parent L,string asal,string tujuan);
void hubungkan_4(list_relasi &L,list_child &Lc,list_parent &Lp, adr_relasi P);
int countchild_4(list_relasi L,list_child Lc,list_parent Lp,string id_stasiun);
int countchild_4(list_relasi L,list_child Lc,list_parent Lp,string id_stasiun);





#endif // RELASI_H_INCLUDED
