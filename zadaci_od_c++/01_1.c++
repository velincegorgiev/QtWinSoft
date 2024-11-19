// 1.Напиши С++ програм кој користи inline функција circleArea која бара влез од корисникот за 
// радиус на круг, ја пресметува и ја печати површината на кругот.


#include <iostream>
using namespace std;

inline double circleArea(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;
}
int main() {
    double radius;
    cout << "vnesi go radiusot na krugot: ";
    cin >> radius;
    cout << "povrsinata na krugot so radius " << radius << " e: " 
         << circleArea(radius) << endl;

    return 0;
}
