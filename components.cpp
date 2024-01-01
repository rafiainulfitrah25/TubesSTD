#include <iostream>

using namespace std;

class Component {
    public:
        void header(){
            cout<<"--------------------------------------"<<endl;
            cout<<"\t\tKAICC\t"<<endl;
            cout<<"--------------------------------------"<<endl;
            cout<<"Made by Kelompok-4 IF-46-10"<<endl;
            cout << endl;
            cout << endl;
        }

        void menu() {
        cout << "1.Tambahkan Data Command"<<endl;
        cout << "2.Hapus Data Command"<<endl;
        cout << "3.Edit Relasi Command"<<endl;
        cout << "4.Info Data Command"<<endl;
        cout << "5.Exit"<<endl;
        }
};
