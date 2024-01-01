#include <iostream>
#include <typeinfo>
#include <limits>



using namespace std;

class Utils {
    public:
        void inputOption(int &option, int maxOpt) {
            cout << "Pilih opsi: ";
            cin >> option;

            while (!option || option > maxOpt || option == 0) {
                cout << "[Bad Request] Input harus dengan numeric, silahkan pilih 1 sampai " << maxOpt << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Pilih opsi: ";
                cin >> option;
            }
        }

        void clearScreen() {
            system ("CLS");
        }

        void waitForNavigation() {
            cout << endl;
            system("pause");
        }
};


