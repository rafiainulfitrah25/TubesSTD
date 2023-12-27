#include <iostream>
#include "stasiun.h"

using namespace std;

void createStasiunList(StasiunList &stasiunList) {
    stasiunList.first = NULL;
}

StasiunAddress createStasiunElement(StasiunInfoType data) {
    StasiunAddress p;
    p = new StasiunElement;
    p->info = data;
    p->next = NULL;
    return p;
}

void insertLastStasiun(StasiunList &stasiunList, StasiunAddress p) {
    StasiunAddress i;

    if (stasiunList.first == NULL) {
        stasiunList.first = p;
    } else {
        i = stasiunList.first;
        while (i->next != NULL) {
            i = i->next;
        }

        i->next = p;
    }
}

void findAllStasiun(StasiunList stasiunList) {
    StasiunAddress i = stasiunList.first;

    cout << "----------- Data Stasiun -----------" << endl;
    if (i == NULL) {
        cout << "Zero (0) Record" << endl;
    }
    while (i != NULL) {
        cout << "ID : " << i->info.id << endl;
        cout << "Nama : " << i->info.nama << endl;
        cout << "Kabkot : " << i->info.kabkot << endl;
        cout << "Provinsi : " << i->info.provinsi << endl;
        cout << "Traffic : " << i->info.traffic << endl;
        cout << "----------------------------" << endl;

        i = i->next;
    }
}

StasiunAddress findStasiunById(StasiunList stasiunList, string id) {
    StasiunAddress i;

    i = stasiunList.first;

    while (i != NULL) {
        if (i->info.id == id) {
            return i;
        } else {
            i = i->next;
        }

        return NULL;
    }
}

void deleteFirstStasiun(StasiunList &stasiunList, StasiunAddress &P) {
    if (stasiunList.first == NULL) {
        cout << "EMPTY LIST" << endl;
    } else {
        P = stasiunList.first;
        stasiunList.first = P->next;
        P->next = NULL;
    }
}

void deleteLastStasiun(StasiunList &stasiunList, StasiunAddress &P) {
    if (stasiunList.first == NULL) {
        cout << "EMPTY LIST" << endl;
    } else {
        StasiunAddress i = stasiunList.first;

        while (i->next->next != NULL) {
            i = i->next;
        }

        P = i->next;
        i->next = NULL;
    }
}

void deleteAfterStasiun(StasiunList &stasiunList, StasiunAddress &P, StasiunAddress prec) {
    if (stasiunList.first == NULL) {
        cout << "EMPTY LIST" << endl;
    } else {
        P = prec->next;
        prec->next = P->next;
        P->next = NULL;
    }
}


void deleteStasiunById(StasiunList &stasiunList, StasiunAddress &P, string id) {
    StasiunAddress deletedAddress = findStasiunById(stasiunList, id);

    if (deletedAddress = stasiunList.first) {
        deleteFirstStasiun(stasiunList, deletedAddress);
    } else if (deletedAddress->next == NULL) {
        deleteLastStasiun(stasiunList, deletedAddress);
    } else {
        StasiunAddress i = stasiunList.first;

        while (i->next != deletedAddress) {
            i = i->next;
        }

        deleteAfterStasiun(stasiunList, deletedAddress, i);
    }
}
