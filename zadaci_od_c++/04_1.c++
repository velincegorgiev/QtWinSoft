// 1. Создади класа Dropki која извршува операции со дропки. Напиши „драјвер“ за твојот програм да манипулира со оваа класа.

// Користи целоборјни променливи за броител и именител кои мора да се приватни. Обезбеди потребен број 
// на контруктори кои нема да дозволат дефинирање на грешни вредности (со 0 не се дели!).
//  По секоја од наредните операции, дропката треба да се зачува во редуцирана форма, т.е дропката 2/4 
//  треба да се зачува како 1/2. Обезбеди ги следните јавни функции членки:
// 	а) Собирање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма.
// 	б) Одземање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
// 	в) Множење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
// 	г) Делење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
// 	д) Печатење на објектот во форма a/b.
// 	ѓ) Печатење на објектот во форма на реален број.

#include<iostream>
#include <algorithm>
using namespace std;

class Dropki {
private:
    int broitel, imenitel;

    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    void redukcija() {
        int gcd_val = gcd(broitel, imenitel);
        broitel /= gcd_val;
        imenitel /= gcd_val;

        if (imenitel < 0) {
            broitel = -broitel;
            imenitel = -imenitel;
        }
    }

public:
    Dropki(int b, int i) {
        if (i != 0) {
            broitel = b;
            imenitel = i;
            redukcija();
        } else {
            cout << "ne moze da se deli so 0!" << endl;
            broitel = 1;
            imenitel = 1;
        }
    }

    Dropki() {
        broitel = 1;
        imenitel = 1;
    }

    Dropki operator + (const Dropki& d) {
        int b = broitel * d.imenitel + imenitel * d.broitel;
        int i = imenitel * d.imenitel;
        Dropki result(b, i);
        return result;
    }

    Dropki operator - (const Dropki& d) {
        int b = broitel * d.imenitel - imenitel * d.broitel;
        int i = imenitel * d.imenitel;

        if (b < 0 && i < 0) {
            b = -b;
            i = -i;
        }

        Dropki result(b, i);
        return result;
    }

    Dropki operator * (const Dropki& d) {
        int b = broitel * d.broitel;
        int i = imenitel * d.imenitel;
        Dropki result(b, i);
        return result;
    }

    Dropki operator / (const Dropki& d) {
        if (d.broitel == 0) {
            cout << "ne moze da se deli so 0!" << endl;
            return Dropki();
        }
        int b = broitel * d.imenitel;
        int i = imenitel * d.broitel;
        Dropki result(b, i);
        return result;
    }

    void pecati() const {
        cout << broitel << "/" << imenitel << endl;
    }

    void pecatiReal() const {
        cout << (double)broitel / imenitel << endl;
    }
};

int main() {
    Dropki d1(2, 4);
    Dropki d2(3, 5);

    cout << "dropka 1: ";
    d1.pecati();
    cout << "dropka 1 vo realen broj: ";
    d1.pecatiReal();

    cout << "dropka 2: ";
    d2.pecati();
    cout << "dropka 2 vo realen broj: ";
    d2.pecatiReal();

    Dropki zbir = d1 + d2;
    cout << "sobiranje: ";
    zbir.pecati();

    Dropki razlika = d1 - d2;
    cout << "odzemanje: ";
    razlika.pecati();

    Dropki proizvod = d1 * d2;
    cout << "mnozenje: ";
    proizvod.pecati();

    Dropki kolicnik = d1 / d2;
    cout << "delenje: ";
    kolicnik.pecati();

    return 0;
}
