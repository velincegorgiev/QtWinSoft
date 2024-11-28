// 1.Напиши function template palindrom кој има параметар vector и враќа true ако векторот е палиндром, а false во спротивно. 

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
bool palindrom(const vector<T>& v) {
    int i = 0;
    int j = v.size() - 1;
    while (i < j) {
        if (v[i] != v[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    vector<int> v1 = {1, 2, 3, 2, 1};
    if (palindrom(v1)) {
        cout << "vektorot e palindrom." << endl;
    } else {
        cout << "vektorot ne e palindrom." << endl;
    }
    vector<string> v2 = {"mak", "smes", "smes", "mak"};
    if (palindrom(v2)) {
        cout << "vektorot e palindrom." << endl;
    } else {
        cout << "vektorot ne e palindrom." << endl;
    }

    return 0;
}

