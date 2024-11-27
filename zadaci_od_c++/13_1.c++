// Во една зоолошка градина се води евиденција за животните кои се чуваат во неа: птици, 
// влекачи и цицачи. Користејќи ги концептите на ООП да се моделираат соодветни класи 
// според спецификациите дадени на слика 1. Цицачите се вакцинираат секоја година, птиците 
// на секои 6 месеци, а за влекачите овој податок варира. Во main() функцијата да се конструира 
// низа од долунаведените класи (влекачи, птици и цицачи) и да се имплементира кориснички посредник 
// преку мени со следните опции:
// 1.	Додавање на животно во листата
// 2.	Прикажување на бројна состојба
// 3.	Прикажување на животни од дадена група
// 4.	Прикажување на целата листа
// 5.	Прикажување на сите животни кои треба да се вакцинираат во рок од 1 недела
// 6.	Излез од менито

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Zivotno {
protected:
    string datum_na_ragjanje;
    string datum_na_donesuvawe_vo_zoo;
    char pol;
    string ime;
    string datum_na_posledna_vakcinacija;

public:
    Zivotno() {
        datum_na_ragjanje = "";
        datum_na_donesuvawe_vo_zoo = "";
        pol = 'm';
        ime = "";
        datum_na_posledna_vakcinacija = "";
    }

    Zivotno(string datum_ragjanje, string datum_donesuvawe, char pol, string ime, string datum_vakcinacija) {
        this->datum_na_ragjanje = datum_ragjanje;
        this->datum_na_donesuvawe_vo_zoo = datum_donesuvawe;
        this->pol = pol;
        this->ime = ime;
        this->datum_na_posledna_vakcinacija = datum_vakcinacija;
    }

    virtual void prikaziPodatoci() {
        cout << "Ime: " << ime << ", Pol: " << pol << ", Datum na ragjanje: " << datum_na_ragjanje
             << ", Datum na donesuvanje: " << datum_na_donesuvawe_vo_zoo
             << ", Posledna vakcinacija: " << datum_na_posledna_vakcinacija << endl;
    }

    virtual void presmetajVakcinacija() = 0;

    bool trebaVakcinacijaZa1Nedelja() {
        return true;
    }
};

class Vlekaci : public Zivotno {
private:
    string datum_na_sledna_vakcinacija;

public:
    Vlekaci() {
        datum_na_sledna_vakcinacija = "";
    }

    Vlekaci(string datum_ragjanje, string datum_donesuvawe, char pol, string ime, string datum_vakcinacija, string datum_sledna_vakcinacija)
        : Zivotno(datum_ragjanje, datum_donesuvawe, pol, ime, datum_vakcinacija) {
        this->datum_na_sledna_vakcinacija = datum_sledna_vakcinacija;
    }

    void prikaziPodatoci() override {
        Zivotno::prikaziPodatoci();
        cout << "Datum na sledna vakcinacija: " << datum_na_sledna_vakcinacija << endl;
    }

    void presmetajVakcinacija() override {
        cout << "Vlekacite treba da se vakciniraat: " << datum_na_sledna_vakcinacija << endl;
    }
};

class Ptici : public Zivotno {
private:
    char letac;

public:
    Ptici() {
        letac = 'n';
    }

    Ptici(string datum_ragjanje, string datum_donesuvawe, char pol, string ime, string datum_vakcinacija, char letac)
        : Zivotno(datum_ragjanje, datum_donesuvawe, pol, ime, datum_vakcinacija) {
        this->letac = letac;
    }

    void prikaziPodatoci() override {
        Zivotno::prikaziPodatoci();
        cout << "Letac: " << letac << endl;
    }

    void presmetajVakcinacija() override {
        cout << "pticata treba da se vakcinira na sekoi 6 meseci." << endl;
    }
};

class Cicaci : public Zivotno {
private:
    char prezivar;

public:
    Cicaci() {
        prezivar = 'n';
    }

    Cicaci(string datum_ragjanje, string datum_donesuvawe, char pol, string ime, string datum_vakcinacija, char prezivar)
        : Zivotno(datum_ragjanje, datum_donesuvawe, pol, ime, datum_vakcinacija) {
        this->prezivar = prezivar;
    }

    void prikaziPodatoci() override {
        Zivotno::prikaziPodatoci();
        cout << "Prezivar: " << prezivar << endl;
    }

    void presmetajVakcinacija() override {
        cout << "cicacite treba da se vakciniraat na sekoja godina." << endl;
    }
};

int main() {
    vector<Zivotno*> zivotni;
    int opcija;

    do {
        cout << "1. Dadaj zivotno vo listata" << endl;
        cout << "2. Prikazi brojna sostojba" << endl;
        cout << "3. Prikazi zivotni od dadena grupa" << endl;
        cout << "4. Prikazi celata lista" << endl;
        cout << "5. Prikazi site zivotni koi treba da se vakciniraat vo rok od 1 nedela" << endl;
        cout << "6. Izlez" << endl;
        cout << "Vnesi opcija: ";
        cin >> opcija;

        switch (opcija) {
        case 1: {
            string datum_ragjanje, datum_donesuvawe, ime, datum_vakcinacija;
            char pol;
            cout << "Vnesi datum na ragjanje: ";
            cin >> datum_ragjanje;
            cout << "Vnesi datum na donesuvanje vo zoo: ";
            cin >> datum_donesuvawe;
            cout << "Vnesi pol (m/z): ";
            cin >> pol;
            cout << "Vnesi ime: ";
            cin >> ime;
            cout << "Vnesi datum na posledna vakcinacija: ";
            cin >> datum_vakcinacija;


            char letac;
            cout << "Letac (d/n): ";
            cin >> letac;
            Ptici* ptica = new Ptici(datum_ragjanje, datum_donesuvawe, pol, ime, datum_vakcinacija, letac);
            zivotni.push_back(ptica);

            break;
        }
        case 2:
            cout << "Brojna sostojba: " << zivotni.size() << " zivotni" << endl;
            break;
        case 3: {
            break;
        }
        case 4:
            for (auto& zivotno : zivotni) {
                zivotno->prikaziPodatoci();
            }
            break;
        case 5:
            for (auto& zivotno : zivotni) {
                if (zivotno->trebaVakcinacijaZa1Nedelja()) {
                    zivotno->prikaziPodatoci();
                }
            }
            break;
        case 6:
            cout << "Izlez..." << endl;
            break;
        default:
            cout << "Nepoznata opcija!" << endl;
        }
    } while (opcija != 6);

    for (auto& zivotno : zivotni) {
        delete zivotno;
    }

    return 0;
}
