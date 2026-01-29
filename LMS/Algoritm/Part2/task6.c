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

int* PlusOne(const int* arr, const int size, int new_size) {
    // Реализуйте функцию
    // Функция должна обновлять новый размер для корректного отображения массива
    int* new_arr = calloc(new_size, sizeof(int));
    int carry = 1;
    for (int i = size - 1; i >= 0 && carry >= 0; i--) {
        if (new_size > size){
            new_arr[i+1] = arr[i];
            new_arr[i+1] += carry;
            carry = new_arr[i+1] / 10;
            new_arr[i+1] %= 10;
            new_arr[0] = 1;
        } else{
            new_arr[i] = arr[i];
            new_arr[i] += carry;
            carry = new_arr[i] / 10;
            new_arr[i] %= 10;
        }
    }
    return new_arr;
}


int main() {
    // зачитайте размер и массив
    int size;
    scanf("%d", &size);
    int* array = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
    // Выведите конечный массив в формате [элемент, элемент, ...]
    if (array[0] == 9){
        PrintArray(PlusOne(array, size, size+1), size+1);
    }
    else{
        PrintArray(PlusOne(array, size, size), size);
    }
    return 0;
}