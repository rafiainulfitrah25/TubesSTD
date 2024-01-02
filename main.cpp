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

                cout << "1.Tambah stasiun [A]"<<endl;
                cout << "2.Tambah kereta [B]"<<endl;
                cout << "3.Tambah Stasiun untuk kereta [C]"<<endl;

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
                cout << "1.Hapus stasiun [D | F]" << endl;
                cout << "2.Hapus kereta [E]" << endl;

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
                    mintraffic_4(Lr, Lc, Lp, id);
                }

            } break;
            case 3: {
                utils.clearScreen();

                cout << "1.Edit stasiun kereta [T]"<<endl;
                cout << "2.Edit kereta di stasiun [T]"<<endl;

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

                cout << "1.Show stasiun [J | P | S]" << endl;
                cout << "2.Show kereta [K | Q | R]" << endl;
                cout << "3.Show kereta relasi by ID stasiun [L]" << endl;
                cout << "4.Show stasiun relasi by ID kereta [M]" << endl;
                cout << "5.Show stasiun beserta relasi kereta nya [N]"<<endl;
                cout << "6.Show kereta beserta relasi stasiun nya [O]"<<endl;

                int showDataOption;
                utils.inputOption(showDataOption, 6);

                if (showDataOption == 1) {
                    StasiunAddress x = firstpr(Lp);
                    x = firstpr(Lp);
                        cout <<"---data all stasiun---"<<endl;
                    while (x != NULL) {
                        cout << infopr(x).id<<endl;
                        cout << infopr(x).nama<<endl;
                        cout << infopr(x).kabkot<<endl;
                        cout << infopr(x).provinsi<<endl;
                        cout << infopr(x).traffic<<endl;
                        int keretaCounted = countchild_4(Lr, Lc, Lp, infopr(x).id);
                        cout << "jumlah kereta : " << keretaCounted << endl;
                        cout<<"-------------------"<<endl;
                        x = nextpr(x);
                    }
                    int stasiunNoKeretaCounted = countnonchild_4(Lr, Lc, Lp);
                    cout << "Jumlah stasiun yang tidak memiliki kereta : " << stasiunNoKeretaCounted << endl;
                } else if (showDataOption == 2) {
                    KeretaAddress x;
                    x = firstch(Lc);
                    cout <<"---data kereta---"<<endl;
                    while (x != NULL) {
                        cout<< infoch(x).id<<endl;
                        cout<< infoch(x).nama<<endl;
                        cout<< infoch(x).keberangkatan<<endl;
                        cout<< infoch(x).tujuan<<endl;
                        cout<< infoch(x).pemberhentian<<endl;
                        cout << "jumlah stasiun : " << countparent_4(Lr, Lc, Lp, infoch(x).id) << endl;
                        cout<<"-------------------"<<endl;
                        x = nextch(x);
                    }
                    cout << "Jumlah kereta yang tidak memiliki stasiun : " << countnonparent_4(Lr, Lc, Lp) << endl;
                } else if (showDataOption == 3) {
                    string id_stasiun;
                    showParent_4(Lp);
                    cout<<"Pilih stasiun by ID : "<<endl;
                    cin>>id_stasiun;

                    utils.clearScreen();
                    showchildrelasi_4(Lr,Lp,id_stasiun);
                } else if (showDataOption == 4) {
                    string id_kereta;
                    showChild_4(Lc);
                    cout<<"Pilih kereta by ID : "<<endl;
                    cin>>id_kereta;

                    utils.clearScreen();
                    showparentrelasi_4(Lr,Lc,id_kereta);
                } else if (showDataOption == 5) {
                    StasiunAddress x = firstpr(Lp);

                    cout << "---data stasiun---" << endl;

                    while (x != NULL) {
                        cout<< infopr(x).id<<endl;
                        cout<< infopr(x).nama<<endl;
                        cout<< infopr(x).kabkot<<endl;
                        cout<< infopr(x).provinsi<<endl;
                        cout<< infopr(x).traffic<<endl << endl;
                        cout << "Kereta yang berelasi:" << endl;
                        RelasiAddress Y = firstr(Lr);

                        if (Y != NULL) {
                            do {
                                if (relasi_parent(Y) == x) {
                                    cout << "ID : " <<infoch(relasi_child(Y)).id << endl;
                                    cout << "Nama : " <<infoch(relasi_child(Y)).nama << endl;
                                    cout << "Keberangkatan : " <<infoch(relasi_child(Y)).keberangkatan << endl;
                                    cout << "Tujuan : " <<infoch(relasi_child(Y)).tujuan << endl;
                                    cout << "Pemberhentian : " <<infoch(relasi_child(Y)).pemberhentian << endl;
                                    cout << "----------------------" << endl;
                                }
                                Y = nextr(Y);
                            } while (Y != firstr(Lr));
                        }

                        x = nextpr(x);
                        cout << "-------------------------------------" << endl;
                    }
                } else if (showDataOption == 6) {
                    KeretaAddress x = firstch(Lc);

                    cout << "---data kereta---" << endl;

                    while (x != NULL) {
                        cout<< infoch(x).id<<endl;
                        cout<< infoch(x).nama<<endl;
                        cout<< infoch(x).keberangkatan<<endl;
                        cout<< infoch(x).tujuan<<endl;
                        cout<< infoch(x).pemberhentian<<endl;
                        cout << "Stasiun yang berelasi:" << endl;
                        RelasiAddress Y = firstr(Lr);

                        if (Y != NULL) {
                            do {
                                if (relasi_child(Y) == x) {
                                    cout << "ID : " << infopr(relasi_parent(Y)).id << endl;
                                    cout << "Nama : " << infopr(relasi_parent(Y)).nama << endl;
                                    cout << "Kabkot : " << infopr(relasi_parent(Y)).kabkot << endl;
                                    cout << "Provinsi : " << infopr(relasi_parent(Y)).provinsi << endl;
                                    cout << "Traffic : " << infopr(relasi_parent(Y)).traffic << endl;
                                    cout << "----------------------" << endl;
                                }

                                Y = nextr(Y);
                            }while (Y != firstr(Lr));
                        }

                        x = nextch(x);
                        cout << "-------------------------------------" << endl;
                    }
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
