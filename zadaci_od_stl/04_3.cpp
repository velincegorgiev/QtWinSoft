// 3. За текст внесен од тастатура прикажи ги сите зборови од кои се состои текстот по еднаш, во абецеден редослед. 

#include <iostream>
#include <sstream>
#include <set>
#include <string>

using namespace std;

int main() {
    string tekst;
    cout << "vnesete tekst: ";
    getline(cin, tekst);
    set<string> zborovi;
    stringstream ss(tekst);
    string zbor;
    while (ss >> zbor) {
        zborovi.insert(zbor);
    }
    cout << "unikatni zborovi vo azbucen redosled:" << endl;
    for (const string& z : zborovi) {
        cout << z << endl;
    }

    return 0;
}

