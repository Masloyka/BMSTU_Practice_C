// подключите библиотеку для работы с вводом и выводом
// подключите библиотеку для работы с памятью
#include <stdio.h>
#include <stdlib.h>

int InsertIndex(const int* arr, const int size, const int target) {
    // Реализуйте функцию
    // Рекомендуем реализовать алгоритм O(log n)
    if (arr[0] >= target){
        return 0;
    }
    if (arr[size-1] <= target){
        return size;
    }
    for (int i = 0; i < size-1; ++i){
        if (arr[i] < target && arr[i+1] >= target){
            return i+1;
        }
    }
    return -1;
}


int main() {
    // зачитайте размер, массив и цель
    int size;
    scanf("%d", &size);
    int* array = (int*)malloc(size*sizeof(int));
    for (int i = 0 ; i < size; ++i){
        scanf("%d", &array[i]);
    }
    int target = 0;
    scanf("%d", &target);
    int target_id = InsertIndex(array, size, target);
    printf("%d", target_id);
    // Выведите индекс для вставки
    return 0;
}