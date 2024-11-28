#include <iostream>
#include <algorithm> 

using namespace std; 

template <typename T>
void sortArray(T arr[], int size) {
    sort(arr, arr + size); 
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
    cout << "Vnesi " << size << " elementi:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

int main() {
    int intSize, doubleSize;
    cout << "vnesi ja goleminata na nizata: ";
    cin >> intSize;
    int* intArray = new int[intSize];

    inputArray(intArray, intSize);
    cout << "pred sortiranje (int): ";
    printArray(intArray, intSize);

    sortArray(intArray, intSize);
    cout << "po sortiranje (int): ";
    printArray(intArray, intSize);

    delete[] intArray; 
    cout << "vnesi ja goleminata na nizata od double: ";
    cin >> doubleSize;
    double* doubleArray = new double[doubleSize];
    inputArray(doubleArray, doubleSize);
    cout << "pred sortiranje (double): ";
    printArray(doubleArray, doubleSize);

    sortArray(doubleArray, doubleSize);
    cout << "po sortiranje (double): ";
    printArray(doubleArray, doubleSize);

    delete[] doubleArray; 

    return 0;
}
