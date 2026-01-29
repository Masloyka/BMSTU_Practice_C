// подключите библиотеку для работы с вводом и выводом
// подключите библиотеку для работы с памятью
#include <stdio.h>
#include <stdlib.h>

void PrintArray(const int* arr, const int size) {
    // Реализуйте функцию
    printf("[");
    for (int i = 0; i < size; ++i){
        printf("%d", arr[i]);
        if (i != size-1){
            printf(", ");
        }
    }
    printf("]");
}

int* TwoSum(const int* arr, const int size, const int target) {
    // Реализуйте функцию
    // Сложность может быть квадратичной. В рамках тестов достаточно маленькие массивы
    int* index = calloc(2, sizeof(int));
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            if (j != i){
                if (arr[i]+arr[j] == target){
                    index[1] = i;
                    index[0] = j;
                    break;
                }
            }
        }
    }
    return index;
}


int main() {
    // зачитайте размер, массив и цель
    int size;
    scanf("%d", &size);
    int* array = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
    int target;
    scanf("%d", &target);
    // Выведите массив индексов в формате [индекс_1, индекс_2]
    PrintArray(TwoSum(array, size, target), 2);
    return 0;
}