#include <stdio.h>

int main(){
    int N = 1000000;
    int a = 0.5 * N * N;
    int b = (1000+N*10000) * 100;
    printf("%d", a < b);
    return 0;
}