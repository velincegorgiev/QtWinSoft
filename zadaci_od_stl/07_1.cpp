// 1.Креирај листа од 10000 случајни цели броеви co вредности од 0 до 9999. Потоа прикажи ги следните вредности: 
// -број на парни елементи
// -број на елементи помали од 2000
// -број на елементи во интервал [2000, 4000)
// -број на елементи во интервал [4000, 6000)
// -број на елементи во интервал [6000, 8000)
// -број на елементи во интервал [8000, 10000)
// -средна вредност на елементите

#include <iostream>
#include <vector>
#include <random>
#include <numeric>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 9999);
    vector<int> lista(10000);
    for (int i = 0; i < 10000; ++i) {
        lista[i] = dis(gen);
    }
    int brojParni = 0;
    int brojPomaliOd2000 = 0;
    int broj2000Do4000 = 0;
    int broj4000Do6000 = 0;
    int broj6000Do8000 = 0;
    int broj8000Do10000 = 0;
    int suma = 0;
    for (int i = 0; i < 10000; ++i) {
        int broj = lista[i];
        suma += broj;
        if (broj % 2 == 0) {
            brojParni++;
        }
        if (broj < 2000) {
            brojPomaliOd2000++;
        } else if (broj >= 2000 && broj < 4000) {
            broj2000Do4000++;
        } else if (broj >= 4000 && broj < 6000) {
            broj4000Do6000++;
        } else if (broj >= 6000 && broj < 8000) {
            broj6000Do8000++;
        } else if (broj >= 8000 && broj < 10000) {
            broj8000Do10000++;
        }
    }
    double srednaVrednost = suma / 10000.0;
    cout << "brojot na parni elementi: " << brojParni << endl;
    cout << "brojot na elementi pomali od 2000: " << brojPomaliOd2000 << endl;
    cout << "brojot na elementi vo interval [2000, 4000): " << broj2000Do4000 << endl;
    cout << "brojot na elementi vo interval [4000, 6000): " << broj4000Do6000 << endl;
    cout << "brojot na elementi vo interval [6000, 8000): " << broj6000Do8000 << endl;
    cout << "brojot na elementi vo interval [8000, 10000): " << broj8000Do10000 << endl;
    cout << "sredna vredbost na elementite: " << srednaVrednost << endl;

    return 0;
}

