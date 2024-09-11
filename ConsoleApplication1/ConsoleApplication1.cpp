#include <cstdio>
#include <cmath>

const int n = 16;

int processArray(int arr[], int outArr[], int& count) {
    count = 0;
    int outIndex = 0;

    for (int i = 0; i < n; i++) {
        // Заполнение степенями двойками
        if (i % 2 == 0) {
            arr[i] = pow(2, i / 2);
        }
        // Заполнение степенями тройками
        else {
            arr[i] = pow(3, i / 2);
        }
        // Если число двухзначное, то добавляется в выходной массив, увелечивая счётчик count
        if (arr[i] >= 10 && arr[i] <= 99) {
            count++;
            outArr[outIndex++] = arr[i];
        }
    }

    return count;
}

int main() {
    int arr[n];
    int outArr[n];
    int count;

    // Инициализация массива единицами
    for (int i = 0; i < n; i++) {
        arr[i] = 1;
    }

    // Обработка массива
    processArray(arr, outArr, count);

    // Вывод исходного массива
    printf("The source array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Вывод выходного массива
    printf("Output array (TD numbers):\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", outArr[i]);
    }
    printf("\n\n");

    // Вывод количества двузначных чисел
    printf("The number of TD numbers: %d\n", count);

    return 0;
}