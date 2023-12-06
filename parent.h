#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
//SLL
#include <iostream>
#define Firstpr(L) L.Firstpr
#define nextpr(P) P->nextpr
#define infopr(P) P->infopr
using namespace std;

struct datastasiun {
    string nama;
    string kabkot;
    string provinsi;
    string traffic_status;
};

typedef datastasiun infotype_parent;
typedef struct elmt_parent *adr_parent;

struct elmt_parent{
    infotype_parent infopr;
    adr_parent nextpr;
};

struct list_parent {
    adr_parent Firstpr;
};

void createListParent_4(list_parent &L);
adr_parent createNewElmtParent_4(infotype_parent data);
void InsertLastParent_4(list_parent &L, adr_parent P);
void showLastParent_4(list_parent L,int K);
void deletefirstParent_4(list_parent &L,adr_parent &P);
void deletelastParent_4(list_parent &L, adr_parent &P);
void deleteafterParent_4(list_parent &L, adr_parent &P, adr_parent prec);




#endif // PARENT_H_INCLUDED

