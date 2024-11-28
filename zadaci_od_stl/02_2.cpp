// 2.Креирај класа Kvadrat со податоци strana и класа Pravoagolnik со податоци sirina и dolzina.  
// Напиши function template sortirajPole со кој се врши сортирање на поле и function template pecatiPole 
// со кој се врши печатење на поле. Во main креирај две полиња од квадрати и праваголници, прикажи ги 
// со pecatiPole, сортирај ги според плоштина со sortirajPole и повторно отпечати ги. 

#include <iostream>
#include <algorithm>

using namespace std;

class Kvadrat {
private:
    double strana;
public:
    Kvadrat(double s) : strana(s) {}

    double ploshtina() const {
        return strana * strana;
    }

    void pecati() const {
        cout << "kvadrat - strana: " << strana << ", ploshtina: " << ploshtina() << endl;
    }
};
class Pravoagolnik {
private:
    double sirina, dolzina;
public:
    Pravoagolnik(double s, double d) : sirina(s), dolzina(d) {}

    double ploshtina() const {
        return sirina * dolzina;
    }
    void pecati() const {
        cout << "pravoagolnik - sirina: " << sirina << ", dolzina: " << dolzina << ", ploshtina: " << ploshtina() << endl;
    }
};

template <typename T>
void sortirajPole(T arr[], int size) {
    sort(arr, arr + size, [](const T& a, const T& b) {
        return a.ploshtina() < b.ploshtina();
    });
}

template <typename T>
void pecatiPole(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i].pecati();
    }
}

int main() {
    Kvadrat kvadrati[] = { Kvadrat(5), Kvadrat(3), Kvadrat(7) };
    int kvadratiSize = sizeof(kvadrati) / sizeof(kvadrati[0]);
    cout << "pocetna sostojba na kvadrati:" << endl;
    pecatiPole(kvadrati, kvadratiSize);
    sortirajPole(kvadrati, kvadratiSize);
    cout << "\npo soratiranje na kvadrati:" << endl;
    pecatiPole(kvadrati, kvadratiSize);
    Pravoagolnik pravoagolnici[] = { Pravoagolnik(5, 10), Pravoagolnik(3, 4), Pravoagolnik(6, 8) };
    int pravoagolniciSize = sizeof(pravoagolnici) / sizeof(pravoagolnici[0]);
    cout << "\npocetna sostojba na pravoagolnici:" << endl;
    pecatiPole(pravoagolnici, pravoagolniciSize);
    sortirajPole(pravoagolnici, pravoagolniciSize);
    cout << "\npo soratiranje na pravoagolnici:" << endl;
    pecatiPole(pravoagolnici, pravoagolniciSize);

    return 0;
}

