#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED
//DLL
#include <iostream>
#define firstch(L) L.firstch
#define lastch(L) L.lastch
#define prevch(P) P -> prevch
#define nextch(P) P -> nextch
#define infoch(P) P -> infoch
using namespace std;

struct Kereta {
    string id;
    string nama;
    string keberangkatan;
    string tujuan;
    int pemberhentian;
};

typedef Kereta KeretaInfoType;
typedef struct KeretaElement *KeretaAddress;

struct KeretaElement {
    KeretaInfoType infoch;
    KeretaAddress nextch;
    KeretaAddress prevch;
};

struct KeretaList {
    KeretaAddress firstch,lastch;
};

bool isEmptyChild_4(KeretaList L);
void createListChild_4(KeretaList &L);
KeretaAddress createNewElmtChild_4(KeretaInfoType X);
void insertFirstChild_4(KeretaList &L, KeretaAddress P);
void insertChild_4(KeretaList &L);
void deletefirstChild_4(KeretaList &L,KeretaAddress &P);
void deleteAfterChild_4(KeretaList &L,KeretaAddress prec, KeretaAddress &P);
void deleteLastChild_4(KeretaList &L,KeretaAddress &P);
void showChild_4(KeretaList L);
void showkodekereta_4(KeretaList L);
KeretaAddress searchKereta_4(KeretaList L,string id_kereta);
void deleteChild_4(KeretaList &L,KeretaAddress &P,string id_kereta);

#endif // CHILD_H_INCLUDED
