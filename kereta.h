#ifndef KERETA_H_INCLUDED
#define KERETA_H_INCLUDED

using namespace std;

struct Kereta {
    string id;
    string nama;
    string keberangkatan;
    string tujuan;
};

typedef Kereta KeretaInfoType;
typedef struct KeretaElement *KeretaAddress;

struct KeretaElement {
    KeretaInfoType info;
    KeretaAddress next;
    KeretaAddress prev;
};

struct KeretaList {
    KeretaAddress first;
    KeretaAddress last;
};

void createKeretaList(KeretaList &keretaList);
KeretaAddress createKeretaElement(KeretaInfoType data);

bool isEmptyChild_4(KeretaList keretaList);

// B
void insertLastKereta(KeretaList &keretaList, KeretaAddress p);


// K
void findAllKereta(KeretaList keretaList);
// H
KeretaAddress findKeretaById(KeretaList keretaList, string id);

// E
void deleteFirstStasiun(KeretaList &keretaList, KeretaAddress &P);
void deleteLastStasiun(KeretaList &keretaList, KeretaAddress &P);
void deleteAfterStasiun(KeretaList &keretaList, KeretaAddress &P, KeretaAddress prec);
void deleteStasiunById(KeretaList &keretaList, KeretaAddress &P, string id);

#endif // KERETA_H_INCLUDED
