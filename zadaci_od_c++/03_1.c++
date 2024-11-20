// 1. Да се формира класа Квадар (скриени елементи: должина, ширина и висина; јавни функции: плоштина, волумен). 
// Од неа да се имплементира поле од објекти. Да се најде оној кој има најмала плоштина, а не е коцка. Да се креира мени:
// a)	Креирај нов објект
// b)	Постави ги димензиите
// c)	Печати ги димензиите на сите објекти
// d)	Печати ги димензиите за поедин објект
// e)	Печати ги оние кои го задоволуваат условот


#include <iostream>
#include <vector>
using namespace std;

class Kvadar {
private:
    int dolzina, sirina, visina;

public:
    Kvadar(){
        dolzina=0;
        sirina=0;
        visina=0;
    }
    Kvadar(int d, int s, int v){
        dolzina=d;
        sirina=s;
        visina=v;
    }

    void setDolzina(int d) { dolzina = d; }
    void setSirina(int s) { sirina = s; }
    void setVisina(int v) { visina = v; }

    int getDolzina() const { return dolzina; }
    int getSirina() const { return sirina; }
    int getVisina() const { return visina; }

    int plostina() const {
        return 2 * (dolzina * sirina + dolzina * visina + sirina * visina);
    }

    int volumen() const {
        return dolzina * sirina * visina;
    }

    void pecatiDimenzii() const {
        cout << "Dolzina: " << dolzina << ", Sirina: " << sirina << ", Visina: " << visina << endl;
    }

    bool eKocka() const {
        return dolzina == sirina && sirina == visina;
    }
};

int main() {
    vector<Kvadar> objekti;
    int izbor;
    bool exit = false;

    while (!exit) {
        cout << "\nMeni:\n";
        cout << "1. Kreiraj nov objekt\n";
        cout << "2. Postavi gi dimenziite za postoecki objekt\n";
        cout << "3. Pecati gi dimenziite na site objekti\n";
        cout << "4. Pecati gi dimenziite na eden objekt\n";
        cout << "5. Pecati gi objektite koi ne se kocki i go zadovoluvaat uslovot za najmala plostina\n";
        cout << "6. Izlez\n";
        cout << "Izbor: ";
        cin >> izbor;

        switch (izbor) {
            case 1: {
                int d, s, v;
                cout << "Vnesi dolzina, sirina, visina: ";
                cin >> d >> s >> v;
                objekti.push_back(Kvadar(d, s, v));
                break;
            }
            case 2: {
                int index;
                cout << "Vnesi indeks (0-" << objekti.size() - 1 << "): ";
                cin >> index;
                if (index >= 0 && index < objekti.size()) {
                    int d, s, v;
                    cout << "Vnesi dolzina, sirina, visina: ";
                    cin >> d >> s >> v;
                    objekti[index].setDolzina(d);
                    objekti[index].setSirina(s);
                    objekti[index].setVisina(v);
                } else {
                    cout << "Nevaliden indeks!\n";
                }
                break;
            }
            case 3: {
                if (objekti.empty()) {
                    cout << "Nema kreirani objekti.\n";
                } else {
                    for (int i = 0; i < objekti.size(); i++) {
                        cout << "Objekt " << i + 1 << ": ";
                        objekti[i].pecatiDimenzii();
                    }
                }
                break;
            }
            case 4: {
                int index;
                cout << "Vnesi indeks (0-" << objekti.size() - 1 << "): ";
                cin >> index;
                if (index >= 0 && index < objekti.size()) {
                    objekti[index].pecatiDimenzii();
                } else {
                    cout << "Nevaliden indeks!\n";
                }
                break;
            }
            case 5: {
                if (objekti.empty()) {
                    cout << "Nema kreirani objekti.\n";
                } else {
                    Kvadar minKvadar(9999, 9999, 9999);
                    bool found = false;
                    for (const Kvadar& k : objekti) {
                        if (!k.eKocka() && (found == false || k.plostina() < minKvadar.plostina())) {
                            minKvadar = k;
                            found = true;
                        }
                    }
                    if (found) {
                        cout << "Objektot so najmala plostina koj ne e kocka:\n";
                        minKvadar.pecatiDimenzii();
                    } else {
                        cout << "Ne postoi objekt koj ne e kocka.\n";
                    }
                }
                break;
            }
            case 6: {
                exit = true;
                break;
            }
            default:
                cout << "Nevaliden izbor! Probajte povtorno.\n";
        }
    }

    return 0;
}

