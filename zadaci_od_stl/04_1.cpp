// 1.Напиши класа Imenik којa содржи ime и tel_broj. Креирај телефонски именик користејќи контејнер vector.   
// Прикажи го именикот во абецеден редослед.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Imenik {
public:
    string ime;
    string tel_broj;

    Imenik(string i, string t){
        ime=i;
        tel_broj=t;
    }
    void prikazi() const {
        cout << ime << " - " << tel_broj << endl;
    }
    bool operator < (const Imenik& other) const {
        return ime < other.ime;
    }
};

int main() {
    vector<Imenik> imenik;

    imenik.push_back(Imenik("Velin", "070123456"));
    imenik.push_back(Imenik("Verica", "075987654"));
    imenik.push_back(Imenik("Sarko", "071234567"));
    imenik.push_back(Imenik("Luna", "072345678"));

    sort(imenik.begin(), imenik.end());

    cout << "sortiran telefonski imenik:" << endl;
    for (const auto& entry : imenik) {
        entry.prikazi();
    }

    return 0;
}

