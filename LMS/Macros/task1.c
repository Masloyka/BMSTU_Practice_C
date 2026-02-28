#include <stdio.h>

#define PI 3.14159265 // макрос
#define MAX_STUDENTS 50 // макрос Замена значения в коде на имя (магические цифры) не очень!
#define var 1+2

#define SQR(x) x * x // неправильно 
#define TRUE_SQR(x) ((x) * (x)) // более правильно 

int main(){
    printf("%0.10f\n", PI);
    printf("%d\n", MAX_STUDENTS);
    auto varr = var * 3;
    return 0;
}