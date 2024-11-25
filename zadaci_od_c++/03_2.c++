// 2. Да се направи програма која ќе ја користи класата Штедач и ќе овозможи: 
// a)	Внесување на нов штедач во системот
// b)	Приказ на податоците
// c)	Уплата на средства
// d)	Исплата на средства (со контрола дали е можна таква исплата)
// e)	Приказ на салдото за даден штедач

#include<iostream>
#include <cstring>
#include <vector>
using namespace std;

class Stedac
{
private:
    int broj;
    char imeprezime[30], adresa[50];
    long saldo;
 public:
        void vnesi_podatoci(int b, const char* ime, const char* adresa_val)
        {
            broj = b;
            strncpy(imeprezime, ime, sizeof(imeprezime) - 1);
            imeprezime[sizeof(imeprezime) - 1] = '\0';
            strncpy(adresa, adresa_val, sizeof(adresa) - 1);
            adresa[sizeof(adresa) - 1] = '\0';
            saldo = 0;
        }
        void prikazi_podatoci()
        {
            cout << "Broj na shtedach: " << broj << endl;
            cout << "Ime i prezime: " << imeprezime << endl;
            cout << "Adresa: " << adresa << endl;
            cout << "Saldo: " << saldo << endl;
        }
        void uplata(unsigned long i)
        {
            saldo += i;
            cout << "Uspesna uplata od " << i << endl;
        }
        void isplata(unsigned long i)
        {
            if (i <= saldo) {
            saldo -= i;
            cout << "Uspesna isplata od " << i << endl;
            } else {
                cout << "Nemate dovolno sredstva za ova isplata!" << endl;
            }
        }
        long sostojba()
        {
            return saldo;
        }


}; 


int main()
{
    vector<Stedac> stedaci; 
    int izbor;
    bool exit = false;

    while (!exit) {
        cout << "\nMeni:" << endl;
        cout << "1. Vnesi nov stedac" << endl;
        cout << "2. Prikazi podatoci za stedac" << endl;
        cout << "3. Uplata na sredstva" << endl;
        cout << "4. Isplata na sredstva" << endl;
        cout << "5. Prikazi saldo za stedac" << endl;
        cout << "6. Izhod" << endl;
        cout << "Izbor: ";
        cin >> izbor;

        switch (izbor) {
            case 1: {
                int broj;
                char ime[30], adresa[50];
                cout << "Vnesi broj na stedac: ";
                cin >> broj;
                cin.ignore();  // За да го исчистиме последниот останат знак од ентерот
                cout << "Vnesi ime i prezime: ";
                cin.getline(ime, 30);
                cout << "Vnesi adresa: ";
                cin.getline(adresa, 50);

                Stedac novi_stedac;
                novi_stedac.vnesi_podatoci(broj, ime, adresa);
                stedaci.push_back(novi_stedac);  // Додаваме нов штедач во vector
                break;
            }

            case 2: {
                if (stedaci.empty()) {
                    cout << "Nema kreirani stedaci." << endl;
                } else {
                    int index;
                    cout << "Vnesi broj na stedac (0-" << stedaci.size() - 1 << "): ";
                    cin >> index;
                    if (index >= 0 && index < stedaci.size()) {
                        stedaci[index].prikazi_podatoci();
                    } else {
                        cout << "Nevaliden broj na stedac!" << endl;
                    }
                }
                break;
            }

            case 3: {
                if (stedaci.empty()) {
                    cout << "Nema kreirani stedaci." << endl;
                } else {
                    int index;
                    unsigned long uplata;
                    cout << "Vnesi broj na stedac (0-" << stedaci.size() - 1 << "): ";
                    cin >> index;
                    if (index >= 0 && index < stedaci.size()) {
                        cout << "Vnesi iznos na uplata: ";
                        cin >> uplata;
                        stedaci[index].uplata(uplata);
                    } else {
                        cout << "Nevaliden broj na stedac!" << endl;
                    }
                }
                break;
            }

            case 4: {
                if (stedaci.empty()) {
                    cout << "Nema kreirani stedaci." << endl;
                } else {
                    int index;
                    unsigned long isplata;
                    cout << "Vnesi broj na stedach (0-" << stedaci.size() - 1 << "): ";
                    cin >> index;
                    if (index >= 0 && index < stedaci.size()) {
                        cout << "Vnesi iznos na isplata: ";
                        cin >> isplata;
                        stedaci[index].isplata(isplata);
                    } else {
                        cout << "Nevaliden broj na stedac!" << endl;
                    }
                }
                break;
            }

            case 5: {
                if (stedaci.empty()) {
                    cout << "Nema kreirani stedaci." << endl;
                } else {
                    int index;
                    cout << "Vnesi broj na stedac (0-" << stedaci.size() - 1 << "): ";
                    cin >> index;
                    if (index >= 0 && index < stedaci.size()) {
                        cout << "Saldo: " << stedaci[index].sostojba() << endl;
                    } else {
                        cout << "Nevaliden broj na stedac!" << endl;
                    }
                }
                break;
            }

            case 6: {
                exit = true;
                break;
            }

            default:
                cout << "Nevaliden izbor! Probajte povtorno." << endl;
        }
    }
}

