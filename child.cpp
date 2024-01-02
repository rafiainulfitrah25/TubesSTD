#include <iostream>
#include "child.h"
using namespace std;

bool isEmptyChild_4(KeretaList L){
    if (firstch(L) == NULL) {
        return true;
    }else {
        return false;
    }
}

void createListChild_4(KeretaList &L){
    firstch(L) = NULL;
    lastch(L) = NULL;
}

KeretaAddress createNewElmtChild_4(KeretaInfoType X){
    KeretaAddress P;
    P = new KeretaElement;
    infoch(P) = X;
    nextch(P) = NULL;
    prevch(P) = NULL;
    return P;
};

void insertLastChild_4(KeretaList &L, KeretaAddress P) {
    if (isEmptyChild_4(L) == true) {
        firstch(L) = P;
        lastch(L)= P;
    }else {
        prevch(P) = lastch(L);
        nextch(lastch(L)) = P;
        lastch(L) = P;
    }
}

void insertChild_4(KeretaList &L){
    KeretaInfoType data;
    cout<<"ID : "<<endl;
    cin>> data.id;
    cout<<"Nama : "<<endl;
    cin>> data.nama;
    cout<<"Keberangkatan : "<<endl;
    cin>> data.keberangkatan;
    cout<<"Tujuan : "<<endl;
    cin>> data.tujuan;
    data.pemberhentian = 0;
    KeretaAddress P = createNewElmtChild_4(data);
    insertLastChild_4(L,P);
}


void deletefirstChild_4(KeretaList &L,KeretaAddress &P){
    if (nextch(firstch(L)) == NULL) {
        P = firstch(L);
        firstch(L) = NULL;
        lastch(L) = NULL;
    }else{
        P = firstch(L);
        firstch(L)= nextch(P);
        nextch(P)= NULL;
        prevch(firstch(L)) = NULL;
    }
}

void deleteAfterChild_4(KeretaList &L,KeretaAddress prec, KeretaAddress &P){
    P = nextch(prec);
    nextch(prec)= nextch(P);
    prevch(nextch(P)) = prec;
    nextch(P) = NULL;
    prevch(P) = NULL;
}

void deleteLastChild_4(KeretaList &L,KeretaAddress &P){
    if (nextch(firstch(L)) == NULL) {
        P = firstch(L);
        firstch(L) = NULL;
        lastch(L) = NULL;
    }else{
        P = lastch(L);
        lastch(L)= prevch(P);
        nextch(lastch(L))= NULL;
        prevch(P) = NULL;
    }
}

void showChild_4(KeretaList L){
    KeretaAddress x;
    x = firstch(L);
    cout <<"---data kereta---"<<endl;
    while (x != NULL) {
        cout<< infoch(x).id<<endl;
        cout<< infoch(x).nama<<endl;
        cout<< infoch(x).keberangkatan<<endl;
        cout<< infoch(x).tujuan<<endl;
        cout<< infoch(x).pemberhentian<<endl;
        cout<<"-------------------"<<endl;
        x = nextch(x);
    }
}

void showkodekereta_4(KeretaList L){
    KeretaAddress x;
    x = firstch(L);
    cout <<"---data kereta---"<<endl;
    while (x != NULL) {
        cout<< infoch(x).id<<"||";
        cout<< infoch(x).nama<<endl;
        cout<<"-------------------"<<endl;
        x = nextch(x);
    }
}

KeretaAddress searchKereta_4(KeretaList L,string id_kereta) {
    KeretaAddress x;
    x = firstch(L);
    while (x != NULL){
        if (infoch(x).id == id_kereta) {
            return x;
        }else {
            x = nextch(x);
        }
    }
    return NULL;
}

void deleteChild_4(KeretaList &L,KeretaAddress &P,string id_kereta){
    KeretaAddress x;
    x = searchKereta_4(L,id_kereta);
    if (x== firstch(L)){
        deletefirstChild_4(L,P);
    }else if(nextch(x)== NULL){
        deleteLastChild_4(L,P);
    }else{
        KeretaAddress q;
        while (nextch(q) != x){
            q = nextch(q);
        }
        deleteAfterChild_4(L,P,q);
    }
}
