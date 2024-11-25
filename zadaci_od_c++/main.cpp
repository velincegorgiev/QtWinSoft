#include <iostream>
#include "complex1.h"

using namespace std;

int main() {
   Complex x, y(4.3, 8.2), z(3.3, 1.1);

   cout << "x: ";
   cin >> x;
   cout << "y: " << y << endl;
   cout << "z: " << z << endl;

   Complex result = y + z;
   cout << "y + z: " << result << endl;

   result = y - z;
   cout << "y - z: " << result << endl;

   result = y * z;
   cout << "y * z: " << result << endl;

   result = y * 2;
   cout << "y * 2: " << result << endl;

   if (y == z)
      cout << "y and z are equal." << endl;
   else
      cout << "y and z are not equal." << endl;

   x += y;
   cout << "x += y: " << x << endl;
   x -= z;
   cout << "x -= z: " << x << endl;
   x *= y;
   cout << "x *= y: " << x << endl;

   return 0;
}
