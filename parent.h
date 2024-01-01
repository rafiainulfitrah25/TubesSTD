#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
//SLL
#include <iostream>
#define firstpr(L) L.firstpr
#define nextpr(P) P->nextpr
#define infopr(P) P->infopr
using namespace std;

struct Stasiun {
    string id;
    string nama;
    string kabkot;
    string provinsi;
    int traffic;
};

typedef Stasiun StasiunInfoType;
typedef struct StasiunElement *StasiunAddress;

struct StasiunElement{
    StasiunInfoType infopr;
    StasiunAddress nextpr;
};

struct StasiunList {
    StasiunAddress firstpr;
};

void createListParent_4(StasiunList &L);
StasiunAddress createNewElmtParent_4(StasiunInfoType data);
void InsertLastParent_4(StasiunList &L, StasiunAddress P);
void insertParent_4(StasiunList &L);
void showLastParent_4(StasiunList L,int K);
void deletefirstParent_4(StasiunList &L,StasiunAddress &P);
void deletelastParent_4(StasiunList &L, StasiunAddress &P);
void deleteafterParent_4(StasiunList &L, StasiunAddress &P, StasiunAddress prec);
StasiunAddress searchStasiun_4(StasiunList L,string id);
void deleteParent_4(StasiunList &L,StasiunAddress &P,string id);
void showParent_4(StasiunList L);
void showKodeStasiun_4(StasiunList L);


#endif // PARENT_H_INCLUDED
