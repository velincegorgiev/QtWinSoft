// Користејќи ги концептите на ООП да се моделираат соодветни класи според спецификациите дадени на слика 1,
//  а потоа во функцијата main() да се констуира низа со објекти од долунаведените класи 
//  (професор, асистент, демонстратор) и имплементира кориснички посредник преку мени со следните опции: 
 
// 1.    Додавање на нов вработен во листата
// 2.    Прикажување на листата 
// 3.    Крај
 
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Vraboten {
protected:
    char ime[50];
    char prezime[50];
    int godina_na_vrabotuvanje;

public:
    Vraboten() {
        strcpy(ime, "");
        strcpy(prezime, "");
        godina_na_vrabotuvanje = 0;
    }

    Vraboten(const char* _ime, const char* _prezime, int _godina) {
        strcpy(ime, _ime);
        strcpy(prezime, _prezime);
        godina_na_vrabotuvanje = _godina;
    }

    void postavi(const char* _ime, const char* _prezime, int _godina) {
        strcpy(ime, _ime);
        strcpy(prezime, _prezime);
        godina_na_vrabotuvanje = _godina;
    }

    virtual void prikazi_podatoci() const {
        cout << "Ime: " << ime << ", Prezime: " << prezime
             << ", Godina na vrsenje: " << godina_na_vrabotuvanje << endl;
    }
};

class Profesor : public Vraboten {
private:
    char zvanje[50];
    char oblast[50];
    int br_predmeti;

public:
    Profesor() : Vraboten() {
        strcpy(zvanje, "");
        strcpy(oblast, "");
        br_predmeti = 0;
    }

    Profesor(const char* _ime, const char* _prezime, int _godina,
             const char* _zvanje, const char* _oblast, int _br_predmeti)
        : Vraboten(_ime, _prezime, _godina) {
        strcpy(zvanje, _zvanje);
        strcpy(oblast, _oblast);
        br_predmeti = _br_predmeti;
    }

    void postavi(const char* _ime, const char* _prezime, int _godina,
                 const char* _zvanje, const char* _oblast, int _br_predmeti) {
        Vraboten::postavi(_ime, _prezime, _godina);
        strcpy(zvanje, _zvanje);
        strcpy(oblast, _oblast);
        br_predmeti = _br_predmeti;
    }

    void prikazi_podatoci() const override {
        Vraboten::prikazi_podatoci();
        cout << "Zvanje: " << zvanje << ", Oblast: " << oblast << ", Broj na predmeti: " << br_predmeti << endl;
    }
};

class Asistent : public Vraboten {
private:
    char zvanje[50];
    char mentor[50];
    int br_predmeti;

public:
    Asistent() : Vraboten() {
        strcpy(zvanje, "");
        strcpy(mentor, "");
        br_predmeti = 0;
    }

    Asistent(const char* _ime, const char* _prezime, int _godina,
             const char* _zvanje, const char* _mentor, int _br_predmeti)
        : Vraboten(_ime, _prezime, _godina) {
        strcpy(zvanje, _zvanje);
        strcpy(mentor, _mentor);
        br_predmeti = _br_predmeti;
    }

    void postavi(const char* _ime, const char* _prezime, int _godina,
                 const char* _zvanje, const char* _mentor, int _br_predmeti) {
        Vraboten::postavi(_ime, _prezime, _godina);
        strcpy(zvanje, _zvanje);
        strcpy(mentor, _mentor);
        br_predmeti = _br_predmeti;
    }

    void prikazi_podatoci() const override {
        Vraboten::prikazi_podatoci();
        cout << "Zvanje: " << zvanje << ", Mentor: " << mentor << ", Broj na predmeti: " << br_predmeti << endl;
    }
};

class Demonstrator : public Vraboten {
private:
    char rabotno_vreme[50];

public:
    Demonstrator() : Vraboten() {
        strcpy(rabotno_vreme, "");
    }

    Demonstrator(const char* _ime, const char* _prezime, int _godina, const char* _rabotno_vreme)
        : Vraboten(_ime, _prezime, _godina) {
        strcpy(rabotno_vreme, _rabotno_vreme);
    }

    void postavi(const char* _ime, const char* _prezime, int _godina, const char* _rabotno_vreme) {
        Vraboten::postavi(_ime, _prezime, _godina);
        strcpy(rabotno_vreme, _rabotno_vreme);
    }

    void prikazi_podatoci() const override {
        Vraboten::prikazi_podatoci();
        cout << "Rabotno vreme: " << rabotno_vreme << endl;
    }
};

int main() {
    vector<Vraboten*> lista_vraboteni;
    int opcija;
    do {
        cout << "\n1. Dodavanje na nov vraboteni\n";
        cout << "2. Prikazuvanje na listata\n";
        cout << "3. Kraj\n";
        cout << "Izberi opcija: ";
        cin >> opcija;
        cin.ignore();

        if (opcija == 1) {
            int tip;
            cout << "Izberi tip na vraboteni (1. Profesor, 2. Asistent, 3. Demonstrator): ";
            cin >> tip;
            cin.ignore();

            char ime[50], prezime[50], zvanje[50], oblast[50], mentor[50], rabotno_vreme[50];
            int godina, br_predmeti;

            switch (tip) {
                case 1:
                    cout << "Vnesi ime, prezime, godina, zvanje, oblast, broj na predmeti: ";
                    cin.getline(ime, 50);
                    cin.getline(prezime, 50);
                    cin >> godina;
                    cin.ignore();
                    cin.getline(zvanje, 50);
                    cin.getline(oblast, 50);
                    cin >> br_predmeti;
                    cin.ignore();
                    {
                        Profesor* profesor = new Profesor();
                        profesor->postavi(ime, prezime, godina, zvanje, oblast, br_predmeti);
                        lista_vraboteni.push_back(profesor);
                    }
                    break;

                case 2:
                    cout << "Vnesi ime, prezime, godina, zvanje, mentor, broj na predmeti: ";
                    cin.getline(ime, 50);
                    cin.getline(prezime, 50);
                    cin >> godina;
                    cin.ignore();
                    cin.getline(zvanje, 50);
                    cin.getline(mentor, 50);
                    cin >> br_predmeti;
                    cin.ignore();
                    {
                        Asistent* asistent = new Asistent();
                        asistent->postavi(ime, prezime, godina, zvanje, mentor, br_predmeti);
                        lista_vraboteni.push_back(asistent);
                    }
                    break;

                case 3:
                    cout << "Vnesi ime, prezime, godina, rabotno vreme: ";
                    cin.getline(ime, 50);
                    cin.getline(prezime, 50);
                    cin >> godina;
                    cin.ignore();
                    cin.getline(rabotno_vreme, 50);
                    {
                        Demonstrator* demonstrator = new Demonstrator();
                        demonstrator->postavi(ime, prezime, godina, rabotno_vreme);
                        lista_vraboteni.push_back(demonstrator);
                    }
                    break;

                default:
                    cout << "Nepoznata opcija.\n";
            }
        } else if (opcija == 2) {
            cout << "\nLista na vraboteni:\n";
            for (auto& vraboten : lista_vraboteni) {
                vraboten->prikazi_podatoci();
                cout << "--------------------------------------\n";
            }
        } else if (opcija == 3) {
            cout << "Kraj na programata.\n";
        } else {
            cout << "Nepoznata opcija. Pokušajte ponovo.\n";
        }

    } while (opcija != 3);

    for (auto& vraboten : lista_vraboteni) {
        delete vraboten;
    }

    return 0;
}
