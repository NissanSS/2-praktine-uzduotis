#include <iostream>
#include <string>

using namespace std;

int main() {
    string vardai[100];
    int pazymiai[100][10] = {};
    int mokiniukiekis = 0;
    int pasirinkimas;

    do {
        cout << endl;
        cout << "- MOKINIU PAZYMIU SISTEMA -" << endl;
        cout << "1. Prideti mokini ir pazymius" << endl;
        cout << "2. Perziureti visu mokiniu pazymius" << endl;
        cout << "3. Perziureti konkretaus mokinio pazymius" << endl;
        cout << "4. Atnaujinti pazymi" << endl;
        cout << "5. Pasalinti mokini" << endl;
        cout << "0. Baigti darba" << endl;
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;

        if (pasirinkimas == 1) {
            if (mokiniukiekis >= 100) {
                cout << "Daugiau mokiniu prideti negalima." << endl;
                continue;
            }
            int kiekpazymiu;

            cout << "Iveskite mokinio varda (be tarpu): ";
            cin >> vardai[mokiniukiekis];
            cout << "Kiek pazymiu tures mokinys? (1-10): ";
            cin >> kiekpazymiu;

            if (kiekpazymiu < 1 || kiekpazymiu > 10) {
                cout << "Neteisingas pazymiu kiekis." << endl;
                continue;
            }
            for (int j = 0; j < kiekpazymiu; j++) {

                cout << "Iveskite " << j + 1 << "-aji pazymi: ";
                cin >> pazymiai[mokiniukiekis][j];

                if (pazymiai[mokiniukiekis][j] < 1 || pazymiai[mokiniukiekis][j] > 10) {
                    cout << "Pazymys turi buti nuo 1 iki 10." << endl;
                    pazymiai[mokiniukiekis][j] = 0;
                    j--;
                }
              }
            mokiniukiekis++;
            cout << "Mokinys sekmingai pridetas." << endl;
        }

        else if (pasirinkimas == 2) {
            if (mokiniukiekis == 0) {
                cout << "Mokiniu sarasas tuscias." << endl;
                continue;
            }
            cout << endl;
            cout << "Visu mokiniu pazymiai:" << endl;

            for (int i = 0; i < mokiniukiekis; i++) {

                cout << i + 1 << ". " << vardai[i] << ": ";
                for (int j = 0; j < 10; j++) {

                    if (pazymiai[i][j] != 0) {
                        cout << pazymiai[i][j] << " ";
                    }
                  }
                cout << endl;
            }
           }
        else if (pasirinkimas == 3) {
            if (mokiniukiekis == 0) {
                cout << "Mokiniu sarasas tuscias." << endl;
                continue;
            }
            int numeris;

            cout << endl;
            cout << "Mokiniu sarasas:" << endl;

            for (int i = 0; i < mokiniukiekis; i++) {
                cout << i + 1 << ". " << vardai[i] << endl;
            }
            cout << "Iveskite mokinio numeri: ";
            cin >> numeris;

            if (numeris < 1 || numeris > mokiniukiekis) {
                cout << "Neteisingas numeris." << endl;
                continue;
            }
            int i = numeris - 1;

            cout << vardai[i] << " pazymiai: ";

            for (int j = 0; j < 10; j++) {
                if (pazymiai[i][j] != 0) {
                    cout << pazymiai[i][j] << " ";
                }
            }
            cout << endl;
        }
        else if (pasirinkimas == 4) {

            if (mokiniukiekis == 0) {
                cout << "Mokiniu sarasas tuscias." << endl;
                continue;
            }
            int numeris;

            cout << endl;
            cout << "Mokiniu sarasas:" << endl;

            for (int i = 0; i < mokiniukiekis; i++) {
                cout << i + 1 << ". " << vardai[i] << endl;
            }
            cout << "Iveskite mokinio numeri: ";
            cin >> numeris;

            if (numeris < 1 || numeris > mokiniukiekis) {
                cout << "Neteisingas numeris." << endl;
                continue;
            }
            int i = numeris - 1;

            cout << "Dabartiniai pazymiai: ";
            int pazymiukiekis = 0;

            for (int j = 0; j < 10; j++) {
                if (pazymiai[i][j] != 0) {
                    cout << j + 1 << ":" << pazymiai[i][j] << " ";
                    pazymiukiekis++;
                }
            }
            cout << endl;

            int pazymionr;
            int naujaspazymys;

            cout << "Kuri pazymi norite pakeisti? ";
            cin >> pazymionr;

            if (pazymionr < 1 || pazymionr > pazymiukiekis) {
                cout << "Neteisingas pazymio numeris." << endl;
                continue;
            }
            cout << "Iveskite nauja pazymi (1-10): ";
            cin >> naujaspazymys;
            if (naujaspazymys < 1 || naujaspazymys > 10) {
                cout << "Neteisingas pazymys." << endl;
                continue;
            }
            pazymiai[i][pazymionr - 1] = naujaspazymys;
            cout << "Pazymys atnaujintas." << endl;
        }

        else if (pasirinkimas == 5) {
            if (mokiniukiekis == 0) {
                cout << "Mokiniu sarasas tuscias." << endl;
                continue;
            }
            int numeris;

            cout << endl;
            cout << "Mokiniu sarasas:" << endl;

            for (int i = 0; i < mokiniukiekis; i++) {
                cout << i + 1 << ". " << vardai[i] << endl;
            }
            cout << "Iveskite mokinio numeri, kuri norite pasalinti: ";
            cin >> numeris;

            if (numeris < 1 || numeris > mokiniukiekis) {
                cout << "Neteisingas numeris." << endl;
                continue;
            }

            int i = numeris - 1;

            for (int k = i; k < mokiniukiekis - 1; k++) {

                vardai[k] = vardai[k + 1];

                for (int j = 0; j < 10; j++) {
                    pazymiai[k][j] = pazymiai[k + 1][j];
                }
            }

            vardai[mokiniukiekis - 1] = "";

            for (int j = 0; j < 10; j++) {
                pazymiai[mokiniukiekis - 1][j] = 0;
            }
            mokiniukiekis--;
            cout << "Mokinys pasalintas." << endl;
        }

        else if (pasirinkimas != 0) {
            cout << "Neteisingas pasirinkimas." << endl;
        }
    } while (pasirinkimas != 0);

    cout << "Programa baigta." << endl;

    return 0;
}

