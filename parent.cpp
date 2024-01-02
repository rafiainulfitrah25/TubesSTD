#include <iostream>
#include "parent.h"
using namespace std;

void createListParent_4(StasiunList &L){
    firstpr(L) = NULL;
};

StasiunAddress createNewElmtParent_4(StasiunInfoType data){
    StasiunAddress P;
    P = new StasiunElement;
    infopr(P) = data;
    nextpr(P) = NULL;
    return P;
};

void InsertLastParent_4(StasiunList &L, StasiunAddress P){
    StasiunAddress q;
    if ( firstpr(L) == NULL) {
        firstpr(L) = P;
    }else{
        q = firstpr(L);
        while (nextpr(q) != NULL) {
        q = nextpr(q);
        }
        nextpr(q) = P;
    }
};

void insertParent_4(StasiunList &L){
    StasiunInfoType data;
    cout<<"ID : "<<endl;
    cin>> data.id;
    cout<<"Nama : "<<endl;
    cin>> data.nama;
    cout<<"Kabkot : "<<endl;
    cin>> data.kabkot;
    cout<<"Provinsi : "<<endl;
    cin>> data.provinsi;
    data.traffic = 0;
    StasiunAddress P = createNewElmtParent_4(data);
    InsertLastParent_4(L,P);
}

void showParent_4(StasiunList L){
    StasiunAddress x;
    x = firstpr(L);
        cout <<"---data all stasiun---"<<endl;
    while (x != NULL) {
        cout<< infopr(x).id<<endl;
        cout<< infopr(x).nama<<endl;
        cout<< infopr(x).kabkot<<endl;
        cout<< infopr(x).provinsi<<endl;
        cout<< infopr(x).traffic<<endl;
        cout<<"-------------------"<<endl;
        x = nextpr(x);
    }
}

void showKodeStasiun_4(StasiunList L){
    StasiunAddress x;
    x = firstpr(L);
        cout <<"---data all stasiun---"<<endl;
    while (x != NULL) {
        cout<< infopr(x).id<<endl;
        cout<< infopr(x).nama<<endl;
        cout<<"-------------------"<<endl;
        x = nextpr(x);
    }
}

void deletefirstParent_4(StasiunList &L,StasiunAddress &P){
    if (firstpr(L)!= NULL){
        P = firstpr(L);
        firstpr(L) = nextpr(P);
        nextpr(P) = NULL;
    }else{
        cout<<"list kosong"<<endl;
    }
}

void deletelastParent_4(StasiunList &L, StasiunAddress &P){
    StasiunAddress Q;
    if (firstpr(L)== NULL){
        cout<<"list kosong"<<endl;
    }else if(nextpr(firstpr(L))== NULL){
        deletefirstParent_4(L,P);
    }else{
        Q = firstpr(L);
        while (nextpr(nextpr(Q)) != NULL){
            Q = nextpr(Q);
        }
        P = nextpr(Q);
        nextpr(Q) = NULL;
    }
}

void deleteafterParent_4(StasiunList &L, StasiunAddress &P, StasiunAddress prec){
    if (firstpr(L)!= NULL){
        P = nextpr(prec);
        nextpr(prec) = nextpr(P);
        nextpr(P) = NULL;
    }else{
        cout<<"list kosong"<<endl;
    }
}

StasiunAddress searchStasiun_4(StasiunList L,string id_stasiun) {
    StasiunAddress x;
    x = firstpr(L);
    while (x != NULL){
        if (infopr(x).id == id_stasiun) {
            return x;
        }else {
            x = nextpr(x);
        }
    }
    return NULL;
}

void deleteParent_4(StasiunList &L,StasiunAddress &P,string id_stasiun){
    StasiunAddress x;
    x = searchStasiun_4(L,id_stasiun);
    if (x== firstpr(L)){
        deletefirstParent_4(L,P);
    }else if(nextpr(x)== NULL){
        deletelastParent_4(L,P);
    }else{
        StasiunAddress q;
        while (nextpr(q) != x){
            q = nextpr(q);
        }
        deleteafterParent_4(L,P,q);
    }
}


