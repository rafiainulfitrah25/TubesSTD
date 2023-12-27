#include <iostream>
#include "stasiun.h"
#include "component.cpp"
#include "utils.cpp"
#include <stdlib.h>
#include "kereta.h"

using namespace std;

int main()
{
    Component component;
    Utils utils;

    StasiunList stasiunList;
    createStasiunList(stasiunList);

    KeretaList keretaList;
    createKeretaList(keretaList);





    component.header();

    int option;
    utils.inputOption(option, 13);
    system ("CLS");

    switch (option) {
        case 1:
            {
                StasiunInfoType inputStasiun;
                int x;

                cout << "Jumlah Record Stasiun : ";
                cin >> x;

                for (int i = 0; i < x; i++) {
                    cout << "ID : ";
                    cin >> inputStasiun.id;

                    cout << "Nama : ";
                    cin >> inputStasiun.nama;

                    cout << "Kabkot : ";
                    cin >> inputStasiun.kabkot;

                    cout << "Provinsi : ";
                    cin >> inputStasiun.provinsi;

                    cout << "Traffic ";
                    cin >> inputStasiun.traffic;

                    cout << "--------------------" << endl;
                    StasiunAddress stasiun = createStasiunElement(inputStasiun);
                    insertLastStasiun(stasiunList, stasiun);
                }
            } break;
        case 2:
            {
                KeretaInfoType inputKereta;
                int x;

                cout << "Jumlah Record Kereta : ";
                cin >> x;

                for (int i = 0; i < x; i++) {
                    cout << "ID : ";
                    cin >> inputKereta.id;

                    cout << "Nama : ";
                    cin >> inputKereta.nama;

                    cout << "Keberangkatan : ";
                    cin >> inputKereta.keberangkatan;

                    cout << "Tujuan : ";
                    cin >> inputKereta.tujuan;

                    cout << "--------------------" << endl;
                    KeretaAddress kereta = createKeretaElement(inputKereta);
                    insertLastKereta(keretaList, kereta);
                }
            } break;
        case 3:
            {

            } break;
    }



    // findAllStasiun(stasiunList);
    findAllKereta(keretaList);

    return 0;
}
