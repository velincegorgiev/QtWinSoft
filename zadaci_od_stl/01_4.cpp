// 4.Преклопи го function template-от printArray со non-template функција која печати поле од int во четири порамнети колони. 

#include <iostream>

void printArray(const int arr[], int size) {
    const int columns = 4;  
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << "\t";
        if ((i + 1) % columns == 0) {
            std::cout << std::endl; 
        }
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);

    return 0;
}

