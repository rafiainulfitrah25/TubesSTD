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


void menu1(list_parent &Lp,list_child &Lc,list_relasi &Lr){
    int input;
    cout << "1.Tambah stasiun"<<endl;
    cout << "2.Tambah kereta"<<endl;
    cout << "3.Tambah Stasiun untuk kereta"<<endl;
    cin >>input;
    if (input == 1){
        insertparent_4(Lp);
    }else if (input == 2){
        insertchild_4(Lc);
    }else{
        adr_relasi p;
        hubungkan_4(Lr,Lc,Lp,p);
    }
}

void menu2(list_parent &Lp,list_child &Lc,list_relasi &Lr){

}

void menu3(list_parent &Lp,list_child &Lc,list_relasi &Lr){
    int input;
    cout << "1.Edit stasiun kereta"<<endl;
    cout << "2.Edit kereta di stasiun"<<endl;
    cin >>input;
    if (input == 1){
        editRelasitoPr_4(Lr,Lc,Lp);
    }else{
        editRelasitoCh_4(Lr,Lc,Lp);
    }
}

void menu4(list_parent &Lp,list_child &Lc,list_relasi &Lr){
    int input;
    cout << "1.Show parent"<<endl;
    cout << "2.Show child"<<endl;
    cout << "3.Show child relasi"<<endl;
    cin >>input;
    if (input == 1){
        showParent_4(Lp);
    }else if (input == 2){
        showChild_4(Lc);
    }else{
        string id_stasiun;
        cout<<"pilih stasiun"<<endl;
        showParent_4(Lp);
        cin>>id_stasiun;
        showchildrelasi_4(Lr,Lp,id_stasiun);
    }
}

void showmenu(list_parent &Lp,list_child &Lc,list_relasi &Lr,int input){
    do{
        cout << "1.Tambahkan Data Command"<<endl;
        cout << "2.Hapus Data Command"<<endl;
        cout << "3.Edit Relasi Command"<<endl;
        cout << "4.Info Data Command"<<endl;
        cout << "0.Exit"<<endl;
        cin>>input;
        if (input == 1){
            menu1(Lp,Lc,Lr);
        }else if (input == 2){
            menu2(Lp,Lc,Lr);
        }else if (input == 3){
            menu3(Lp,Lc,Lr);
        }else if (input == 4){
            menu4(Lp,Lc,Lr);
        }
    }while(input != 0);
}
