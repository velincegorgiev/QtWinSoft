// 1.Во една банка пристигаат уплати за штедачи. Напиши програма во која ќе се внесуваат податоци 
// за уплати и ќе се прикажува листа и вкупна уплата за даден штедач. Импламентирај класа Uplata 
// која содржи податоци за штедач и големина на уплата. Користи контејнер multimap. Програмата 
// треба да овозможува едноставно мени за внесување и прикажување на уплати. 
// 1.Додај уплата
// 2.Прикажи уплати за даден штедач
// 3.Крај

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Uplata {
public:
    string ime;
    double iznos;
    Uplata(const string& ime, double iznos) : ime(ime), iznos(iznos) {}
};
int main() {
    multimap<string, Uplata> uplati;
    int opcija;
    do {
        cout << "\nmeni:\n";
        cout << "1.dodaj uplata\n";
        cout << "2.prikazi uplata za daden stedac\n";
        cout << "3.kraj\n";
        cout << "izberete opcija: ";
        cin >> opcija;
        if (opcija == 1) {
            string ime;
            double iznos;
            cout << "vnesete ime na stedacot: ";
            cin >> ime;
            cout << "vnesete golemina na uplatata: ";
            cin >> iznos;
            uplati.insert({ime, Uplata(ime, iznos)});
            cout << "uplatata e uspesno dodadena.\n";
        } 
        else if (opcija == 2) {
            string ime;
            cout << "vnesete ime na stedacot za prikazuvanje na uplatata: ";
            cin >> ime;
            auto it = uplati.equal_range(ime);
            if (it.first != it.second) {
                cout << "uplati za " << ime << ":\n";
                double ukupno = 0;
                for (auto i = it.first; i != it.second; ++i) {
                    cout << "uplata: " << i->second.iznos << " denari\n";
                    ukupno += i->second.iznos;
                }
                cout << "vkupna uplata: " << ukupno << " denari\n";
            } else {
                cout << "nema uplati za stedacot " << ime << ".\n";
            }
        }
        else if (opcija == 3) {
            cout << "programata e zavrsena.\n";
        } else {
            cout << "nevalidna opcija, obidete se povtorno.\n";
        }
    } while (opcija != 3);

    return 0;
}

