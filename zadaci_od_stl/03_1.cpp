// 1.Напиши class template Zapis<T> кој содржи три приватни членки: x, y и z од тип Т. 
// Креирај function template kontrolor кој ќе проверува дали збирот на елементите x, y и z во 
// Zapis надминува 10000. Напиши соодветна програма за демонстрација со инстанцирање 
// на објекти од тип Zapis<int> и Zapis<double>.  

#include <iostream>

using namespace std;

template <typename T>
class Zapis {
private:
    T x, y, z;

public:
    Zapis(T xx, T yy, T zz){
        x=xx;
        y=yy;
        z=zz;
    }
    bool kontrolor() const {
        T sum = x + y + z;
        if (sum > 10000) {
            return true;
        } else {
            return false;
        }
    }
    void pecati() const {
        cout << "x: " << x << ", y: " << y << ", z: " << z << endl;
    }
};

int main() {
    Zapis<int> zapisInt(5000, 6000, 4000);
    zapisInt.pecati();
    if (zapisInt.kontrolor()) {
        cout << "zbirot na int elementi go nadminuva 10000." << endl;
    } else {
        cout << "zbirot na int elementi ne go nadminuva 10000." << endl;
    }
    Zapis<double> zapisDouble(4000.5, 3000.2, 3000.3);
    zapisDouble.pecati();
    if (zapisDouble.kontrolor()) {
        cout << "zbirot na double elementi go nadminuva 10000." << endl;
    } else {
        cout << "zbirot na double elementi ne go nadminuva 10000." << endl;
    }

    return 0;
}

