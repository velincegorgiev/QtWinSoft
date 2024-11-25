// 1. Создади класа Stedac во која ќе користиш статичка податочна членка kamata која ќе ја 
// чува вредноста на годишната камата за сите штедачи и статична податочна членка brojStedaci
//  кој во секој момент кажува колку штедачи има во банката. Останатите податочни членки се lice,
//   bilans и kredit. Името, презимето, адресата и телефонот на секој објeкт од класата Stedac  
//   се сместени во приватна податочна членка lice која е од класaта Covek. 

#include <iostream>
#include <string>
using namespace std;

class Covek {
private:
    string ime;
    string prezime;
    string adresa;
    string telefon;

public:
    Covek(string i, string p, string a, string t) {
        ime = i;
        prezime = p;
        adresa = a;
        telefon = t;
    }

    void prikaziLice() const {
        cout << "Ime: " << ime << ", Prezime: " << prezime
             << ", Adresa: " << adresa << ", Telefon: " << telefon << endl;
    }

    friend class Stedac;
};

class Stedac : public Covek {
private:
    double bilans;
    double kredit;

public:
    static double kamata;
    static int brojStedaci;

    Stedac(string ime, string prezime, string adresa, string telefon, double b, double k)
        : Covek(ime, prezime, adresa, telefon) {
        bilans = b;
        kredit = k;
        brojStedaci++;
    }

    void prikaziPodatoci() const {
        prikaziLice();
        cout << "Bilans: " << bilans << ", Kredit: " << kredit << endl;
    }

    static void prikaziBrojStedaci() {
        cout << "Broj na stedaci: " << brojStedaci << endl;
    }

    void presmetajKamatu() const {
        double kamataZaBilans = bilans * kamata / 100;
        cout << "Kamata na bilans: " << kamataZaBilans << endl;
    }

    static void postaviKamatu(double novaKamata) {
        kamata = novaKamata;
    }

    static Stedac* kreirajStedac(string ime, string prezime, string adresa, string telefon, double b, double k) {
        return new Stedac(ime, prezime, adresa, telefon, b, k);
    }
};

double Stedac::kamata = 5.0;
int Stedac::brojStedaci = 0;

int main() {

    Stedac* s1 = Stedac::kreirajStedac("Ivan", "Petrov", "Skopje, GTC", "070123456", 1000.0, 500.0);
    Stedac* s2 = Stedac::kreirajStedac("Ana", "Dimova", "Bitola, Glavna", "071234567", 2000.0, 1000.0);

    s1->prikaziPodatoci();
    s2->prikaziPodatoci();

    Stedac::prikaziBrojStedaci();

    s1->presmetajKamatu();
    s2->presmetajKamatu();

    Stedac::postaviKamatu(7.5);
    cout << "Nova kamata: " << Stedac::kamata << "%" << endl;

    s1->presmetajKamatu();
    s2->presmetajKamatu();

    delete s1;
    delete s2;

    return 0;
}
