// 1.Напиши програм кој кој користи функциски урнек min за да го определи помалиот од двата аргументи. 
// Тестирај го прогамот со цели броеви, реални броеви и карактери.

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a = 5, b = 8;
    cout << "minimalnata megu " << a << " i " << b << " e: " << min(a, b) << endl;
    double x = 3.14, y = 2.71;
    cout << "minimalnata megu " << x << " i " << y << " e: " << min(x, y) << endl;
    char c1 = 'a', c2 = 'z';
    cout << "minimalnata megu '" << c1 << "' i '" << c2 << "' e: " << min(c1, c2) << endl;
    return 0;
}

