// 3.Една фирма води евиденција за лица кои можат да бидат вработени или клиенти. 
// За секое лице се чуваат следните податоци:  imeiprezime, mat_br, vozrast, adresa, kod. 
// За вработените kod има целобројна вредност, а за клиентите е низа од знаци.
// Креирај class template Lica во која ќе се сместуваат податоците за лица. 
// Податоците кои се низи од знаци да се внесуваат преку динамичка алокација на меморија. 
// Креирај две полиња од објекти, Vraboteni и Klienti. За печатење на двете полиња употреби 
// ја pecatiPole од претходната задача. 
// Напиши тест програма која содржи мени: 
// 1.Внесување на податоци за вработен
// 2.Внесување на податоци за клиент
// 3.Печетење на листа на вработени
// 4.Печатење на листа на клиенти
// 5.Крај

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

template <typename T>
class Lica {
private:
    string imeiprezime;
    string mat_br;
    int vozrast;
    string adresa;
    T kod;

public:
    Lica(string ime, string matBr, int vozrast, string a, T k){
        imeiprezime=ime;
        mat_br=matBr;
        vozrast=vozrast;
        adresa=a;
        kod=k; 
    }

    void pecati() const {
        cout << "ime i prezime: " << imeiprezime << ", maticen broj: " << mat_br
             << ", vozrast: " << vozrast << ", adresa: " << adresa << ", kod: " << kod << endl;
    }
    T getKod() const {
        return kod;
    }
};
template <typename T>
void pecatiPole(const vector<Lica<T>>& arr) {
    for (const auto& lica : arr) {
        lica.pecati();
    }
}
int main() {
    vector<Lica<int>> Vraboteni;
    vector<Lica<string>> Klienti;
    int izbor;
    string ime, mat_br, adresa;
    int vozrast, kodInt;
    string kodString;

    while (true) {
        cout << "\nmeni: \n";
        cout << "1.vnesuvanje na podatoci za vraboteni\n";
        cout << "2.vnesuvanje na podatoci za klienti\n";
        cout << "3.pecatenje na lista na vraboteni\n";
        cout << "4.pecatenje na lista na klienti\n";
        cout << "5.kraj\n";
        cout << "izberi opcija: ";
        cin >> izbor;

        if (izbor == 1) {
            cout << "vnesi ime: ";
            cin >> ime;
            cout << "vnesi maticen broj: ";
            cin >> mat_br;
            cout << "vnesi vozrast: ";
            cin >> vozrast;
            cout << "vnesi adresa: ";
            cin >> adresa;
            cout << "vnesi kod (celebrojna vrednost): ";
            cin >> kodInt;
            Vraboteni.push_back(Lica<int>(ime, mat_br, vozrast, adresa, kodInt));
        } else if (izbor == 2) {
            cout << "vnesi ime: ";
            cin >> ime;
            cout << "vnesi maticen broj: ";
            cin >> mat_br;
            cout << "vnesi vozrast: ";
            cin >> vozrast;
            cout << "vnesi adresa: ";
            cin >> adresa;
            cout << "vnesi kod (niza od znaci): ";
            cin >> kodString;

            Klienti.push_back(Lica<string>(ime, mat_br, vozrast, adresa, kodString));

        } else if (izbor == 3) {
            cout << "\nlista na vraboteni:\n";
            pecatiPole(Vraboteni);
        } else if (izbor == 4) {
            cout << "\nlista na klienti:\n";
            pecatiPole(Klienti);
        } else if (izbor == 5) {
            break;
        } else {
            cout << "nepoznata opcija probaj povtorno.\n";
        }
    }

    return 0;
}

