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

struct datakereta {
    string nama_kereta;
    string relasi_perjalanan;
    int kapasitas_kereta;
};

typedef datakereta infotype_child;
typedef struct elmt_child *adr_child;

struct elmt_child {
    infotype_child infoch;
    adr_child nextch;
    adr_child prevch;
};

struct list_child {
    adr_child firstch,lastch;
};

bool isEmptyChild_4(list_child L);
void createListChild_4(list_child &L);
adr_child createNewElmtChild_4(infotype_child X);
void showChild_4(list_child L);
void insertFirstChild_4(list_child &L, adr_child P);
void insertAfterChild_4( list_child &L,adr_child prec, adr_child P);
void insertLastChild_4(list_child &L, adr_child P);
void deletefirstChild_4(list_child &L,adr_child &P);
void DeleteAfterChild_4(list_child &L,adr_child prec, adr_child &P);
void deleteLastChild_4(list_child &L,adr_child &P);

#endif // CHILD_H_INCLUDED
