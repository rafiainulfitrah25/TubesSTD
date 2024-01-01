#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
using namespace std;
#include "relasi.h"
#include "parent.h"
#include "child.h"


void welcome();
void showmenu(StasiunList &Lp,KeretaList &Lc,RelasiList &Lr,int input);
void menu1(StasiunList &Lp,KeretaList &Lc,RelasiList &Lr);
void menu2(StasiunList &Lp,KeretaList &Lc,RelasiList &Lr);
void menu3(StasiunList &Lp,KeretaList &Lc,RelasiList &Lr);
void menu4(StasiunList &Lp,KeretaList &Lc,RelasiList &Lr);


#endif // MENU_H_INCLUDED
