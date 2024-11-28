// 2.Во еден систем пристигнуваат процеси кои треба да бидат опслужени. 
// Секој процес има идентификационен број и приоритет. Напиши прграма која за внесена листа 
// на процеси и приоритети ќе прикаже по кој редослед тие ќе бидат опслужени. 

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class Proces {
public:
    int id;
    int prioritet;
    Proces(int id, int prioritet) : id(id), prioritet(prioritet) {}
    bool operator<(const Proces& p) const {
        return prioritet > p.prioritet;
    }
};

int main() {
    priority_queue<Proces> pq;
    int n;
    cout << "vnesi broj na procesi: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int id, prioritet;
        cout << "vnesete indentifikacionen broj na procesot: ";
        cin >> id;
        cout << "vnesete prioritet na procesot: ";
        cin >> prioritet;
        pq.push(Proces(id, prioritet));
    }
    cout << "\nredosled na opsluzuvanje na procesite:" << endl;
    while (!pq.empty()) {
        Proces p = pq.top();
        pq.pop();
        cout << "proces ID: " << p.id << ", prioritet: " << p.prioritet << endl;
    }

    return 0;
}

