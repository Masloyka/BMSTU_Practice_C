#include <stdio.h>

int main(){
    int a = 0;
    scanf("%d", &a);
    if(a != 42){
        fprintf(stderr,
        "Error Number Failed!");
        return 1;
    }
    printf("Right!");
}