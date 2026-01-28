#include <stdio.h>

int main(){
    int a;
    char b = 'B';
    char buffer[50];
    if (!fgets(buffer, 50, stdin)){
        return 1;
    }
    sscanf(buffer, "%d %c", &a, &b);
    printf("%d %c\n", a, b);
    fputs("another Line\n", stderr);
    return 0;
}