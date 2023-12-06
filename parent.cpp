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

void showLastParent_4(list_parent L,int K){
    adr_parent P = Firstpr(L);
    int totlist = 0;
    int index;
    while (nextpr(P) != NULL) {
        totlist++;
        P = nextpr(P);
    }
    index = totlist-(K-1);
    P = Firstpr(L);
    for (int i = 1; i <= index; i++) {
            P= nextpr(P);
    }
    cout<<infopr(P).nama<<endl;
    cout<<infopr(P).kabkot<<endl;
    cout<<infopr(P).provinsi<<endl;
};

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
