#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "stasiun.h"
#include "kereta.h"

using namespace std;

typedef struct RelasiElement *RelasiAddress;

struct RelasiElement {
    RelasiAddress next, prev;
    KeretaAddress relKereta;
    StasiunAddress relStasiun;
};

struct RelasiList {
    RelasiAddress first, last;
};

void createRelasiList(RelasiList &relasiList);
RelasiAddress createRelasiElement();
void dealokasiRelasi(RelasiAddress &P);
void connect()

//
void insertLastRelasi(RelasiList &relasiList, RelasiAddress P);

//
void findAll

//
void deleteFirstRelasi(RelasiList &RelasiList, RelasiAddress P);
void deleteLastRelasi(RelasiList &RelasiList, RelasiAddress P);
void deleteAfterRelasi(RelasiList &RelasiList, RelasiAddress P, RelasiAddress prec);


#endif // RELASI_H_INCLUDED
