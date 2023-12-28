#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
using namespace std;
#include "relasi.h"
#include "parent.h"
#include "child.h"


void welcome();
void showmenu(list_parent &Lp,list_child &Lc,list_relasi &Lr,int input);
void menu1(list_parent &Lp,list_child &Lc,list_relasi &Lr);
void menu2(list_parent &Lp,list_child &Lc,list_relasi &Lr);
void menu3(list_parent &Lp,list_child &Lc,list_relasi &Lr);
void menu4(list_parent &Lp,list_child &Lc,list_relasi &Lr);


#endif // MENU_H_INCLUDED
