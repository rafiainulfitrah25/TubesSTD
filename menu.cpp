#include <iostream>
using namespace std;
#include "menu.h"
#include "relasi.h"
#include "parent.h"
#include "child.h"

void welcome(){
    cout<<"-------------------------------"<<endl;
    cout<<"_____________KAICC_____________"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"____________Made by____________"<<endl;
    cout<<"______Kelompok-4 IF-46-10______"<<endl;
}

void showmenu(int &input){
        cout << "1.Tambahkan Relasi"<<endl;
        cout << "2.Hapus Relasi"<<endl;
        cout << "3.Edit Relasi"<<endl;
        cout << "4.Info Relasi"<<endl;
        cout << "0.Exit"<<endl;
        cin>>input;
}

void menu1(list_parent &Lp,list_child &Lc,list_relasi &Lr){
    int input;
    cout << "1.Tambah kereta"<<endl;
    cout << "2.Tambah Stasiun"<<endl;
    cout << "3.Tambah Stasiun untuk kereta"<<endl;
    cin >>input;
    if (input == 1){
        insertparent_4(Lp);
    }
}
