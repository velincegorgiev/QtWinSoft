// 2.      Креирај class template Mnozestvo<T> во со функции членки за додавање, прикажување на 
// елементи на множеството и определување на најголем елемент во множеството. Како податочна структура 
// за сместување на елементите на множеството може да се користи поле. Секој елемент може да се појави 
// само еднаш. Секое множество содржи static компонента во која е сместен бројот на елементи на множеството. 
// Креирај три множества: А од int, B од double и C од char*. Користи соодветна специјализација за 
// коректно определување на најголем елемент во множеството од стрингови. Програмата треба да 
// имплементира мени со следните опции:
 
// 1.      Додај елемент во А
// 2.      Додај елемент во B
// 3.      Додај елемент во C
// 4.      Прикажи го А
// 5.      Прикажи го B
// 6.      Прикажи го C
// 7.      Прикажи најголеми елементи
// 8.      Прикажи број на елементи во множествата
// 9.      Крај

#include <iostream>
#include <cstring>

using namespace std;
template <typename T>
class Mnozestvo {
private:
    T elements[100];
    static int count;
public:
    void addElement(const T& element) {
        for (int i = 0; i < count; ++i) {
            if (elements[i] == element) {
                cout << "elementot veke postoi vo mnozestvoto!" << endl;
                return;
            }
        }
        if (count < 100) {
            elements[count++] = element;
        } else {
            cout << "mnozestvoto e polno!" << endl;
        }
    }
    void print() const {
        cout << "elementi vo mnozestvoto: ";
        for (int i = 0; i < count; ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
    T getMax() const {
        T max = elements[0];
        for (int i = 1; i < count; ++i) {
            if (elements[i] > max) {
                max = elements[i];
            }
        }
        return max;
    }
    static int getCount() {
        return count;
    }
};
template <typename T>
int Mnozestvo<T>::count = 0;
template <>
class Mnozestvo<char*> {
private:
    char* elements[100];
    static int count;
public:
    void addElement(char* element) {
        for (int i = 0; i < count; ++i) {
            if (strcmp(elements[i], element) == 0) {
                cout << "elementot veke ne postoi vo mnozestvoto!" << endl;
                return;
            }
        }
        if (count < 100) {
            elements[count++] = element;
        } else {
            cout << "mnozestvoto e polno!" << endl;
        }
    }
    void print() const {
        cout << "elementite vo mnozestvoto: ";
        for (int i = 0; i < count; ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
    char* getMax() const {
        char* max = elements[0];
        for (int i = 1; i < count; ++i) {
            if (strcmp(elements[i], max) > 0) {
                max = elements[i];
            }
        }
        return max;
    }
    static int getCount() {
        return count;
    }
};
int Mnozestvo<char*>::count = 0;
int main() {
    Mnozestvo<int> A;
    Mnozestvo<double> B;
    Mnozestvo<char*> C;

    int option;
    do {
        cout << "\nmeni:\n";
        cout << "1. dodaj element vo A\n";
        cout << "2. dodaj element vo B\n";
        cout << "3. dodaj element vo C\n";
        cout << "4. prikazi go A\n";
        cout << "5. prikazi go B\n";
        cout << "6. prikazi go C\n";
        cout << "7. prikazi gi najgolemite elementi\n";
        cout << "8. prikazi go brojot na elementi vo mnozestvata\n";
        cout << "9. kraj\n";
        cout << "izberi opcija: ";
        cin >> option;

        switch(option) {
            case 1: {
                int elem;
                cout << "vnesi element za A: ";
                cin >> elem;
                A.addElement(elem);
                break;
            }
            case 2: {
                double elem;
                cout << "vnesi element za B: ";
                cin >> elem;
                B.addElement(elem);
                break;
            }
            case 3: {
                char* elem = new char[100];
                cout << "vnesi element za C: ";
                cin >> elem;
                C.addElement(elem);
                break;
            }
            case 4:
                A.print();
                break;
            case 5:
                B.print();
                break;
            case 6:
                C.print();
                break;
            case 7:
                cout << "najgolem element vo A: " << A.getMax() << endl;
                cout << "najgolem element vo B: " << B.getMax() << endl;
                cout << "najgolem element vo C: " << C.getMax() << endl;
                break;
            case 8:
                cout << "brojot na elementi vo A: " << Mnozestvo<int>::getCount() << endl;
                cout << "brojot na elementi vo B: " << Mnozestvo<double>::getCount() << endl;
                cout << "brojot na elementi vo C: " << Mnozestvo<char*>::getCount() << endl;
                break;
            case 9:
                cout << "izleguvate od programata." << endl;
                break;
            default:
                cout << "nevalidna opcija!" << endl;
        }
    } while (option != 9);

    return 0;
}

