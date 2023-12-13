#include <iostream>
#include "child.h"
using namespace std;

bool isEmptyChild_4(list_child L){
    if (firstch(L) == NULL) {
        return true;
    }else {
        return false;
    }
}

void createListChild_4(list_child &L){
    firstch(L) = NULL;
    lastch(L) = NULL;
}

adr_child createNewElmtChild_4(infotype_child X){
    adr_child P;
    P = new elmt_child;
    infoch(P) = X;
    nextch(P) = NULL;
    prevch(P) = NULL;
    return P;
};

void insertFirstChild_4(list_child &L, adr_child P){
    if (isEmptyChild_4(L) == true) {
        firstch(L) = P;
        lastch(L)= P;
    }else {
        nextch(P) = firstch(L);
        prevch(firstch(L)) = P;
        firstch(L) = P;
    }

}

void insertAfterChild_4( list_child &L,adr_child prec, adr_child P){
    nextch(P) = nextch(prec);
    prevch(P) = prec;
    nextch(prec) = P;
    prevch(nextch(P)) = P;
}

void insertLastChild_4(list_child &L, adr_child P) {
    if (isEmptyChild_4(L) == true) {
        firstch(L) = P;
        lastch(L)= P;
    }else {
        prevch(P) = lastch(L);
        nextch(lastch(L)) = P;
        lastch(L) = P;
    }
}

void deletefirstChild_4(list_child &L,adr_child &P){
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

void DeleteAfterChild_4(list_child &L,adr_child prec, adr_child &P){
    P = nextch(prec);
    nextch(prec)= nextch(P);
    prevch(nextch(P)) = prec;
    nextch(P) = NULL;
    prevch(P) = NULL;
}

void deleteLastChild_4(list_child &L,adr_child &P){
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

void showChild_4(list_child L){
    adr_child x;
    x = firstch(L);
    while (x != NULL) {
        cout <<"---data kereta---"<<endl;
        cout<< infoch(x).id_kereta<<endl;
        cout<< infoch(x).nama_kereta<<endl;
        cout<< infoch(x).asal_perjalanan<<endl;
        cout<< infoch(x).tujuan_perjalanan<<endl;
        cout<< infoch(x).pemberhentian<<endl;
        cout<<"-------------------"<<endl;
        x = nextch(x);
    }
}
