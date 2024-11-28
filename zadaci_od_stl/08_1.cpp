// 1.Во една фирма платата на вработените се пресметува како производ од број на бодови и вредност на бод. 
// Вредноста на бодот е иста за сите вработени.Имплементирај класа Vraboten која содржи податочни членови 
// ime и bodovi. Напиши програма со која ќе се пресмета вкупната сума за да се исплати месечна плата за целата фирма. 
// Програмата треба да ја прикаже вкупната сума и список на вработените сортиран според бројот на бодови. 
// За пресметување на сумата да се употреби accumulate. За сортирање на листата да се употреби sort.  

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Vraboten {
public:
    string ime;
    int bodovi;
    Vraboten(string ime, int bodovi) : ime(ime), bodovi(bodovi) {}
    int platata(int vrednostNaBod) const {
        return bodovi * vrednostNaBod;
    }
};

int main() {
    int vrednostNaBod = 1000;
    vector<Vraboten> vraboteni = {
        Vraboten("veka", 120),
        Vraboten("veki", 150),
        Vraboten("verica", 100),
        Vraboten("velin", 130),
        Vraboten("velince", 140)
    };
    int vkupnaPlata = accumulate(vraboteni.begin(), vraboteni.end(), 0, [vrednostNaBod](int suma, const Vraboten& v) {
        return suma + v.platata(vrednostNaBod);
    });
    sort(vraboteni.begin(), vraboteni.end(), [](const Vraboten& v1, const Vraboten& v2) {
        return v1.bodovi > v2.bodovi;
    });
    cout << "vkupna suma za plata: " << vkupnaPlata << endl;
    cout << "spisok na vraboteni spored bodovi (od najgolemiot do najmaliot):\n";
    for (const auto& v : vraboteni) {
        cout << v.ime << " - bodovi: " << v.bodovi << " - plata: " << v.platata(vrednostNaBod) << endl;
    }
    return 0;
}

