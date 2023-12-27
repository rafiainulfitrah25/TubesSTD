#include <iostream>
#include "kereta.h"

using namespace std;

void createKeretaList(KeretaList &keretaList) {
    keretaList.first = NULL;
    keretaList.last = NULL;
}

KeretaAddress createKeretaElement(KeretaInfoType data) {
    KeretaAddress p;
    p = new KeretaElement;
    p->info = data;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

bool isEmptyChild_4(KeretaList keretaList) {
    return keretaList.first == NULL;
}

void insertLastKereta(KeretaList &keretaList, KeretaAddress p) {
    KeretaAddress i;

    if (keretaList.first == NULL) {
        keretaList.first = p;
        keretaList.last = p;
    } else {
        p->prev = keretaList.last;
        keretaList.last->next = p;
        keretaList.last = p;
    }
}

void findAllKereta(KeretaList keretaList) {
    KeretaAddress i = keretaList.first;

    cout << "----------- Data Kereta -----------" << endl;
    if (i == NULL) {
        cout << "Zero (0) Record" << endl;
    }
    while (i != NULL) {
        cout << "ID : " << i->info.id << endl;
        cout << "Nama : " << i->info.nama << endl;
        cout << "Keberangkatan : " << i->info.keberangkatan << endl;
        cout << "Tujuan : " << i->info.tujuan << endl;
        cout << "----------------------------" << endl;

        i = i->next;
    }
}

KeretaAddress findKeretaById(KeretaList keretaList, string id) {
    KeretaAddress i = keretaList.first;

    while (i != NULL) {
        if (i->info.id == id) {
            return i;
        } else {
            i = i->next;
        }

        return NULL;
    }
}

void deleteFirstKereta(KeretaList &keretaList, KeretaAddress &P) {
     if (keretaList.first == NULL) {
        P = keretaList.first;
        keretaList.first = NULL;
        keretaList.last = NULL;
    }else{
        P = keretaList.first;
        keretaList.first= P->next;
        P->next= NULL;
        keretaList.first->prev = NULL;
    }
}

void deleteLastKereta(KeretaList &keretaList, KeretaAddress &P) {
    if (keretaList.first->next == NULL) {
        P = keretaList.first;
        keretaList.first = NULL;
        keretaList.last = NULL;
    }else{
        P = keretaList.last;
        keretaList.last = P->prev;
        keretaList.last->next = NULL;
        P->prev = NULL;
    }
}

void deleteAfterKereta(KeretaList &keretaList, KeretaAddress &P, KeretaAddress prec) {
    P = prec->next;
    prec->next = P->next;
    P->next->prev = prec;
    P->next = NULL;
    P->prev = NULL;
}


void deleteKeretaById(KeretaList &keretaList, KeretaAddress &P, string id) {
    KeretaAddress deletedAddress = findKeretaById(keretaList, id);

    if (deletedAddress = keretaList.first) {
        deleteFirstKereta(keretaList, deletedAddress);
    } else if (deletedAddress->next == NULL) {
        deleteLastKereta(keretaList, deletedAddress);
    } else {
        KeretaAddress i = keretaList.first;

        while (i->next != deletedAddress) {
            i = i->next;
        }

        deleteAfterKereta(keretaList, deletedAddress, i);
    }
}
