#include <stdio.h>

void Swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int* arr, int left, int right){
    int mid = left + (right - left) / 2;
    Swap(&arr[mid], &arr[right]);
    int pivot = arr[right];

    int i = left - 1;
    for (int j = left; j < right; ++j){
        if (arr[j] < pivot){
            ++i;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i+1], &arr[right]);
    return i+1;
}

void QuickSort(int* arr, int left, int right){
    if (left < right){
        int p = Partition(arr, left, right);
        QuickSort(arr, left, p-1);
        QuickSort(arr, p+1, right);
    }
}

int main(){
    int arr[8] = {3, 8, 2, 5, 1, 4, 7, 6};
    QuickSort(arr, 0, 7);
    printf("Sorted: ");
    for (int i = 0; i<8;++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}