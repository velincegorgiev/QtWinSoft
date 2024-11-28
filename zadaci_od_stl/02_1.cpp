// 1.Напиши function template кој има еден параметризиран тип (T) и прифаќа четири аргументи:
//  поле од тип T, почетен индекс, краен индекс и опциона, почетна вредност. 
//  Функцијата трба да ја врати сумата на елементите во полето зададени со почетниот и крајниот индекс. 
//  За почетната вредност да се употреби конструкторот на T.

#include <iostream>

using namespace std;

template <typename T>
T sumArray(T arr[], int startIndex, int endIndex, T initialValue = T()) {
    T sum = initialValue;
    for (int i = startIndex; i <= endIndex; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int intArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int intStart = 2, intEnd = 5;
    cout << "sumata na intArray od indeks " << intStart << " do " << intEnd << ": " 
         << sumArray(intArray, intStart, intEnd) << endl;
    double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    int doubleStart = 1, doubleEnd = 3;
    cout << "sumata na doubleArray od indeks " << doubleStart << " do " << doubleEnd << ": " 
         << sumArray(doubleArray, doubleStart, doubleEnd) << endl;
    int intArrayWithInitial[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    cout << "sumata na intArray so pocetna vrednost 100: "
         << sumArray(intArrayWithInitial, 2, 5, 100) << endl;

    return 0;
}

