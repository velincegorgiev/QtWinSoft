// 3.Формирај deque d од цели броеви. Потоа формирај vector v од елементите на d, но во обратен редослед. 

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    deque<int> d = {1, 2, 3, 4, 5};
    vector<int> v(d.rbegin(), d.rend());
    cout << "elementite na v vo obraten redosled:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

