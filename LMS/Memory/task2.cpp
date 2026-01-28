#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    scanf("%d", &size);
    int* array = (int*) malloc(size*sizeof(int));
    if (array == NULL){
        printf("ERROR! Array not init!");
        return 1;
    }
    for (int i = 1; i <=size; i++) {array[i-1] = i*i*i;}
    for (int j = 0; j < size; j++){
        if (j == 0)
            printf("[");
        if (j == size-1){
            printf("%d]", array[j]);
            break;}
        printf("%d, ", array[j]);
    }
    free(array);
    return 0;
}