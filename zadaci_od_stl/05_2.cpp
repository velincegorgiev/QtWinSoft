// 2.Дадени се три листи од e-mail адреси. Некои адреси се појавуваат само во една од листите, 
// а некои се повторуваат и во другите листи. Напиши програма со која ќе се состави една листа 
// во која ќе се содржат сите адреси по еднаш.

#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> lista1 = {"velin@example.com", "verica@example.com", "veka@example.com"};
    vector<string> lista2 = {"veki@example.com", "velin@example.com", "velince@example.com"};
    vector<string> lista3 = {"win@example.com", "veka@example.com", "velince@example.com"};
    set<string> uniqueEmails;
    uniqueEmails.insert(lista1.begin(), lista1.end());
    uniqueEmails.insert(lista2.begin(), lista2.end());
    uniqueEmails.insert(lista3.begin(), lista3.end());
    cout << "unikatni e-mail adresi:" << endl;
    for (const string& email : uniqueEmails) {
        cout << email << endl;
    }

    return 0;
}

