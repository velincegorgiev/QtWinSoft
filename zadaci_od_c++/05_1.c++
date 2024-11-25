// 1. Во една зоолошка градина се води евиденција за различни типови животни кои се чуваат во неа:
// птици, влекачи, цицачи.... Користејќи ги концептите на ООП да се моделира класа според спецификациите
// дадени на слика 5.1. Цицачите се вакцинираат секоја година, птиците на секои 6 месеци, а влекачите 
//на секои 8 месеци. Датумите да се дефинираат во посебна класа Datum со приватни податочни членки den, 
//mesec и godina. Да се имплементира кориснички посредник преку мени со следните опции:
// 1.	Додавање на животно во зоолошка градина
// 2.	Прикажување на бројна состојба
// 3.	Прикажување на животни од дадена група (тип: c- цицачи, v-влекачи, p-птици)
// 4.	Прикажување на целата листа
// 5.	Прикажување на сите животни кои треба да се вакцинираат во рок од 1 недела
// 6.	Излез од менито

// Klasa: Zivotno
// Podatoci:
// Datum_na_ragjanje
// Datum_na_donesuvawe_vo_zoo
// tip
// Pol (m/z)
// Ime
// Datum_na_posledna_vakcinacija
// Metodi:
// Konstruktor()
// Prikazi_Podatoci()
// Presmetaj_vakcinacija()


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Datum {
private:
    int den, mesec, godina;

public:
    Datum(int d, int m, int g){
        den=d;
        mesec=m;
        godina=g;
    }
    Datum(){
        den=1;
        mesec=1;
        godina=2024;
    }

    void prikazi() const {
        cout << den << "/" << mesec << "/" << godina;
    }
    int razlikaDenovi(const Datum& d) const {
        return (godina - d.godina) * 365 + (mesec - d.mesec) * 30 + (den - d.den);
    }
};

class Zivotno {
private:
    Datum datum_na_ragjanje;
    Datum datum_na_donesuvawe_vo_zoo;
    char tip;
    char pol;
    string ime;
    Datum datum_na_posledna_vakcinacija;

public:
    Zivotno(Datum r, Datum d, char t, char p, string i, Datum v){
        datum_na_ragjanje=r;
        datum_na_donesuvawe_vo_zoo=d;
        tip=t;
        pol=p;
        ime=i;
        datum_na_posledna_vakcinacija=v;
    }

    void prikaziPodatoci() const {
        cout << "Ime: " << ime << ", Tip: " << tip << ", Pol: " << pol << ", Datum na ragjanje: ";
        datum_na_ragjanje.prikazi();
        cout << ", Datum na donesuvawe vo zoo: ";
        datum_na_donesuvawe_vo_zoo.prikazi();
        cout << ", Datum na posledna vakcinacija: ";
        datum_na_posledna_vakcinacija.prikazi();
        cout << endl;
    }

    bool trebaVakcinacija() const {
        Datum danesenDatum(25, 11, 2024); 
        int razlika = datum_na_posledna_vakcinacija.razlikaDenovi(danesenDatum);

        if (tip == 'c' && razlika >= 365) return true; 
        if (tip == 'v' && razlika >= 240) return true;
        if (tip == 'p' && razlika >= 180) return true;
        return false;
    }

    char getTip() const {
        return tip;
    }
};

class ZooloskaGradina {
private:
    vector<Zivotno> listaZivotni;

public:
    void dodadiZivotno(Zivotno z) {
        listaZivotni.push_back(z);
    }

    void prikaziBrojnaSostojba() const {
        int c = 0, v = 0, p = 0;
        for (const auto& z : listaZivotni) {
            if (z.getTip() == 'c') c++;
            else if (z.getTip() == 'v') v++;
            else if (z.getTip() == 'p') p++;
        }
        cout << "cicaci: " << c << ", vlekaci: " << v << ", ptici: " << p << endl;
    }

    void prikaziZivotniPoTipu(char tip) const {
        for (const auto& z : listaZivotni) {
            if (z.getTip() == tip) {
                z.prikaziPodatoci();
            }
        }
    }

    void prikaziZivotniKojiTrebaVakcinacija() const {
        for (const auto& z : listaZivotni) {
            if (z.trebaVakcinacija()) {
                z.prikaziPodatoci();
            }
        }
    }

    void prikaziCelokupnaLista() const {
        for (const auto& z : listaZivotni) {
            z.prikaziPodatoci();
        }
    }
};

int main() {
    ZooloskaGradina zoo;
    int izbor;

    do {
        cout << "Izbor meni:\n";
        cout << "1. Doadavanje na zivotno\n";
        cout << "2. Prikazuvanje na brojna sostojba\n";
        cout << "3. Prikazuvanje na zivotni od dadena grupa\n";
        cout << "4. Prikazuvanje na celata lista\n";
        cout << "5. Prikazuvanje na site zivotni koi treba da se vakciniraat\n";
        cout << "6. Izlez\n";
        cout << "Izbor: ";
        cin >> izbor;

        switch (izbor) {
        case 1: {
            Datum r(1, 1, 2020);
            Datum d(1, 1, 2021);
            Datum v(1, 1, 2023);
            Zivotno z(r, d, 'c', 'm', "Tigar", v);
            zoo.dodadiZivotno(z);
            break;
        }
        case 2:
            zoo.prikaziBrojnaSostojba();
            break;
        case 3:
            char tip;
            cout << "Vnesi tip na zivotno (c - cicaci, v - vlecaci, p - ptici): ";
            cin >> tip;
            zoo.prikaziZivotniPoTipu(tip);
            break;
        case 4:
            zoo.prikaziCelokupnaLista();
            break;
        case 5:
            zoo.prikaziZivotniKojiTrebaVakcinacija();
            break;
        case 6:
            cout << "Izlez od programot." << endl;
            break;
        default:
            cout << "Nepoznat izbor. Pobrza se." << endl;
        }
    } while (izbor != 6);

    return 0;
}
