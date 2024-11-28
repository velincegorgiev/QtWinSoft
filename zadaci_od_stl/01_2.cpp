// 2.Преклопи го printArray така што ќе добие уште два целобројни аргументи lowSubscript и highSubscript. 
// Повик на оваа функција треба да ги отпечати елементите помеѓу lowSubscript и highSubscript. 
// Ако нивните вредности излегуваат од димензиите на полето, printArray треба да врати 0, во спротивно бројот 
// на отпечатени елементи. Во main да се тестира функционирањето на двете верзии на printArray врз полињата a, b и c.

#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void sortArray(T arr[], int size) {
    sort(arr, arr + size);
}

template <typename T>
int printArray(const T arr[], int size, int lowSubscript, int highSubscript) {
    if (lowSubscript < 0 || highSubscript >= size || lowSubscript > highSubscript) {
        return 0;
    }
    int count = 0;
    for (int i = lowSubscript; i <= highSubscript; ++i) {
        cout << arr[i] << " ";
        ++count;
    }
    cout << endl;
    return count;
}

template <typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void inputArray(T arr[], int size) {
    cout << "vnesi " << size << " elementi:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

int main() {
    int intSize1, intSize2, intSize3;
    cout << "vnesi ja goleminata na int nizata a: ";
    cin >> intSize1;
    int* a = new int[intSize1];
    inputArray(a, intSize1);
    cout << "nizata pred sortiranje: ";
    printArray(a, intSize1);
    sortArray(a, intSize1);
    cout << "nizata po sortiranje: ";
    printArray(a, intSize1);
    int lowSubscript, highSubscript;
    cout << "vnesi lowSubscript i highSubscript za nizata a: ";
    cin >> lowSubscript >> highSubscript;
    int printedCount = printArray(a, intSize1, lowSubscript, highSubscript);
    if (printedCount == 0) {
        cout << "nevazeski indeks za nizata a!" << endl;
    } else {
        cout << "pecateni " << printedCount << " elementi od nizata a." << endl;
    }
    delete[] a; 
    cout << "vnesi ja goleminata na nizata b: ";
    cin >> intSize2;
    int* b = new int[intSize2];
    inputArray(b, intSize2);
    cout << "nizata b pred soritiranje: ";
    printArray(b, intSize2);
    sortArray(b, intSize2);
    cout << "nizata b posle sortiranje: ";
    printArray(b, intSize2);
    cout << "vnesi lowSubscript i highSubscript za nizata b: ";
    cin >> lowSubscript >> highSubscript;
    printedCount = printArray(b, intSize2, lowSubscript, highSubscript);
    if (printedCount == 0) {
        cout << "nevazeski indeks za nizata b!" << endl;
    } else {
        cout << "pecateni " << printedCount << " elementi od nizata b." << endl;
    }
    delete[] b; 
    cout << "vnesi ja goleminata na nizata c: ";
    cin >> intSize3;
    int* c = new int[intSize3];
    inputArray(c, intSize3);
    cout << "nizata c pred sortiranje: ";
    printArray(c, intSize3);
    sortArray(c, intSize3);
    cout << "nizata c po sortiranje: ";
    printArray(c, intSize3);
    cout << "vnesi lowSubscript i highSubscript za nizata c: ";
    cin >> lowSubscript >> highSubscript;
    printedCount = printArray(c, intSize3, lowSubscript, highSubscript);
    if (printedCount == 0) {
        cout << "nevazeski indeks za nizata c!" << endl;
    } else {
        cout << "pecateni " << printedCount << " elementi od nizata c." << endl;
    }
    delete[] c;
    return 0;
}

