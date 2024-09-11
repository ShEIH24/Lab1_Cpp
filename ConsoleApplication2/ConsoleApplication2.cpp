#include <iostream>
#include <iomanip>
#include <algorithm>

void initializeArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = i * i + 1;
        if (i % 2 == 0) {
            arr[i] *= -1;
        }
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(5) << arr[i];
        // Каждые 9 элементов происходит переход на новую строку
        if ((i + 1) % 9 == 0) std::cout << std::endl;
    }
    std::cout << std::endl;
}

void transformArray(int* arr1D, int size1D, int**& arr2D, int& rows, int& cols) {
    rows = 9;
    cols = 2;

    // Сортировка в порядке убывания
    std::sort(arr1D, arr1D + size1D, std::greater<int>());

    // Выделение памяти для 2D массива
    arr2D = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr2D[i] = new int[cols];
    }

    // Заполнение 2D массива
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr2D[i][j] = arr1D[i * cols + j];
        }
    }
}

int main() {
    const int size1D = 18;
    int* arr1D = new int[size1D];

    initializeArray(arr1D, size1D);

    std::cout << "1D array:" << std::endl;
    printArray(arr1D, size1D);

    int** arr2D;
    int rows, cols;
    transformArray(arr1D, size1D, arr2D, rows, cols);

    std::cout << "2D array:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(5) << arr2D[i][j];
        }
        std::cout << std::endl;
    }

    // Освобождение памяти
    delete[] arr1D;
    for (int i = 0; i < rows; ++i) {
        delete[] arr2D[i];
    }
    delete[] arr2D;

    return 0;
}