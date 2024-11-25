// Во една продавница се води евиденција за артиклите кои се продаваат во неа: пантолони и кошули. 
// Користејќи ги концептите на ООП да се моделираат соодветни класи според спецификациите дадени на сликата. 
// Пратката на пантолони доаѓа секој месец, а нарачки на кошули се прават по потреба. 
// Во main() функцијата да се конструира низа од долунаведените класи (пантолони, кошули) и да се имплементира
//  кориснички посредник преку мени со следните опции:
// 1.      Додавање на артикл во листата
// 2.      Прикажување на артикли од дадена група
// 3.      Прикажување на целата листа (со вкупна цена)
// 4.      Прикажување на сите артикли кои треба да се набават во рок од 1 недела и пари кои треба да
//  се потрошат за да се набават потребните артикли
// 5.      Излез од менито

// Приватната членка Donesen_vo_prodavnica е од тип Datum кој треба да се дефинира во посебна класа.

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Datum {
public:
    int day, month, year;

    Datum(){
        day=0;
        month=0;
        year=0;
    }

    Datum(int d, int m, int y){
        day=d;
        month=m;
        year=y;
    }

    void prikaziDatum() const {
        cout << day << "/" << month << "/" << year;
    }
};

class Artikl {
protected:
    char ime_na_artikl[50];
    char golemina[20];
    double cena;
    Datum doneseno_vo_prodavnica;

public:
    Artikl(const char* ime = "", const char* g = "", double c = 0.0, Datum d = Datum()) {
        strcpy(ime_na_artikl, ime);
        strcpy(golemina, g);
        cena = c;
        doneseno_vo_prodavnica = d;
    }

    virtual void prikaziPodatoci() const {
        cout << "Ime: " << ime_na_artikl << ", Golemina: " << golemina << ", Cena: " << cena << ", Doneseno: ";
        doneseno_vo_prodavnica.prikaziDatum();
        cout << endl;
    }

    virtual void presmetajNabavka() const {}

    double getCena() const {
        return cena;
    }
};

class Pantoloni : public Artikl {
private:
    Datum datum_na_sledna_nabavka;

public:
    Pantoloni(const char* ime, const char* g, double c, Datum d, Datum ds)
        : Artikl(ime, g, c, d){
            datum_na_sledna_nabavka=ds;
        }

    void prikaziPodatoci() const override {
        Artikl::prikaziPodatoci();
        cout << "Datum na sledna nabavka: ";
        datum_na_sledna_nabavka.prikaziDatum();
        cout << endl;
    }

    void presmetajNabavka() const override {
        if (datum_na_sledna_nabavka.year == 2024 && datum_na_sledna_nabavka.month == 11 && datum_na_sledna_nabavka.day <= 21) {
            cout << "Pantoloni " << ime_na_artikl << " treba da se nabavat." << endl;
        }
    }
};

class Kosuli : public Artikl {
public:
    Kosuli(const char* ime, const char* g, double c, Datum d)
        : Artikl(ime, g, c, d) {}

    void prikaziPodatoci() const override {
        Artikl::prikaziPodatoci();
    }

    void presmetajNabavka() const override {
        cout << "Kosuli " << ime_na_artikl << " treba da se nabavat po potreba." << endl;
    }
};

int main() {
    vector<Artikl*> artikli;
    int opcija;

    do {
        cout << "\n1. Dodavanje na artikl\n";
        cout << "2. Prikazuvanje na artikli\n";
        cout << "3. Prikazuvanje na celata lista\n";
        cout << "4. Prikazuvanje na nabavki\n";
        cout << "5. Izlez\n";
        cout << "Izberi opcija: ";
        cin >> opcija;
        cin.ignore();

        if (opcija == 1) {
            int tip;
            cout << "Izberi tip na artikl (1. Pantoloni, 2. Kosuli): ";
            cin >> tip;
            cin.ignore();

            char ime[50], golemina[20];
            double cena;
            int d, m, y, ds_d, ds_m, ds_y;

            switch (tip) {
                case 1:
                    cout << "Vnesi ime, golemina, cena, datum na doneseno (d m g), datum na sledna nabavka (d m g): ";
                    cin.getline(ime, 50);
                    cin.getline(golemina, 20);
                    cin >> cena >> d >> m >> y >> ds_d >> ds_m >> ds_y;
                    cin.ignore();
                    artikli.push_back(new Pantoloni(ime, golemina, cena, Datum(d, m, y), Datum(ds_d, ds_m, ds_y)));
                    break;
                case 2:
                    cout << "Vnesi ime, golemina, cena, datum na doneseno (d m g): ";
                    cin.getline(ime, 50);
                    cin.getline(golemina, 20);
                    cin >> cena >> d >> m >> y;
                    cin.ignore();
                    artikli.push_back(new Kosuli(ime, golemina, cena, Datum(d, m, y)));
                    break;
            }
        } else if (opcija == 2) {
            for (auto& artikl : artikli) {
                artikl->prikaziPodatoci();
            }
        } else if (opcija == 3) {
            double vkupnaCena = 0;
            for (auto& artikl : artikli) {
                artikl->prikaziPodatoci();
                vkupnaCena += artikl->getCena();
            }
            cout << "Vkupna cena: " << vkupnaCena << endl;
        } else if (opcija == 4) {
            for (auto& artikl : artikli) {
                artikl->presmetajNabavka();
            }
        } else if (opcija == 5) {
            cout << "Izlez.\n";
        } else {
            cout << "Nepoznata opcija.\n";
        }
    } while (opcija != 5);

    for (auto& artikl : artikli) {
        delete artikl;
    }

    return 0;
}
