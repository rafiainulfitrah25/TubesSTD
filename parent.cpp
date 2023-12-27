#include <iostream>
#include "parent.h"
using namespace std;

void createListParent_4(list_parent &L){
    Firstpr(L) = NULL;
};

adr_parent createNewElmtParent_4(infotype_parent data){
    adr_parent P;
    P = new elmt_parent;
    infopr(P) = data;
    nextpr(P) = NULL;
    return P;
};

void InsertLastParent_4(list_parent &L, adr_parent P){
    adr_parent q;
    if ( Firstpr(L) == NULL) {
        Firstpr(L) = P;
    }else{
        q = Firstpr(L);
        while (nextpr(q) != NULL) {
        q = nextpr(q);
        }
        nextpr(q) = P;
    }
};

void insertparent_4(list_parent &L){
    infotype_parent data;
    cout<<"masukan id stasiun"<<endl;
    cin>> data.id_stasiun;
    cout<<"masukan kabupaten/kota stasiun"<<endl;
    cin>> data.kabkot;
    cout<<"masukan nama stasiun"<<endl;
    cin>> data.nama;
    cout<<"masukan provinsi stasiun"<<endl;
    cin>> data.provinsi;
    data.traffic_status = 0;
    adr_parent P = createNewElmtParent_4(data);
    InsertLastParent_4(L,P);
}

void showParent_4(list_parent L){
    adr_parent x;
    x = Firstpr(L);
    while (x != NULL) {
        cout <<"---data all stasiun---"<<endl;
        cout<< infopr(x).id_stasiun<<endl;
        cout<< infopr(x).nama<<endl;
        cout<< infopr(x).kabkot<<endl;
        cout<< infopr(x).provinsi<<endl;
        cout<< infopr(x).traffic_status<<endl;
        cout<<"-------------------"<<endl;
        x = nextpr(x);
    }
}


void deletefirstParent_4(list_parent &L,adr_parent &P){
    if (Firstpr(L)!= NULL){
        P = Firstpr(L);
        Firstpr(L) = nextpr(P);
        nextpr(P) = NULL;
    }else{
        cout<<"list kosong"<<endl;
    }
}

void deletelastParent_4(list_parent &L, adr_parent &P){
    adr_parent Q;
    if (Firstpr(L)== NULL){
        cout<<"list kosong"<<endl;
    }else if(next(Firstpr(L))== NULL){
        deletefirstParent_4(L,P);
    }else{
        Q = Firstpr(L);
        while (nextpr(nextpr(Q)) != NULL){
            Q = nextpr(Q);
        }
        P = nextpr(Q);
        nextpr(Q) = NULL;
    }
}

void deleteafterParent_4(list_parent &L, adr_parent &P, adr_parent prec){
    if (Firstpr(L)!= NULL){
        P = nextpr(prec);
        nextpr(prec) = nextpr(P);
        nextpr(P) = NULL;
    }else{
        cout<<"list kosong"<<endl;
    }
}

adr_parent searchStasiun_4(list_parent L,string id_stasiun) {
    adr_parent x;
    x = Firstpr(L);
    while (x != NULL){
        if (infopr(x).id_stasiun == id_stasiun) {
            return x;
        }else {
            x = next(x);
        }
        return NULL;
    }
}

void deleteParent_4(list_parent &L,adr_parent &P,string id_stasiun){
    adr_parent x;
    x = searchStasiun_4(L,id_stasiun);
    if (x== Firstpr(L)){
        deletefirstParent_4(L,P);
    }else if(nextpr(x)== NULL){
        deletelastParent_4(L,P);
    }else{
        adr_parent q;
        while (nextpr(q) != x){
            q = nextpr(q);
        }
        deleteafterParent_4(L,P,q);
    }
}


