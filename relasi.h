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

typedef struct RelasiElement *RelasiAddress;


struct RelasiElement {
    RelasiAddress nextr,prevr;
    KeretaAddress relasi_child;
    StasiunAddress relasi_parent;
};
struct RelasiList {
    RelasiAddress firstr,lastr;
};

void createListRelasi_4(RelasiList &L);
RelasiAddress createNewElmtRelasi_4();
void dealokasiRelasi_4(RelasiAddress &P);
void insertLastRelasi_4(RelasiList &L,RelasiAddress P);
void deleteFirstRelasi_4(RelasiList &L, RelasiAddress &P);
void deleteAfterRelasi_4(RelasiList &L,RelasiAddress &prec,RelasiAddress &P);
void deleteLastRelasi_4(RelasiList &L,RelasiAddress &P);
void deleteRelParent_4(RelasiList &Lr,StasiunList &Lp,KeretaList &Lc);
void showParentCocok_4(StasiunList L,string asal,string tujuan);
void hubungkan_4(RelasiList &L,KeretaList &Lc,StasiunList &Lp);
int countchild_4(RelasiList L,KeretaList Lc,StasiunList Lp,string id_stasiun);
int countparent_4(RelasiList L,KeretaList Lc,StasiunList Lp,string id_kereta);
int countnonchild_4(RelasiList L,KeretaList Lc,StasiunList Lp);
int countnonparent_4(RelasiList L,KeretaList Lc,StasiunList Lp);
void showchildrelasi_4(RelasiList L,StasiunList Lp,string id_stasiun);
void showparentrelasi_4(RelasiList L,KeretaList Lc,string id_kereta);
void editRelasitoPr_4(RelasiList &L,KeretaList &Lc,StasiunList &Lp);
void editRelasitoCh_4(RelasiList &L,KeretaList &Lc,StasiunList &Lp);
RelasiAddress findRelasi_4(RelasiList L,KeretaList Lc,StasiunList Lp,string id_stasiun);
void minpemberhentian_4(RelasiList &L,KeretaList &Lc,StasiunList &Lp,string id_stasiun);
void mintraffic_4(RelasiList &L,KeretaList &Lc,StasiunList &Lp,string id_kereta);


#endif // RELASI_H_INCLUDED
