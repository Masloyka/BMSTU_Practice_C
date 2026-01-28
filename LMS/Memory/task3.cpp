#include <stdio.h>

void Swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    Swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}