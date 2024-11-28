// 5.Напиши програма која содржи class template Array со која може да се инстанцира поле 
// од било кој тип. Класата треба да содржи функции членки за сместување и преземање на вредност 
// на елемент од полето. Да се демонстрира создавање на објекти за int и double тип.

#include <iostream>

template <typename T>
class Array {
private:
    T* arr;
    int size;

public:
    Array(int s) : size(s) {
        arr = new T[size];
    }
    ~Array() {
        delete[] arr;
    }
    void set(int index, T value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        } else {
            std::cout << "indeks nadvor od opseg!" << std::endl;
        }
    }
    T get(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        } else {
            std::cout << "indeks nadvor od opseg!" << std::endl;
            return T();
        }
    }
    void print() {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Array<int> intArray(5);
    intArray.set(0, 10);
    intArray.set(1, 20);
    intArray.set(2, 30);
    intArray.set(3, 40);
    intArray.set(4, 50);
    
    std::cout << "elementi na intArray: ";
    intArray.print();
    Array<double> doubleArray(3);
    doubleArray.set(0, 10.5);
    doubleArray.set(1, 20.75);
    doubleArray.set(2, 30.25);

    std::cout << "elementi na doubleArray: ";
    doubleArray.print();

    return 0;
}

