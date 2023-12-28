#include <iostream>
using namespace std;
#include "relasi.h"
#include "parent.h"
#include "child.h"
#include "menu.h"
int main()
{
    list_parent Lp;
    list_child Lc;
    list_relasi Lr;
    createListParent_4(Lp);
    createListChild_4(Lc);
    createListRelasi_4(Lr);
    int input;
    showmenu(Lp,Lc,Lr,input);
}
