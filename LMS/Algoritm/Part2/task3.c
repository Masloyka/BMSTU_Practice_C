#include <stdio.h>

int FindSortedTargetIndex(const int* arr, const int size, const int target){
    int left = 0;
    int right = size - 1;
    printf("Finding...\n");
    while (left <= right){
        int mid = (left + right) / 2;
        printf("Mid: %d\n", arr[mid]);
        if (arr[mid] == target){
            return mid;
        }
        if (arr[mid] < target){
            left = mid + 1;
        }
        if (arr[mid] > target){
            right = mid - 1;
        }
    }
    return - 1;
}
int FindSortedMax(const int* arr, const int size){
    return arr[size-1];
}
int FindSortedMin(const int* arr, const int size){
    return arr[0];
}

int main(){
    int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(array) / sizeof(int);
    printf("Finded: %d\n", FindSortedTargetIndex(array, size, 7));
    printf("Max: %d\n", FindSortedMax(array, size));
    printf("Min: %d\n", FindSortedMin(array, size)); 
    return 0;
}