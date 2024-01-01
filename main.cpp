#include <iostream>
using namespace std;
#include "relasi.h"
#include "parent.h"
#include "child.h"
#include "menu.h"
#include "components.cpp"
#include "utils.cpp"

int main()
{
    Component component;
    Utils utils;

    StasiunList Lp;
    createListParent_4(Lp);

    KeretaList Lc;
    createListChild_4(Lc);

    RelasiList Lr;
    createListRelasi_4(Lr);


    component.header();

    component.menu();

    int option;
    utils.inputOption(option, 5);


    while (option != 5) {
        switch (option) {
            case 1: {
                utils.clearScreen();

                cout << "1.Tambah stasiun"<<endl;
                cout << "2.Tambah kereta"<<endl;
                cout << "3.Tambah Stasiun untuk kereta"<<endl;

                int tambahDataOption;
                utils.inputOption(tambahDataOption, 3);

                if (tambahDataOption == 1) {
                    int insertQty;

                    cout << "Jumlah record stasiun yang akan di tambah: ";
                    cin >> insertQty;

                    for (int i = 0; i < insertQty; i++) {
                        insertParent_4(Lp);
                    }
                } else if (tambahDataOption == 2) {
                    int insertQty;

                    cout << "Jumlah record kereta yang akan di tambah: ";
                    cin >> insertQty;

                    for (int i = 0; i < insertQty; i++) {
                        insertChild_4(Lc);
                    }
                } else if (tambahDataOption == 3) {
                    hubungkan_4(Lr,Lc,Lp);
                }
            } break;
            case 2: {
                cout << "1.Hapus stasiun"<<endl;
                cout << "2.Hapus kereta"<<endl;

                int hapusDataOption;
                utils.inputOption(hapusDataOption, 3);

                if (hapusDataOption == 1) {
                    deleteRelParent_4(Lr, Lp, Lc);
                } else if (hapusDataOption == 2) {
                    string id;
                    cout << "Hapus kereta by ID : ";
                    cin >> id;

                    KeretaAddress POut;
                    deleteChild_4(Lc, POut, id);
                }

            } break;
            case 3: {
                utils.clearScreen();

                cout << "1.Edit stasiun kereta"<<endl;
                cout << "2.Edit kereta di stasiun"<<endl;

                int editDataOption;
                utils.inputOption(editDataOption, 2);

                if (editDataOption == 1) {
                    editRelasitoPr_4(Lr,Lc,Lp);
                } else if (editDataOption == 2) {
                    editRelasitoCh_4(Lr,Lc,Lp);
                }
            } break;
            case 4: {
                utils.clearScreen();

                cout << "1.Show stasiun"<<endl;
                cout << "2.Show kereta"<<endl;
                cout << "3.Show kereta relasi"<<endl;

                int showDataOption;
                utils.inputOption(showDataOption, 3);

                if (showDataOption == 1) {
                    showParent_4(Lp);
                } else if (showDataOption == 2) {
                    showChild_4(Lc);
                } else if (showDataOption == 3) {
                    string id_stasiun;
                    cout<<"pilih stasiun"<<endl;
                    showParent_4(Lp);
                    cin>>id_stasiun;

                    utils.clearScreen();
                    showchildrelasi_4(Lr,Lp,id_stasiun);
                }

                utils.waitForNavigation();
            } break;
        }

        utils.clearScreen();
        component.menu();
        utils.inputOption(option, 5);
    }

    cout << "Application closed";

}
