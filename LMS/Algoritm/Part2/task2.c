#include <stdio.h>

// Линейная сложность
int Findmin(const int* arr, int size){
    int min = arr[0];
    for (int i = 0; i < size; ++i){
        if (arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int FindMax(const int* arr, int size){
    int max = arr[0];
    for (int j = 1; j < size; ++j){
        if (arr[j] > max){
            max = arr[j];
        }
    }
    return max;
}

int FindTargetIndex(const int* arr, int size, int Target){
    for (int i = 0; i < size; ++i){
        if (arr[i] == Target){
            return i;
        }
    }
    return -1;
}

int main(){
    int array[9] = {1, 2, 3 ,4 ,5, 76, 1231431, 3, 565464};
    int size = sizeof(array) / sizeof(int);
    printf("Max Element: %d\n", FindMax(array, size));
    printf("Min element: %d\n", Findmin(array, size));
    printf("Index target: %d\n", FindTargetIndex(array, size, 3));
}