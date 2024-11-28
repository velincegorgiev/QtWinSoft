// 2.Напиши програма што определува дали два збора се анаграми. 
// Два збора се нарекуваат анаграми ако се состојат од исти букви (Пр. стакло и слатко). 
// Притоа користи vector. За споредба  на еднаквост на два вектори може да се користи:
//       std::equal( v1.begin(), v1.end(), v2.begin() );
// која враќа bool вредност.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool seAnegrami(const string& zbor1, const string& zbor2) {
    if (zbor1.size() != zbor2.size()) {
        return false;
    }
    vector<char> vektor1(zbor1.begin(), zbor1.end());
    vector<char> vektor2(zbor2.begin(), zbor2.end());
    sort(vektor1.begin(), vektor1.end());
    sort(vektor2.begin(), vektor2.end());
    return equal(vektor1.begin(), vektor1.end(), vektor2.begin());
}

int main() {
    string zbor1, zbor2;
    cout << "vnesi prv zbor: ";
    cin >> zbor1;
    cout << "vnesi vtor zbor: ";
    cin >> zbor2;

    // Проверка дали се анаграми
    if (seAnegrami(zbor1, zbor2)) {
        cout << "zborovite se anagrimi." << endl;
    } else {
        cout << "zborovite ne se anagrimi." << endl;
    }

    return 0;
}

