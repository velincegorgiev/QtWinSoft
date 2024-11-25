// 1. Создади класа Dropki која извршува операции со дропки. Напиши „драјвер“ за твојот програм да манипулира со оваа класа.

// Користи целоборјни променливи за броител и именител кои мора да се приватни. Обезбеди потребен број на контруктори 
// кои нема да дозволат дефинирање на грешни вредности (со 0 не се дели). По секоја од наредните операции, дропката 
// треба да се зачува во редуцирана форма, т.е дропката 2/4 треба да се зачува како 1/2. Обезбеди ги следните 
// операторски функции членки:
// 	а) Собирање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма.
// 	б) Одземање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
// 	в) Множење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
// 	г) Делење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
// 	д) Собирање на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.
// 	ѓ) Одземање на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.
// 	е) Множење на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.
// 	ж) Делење на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.

// Да се обезбедат и следните функции членки на класата:
// 	з) Печатење на објектот во форма a/b.
// 	ѕ) Печатење на објектот во форма на реален број.

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

    Dropki operator + (int n) {
        int b = broitel + n * imenitel;
        Dropki result(b, imenitel);
        return result;
    }

    Dropki operator - (int n) {
        int b = broitel - n * imenitel;
        Dropki result(b, imenitel);
        return result;
    }

    Dropki operator * (int n) {
        int b = broitel * n;
        Dropki result(b, imenitel);
        return result;
    }

    Dropki operator / (int n) {
        if (n == 0) {
            cout << "ne moze da se deli so 0!" << endl;
            return Dropki();
        }
        int b = broitel;
        int i = imenitel * n;
        Dropki result(b, i);
        return result;
    }

    friend ostream& operator<<(ostream& os, const Dropki& d) {
        os << d.broitel << "/" << d.imenitel;
        return os;
    }

    void printAsReal() const {
        cout << (double)broitel / imenitel << endl;
    }
};

int main() {
    Dropki d1(2, 4);
    Dropki d2(3, 5);
    cout << "Dropka 1: ";
    cout << d1 << endl;
    cout << "Dropka 1 kako realen broj: ";
    d1.printAsReal();

    cout << "Dropka 2: ";
    cout << d2 << endl;
    cout << "Dropka 2 kako realen broj: ";
    d2.printAsReal();

    Dropki zbir = d1 + d2;
    cout << "sobiranje: ";
    cout << zbir << endl;

    Dropki razlika = d1 - d2;
    cout << "odzemanje: ";
    cout << razlika << endl;

    Dropki proizvod = d1 * d2;
    cout << "mnozenje: ";
    cout << proizvod << endl;

    Dropki kolicnik = d1 / d2;
    cout << "delenje: ";
    cout << kolicnik << endl;

    Dropki zbirCe = d1 + 3;
    cout << "sobiranje so cel broj: ";
    cout << zbirCe << endl;

    Dropki razlikaCe = d1 - 2;
    cout << "odzemanje so cel broj: ";
    cout << razlikaCe << endl;

    Dropki proizvodCe = d1 * 4;
    cout << "mnozenje so cel broj: ";
    cout << proizvodCe << endl;

    Dropki kolicnikCe = d1 / 2;
    cout << "delenje so cel broj: ";
    cout << kolicnikCe << endl;

    return 0;
}

