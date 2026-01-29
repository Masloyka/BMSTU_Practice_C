#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (argc != 4){
        printf("Usage: %s <num> <+|-|/|x> <num>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[3]);
    char op = argv[2][0];

    int result = 0;

    if (op == '+'){
        result = a + b;
    } else if (op == '-'){
        result = a - b;
    } else if (op == '/'){
        result = a/b;
    } else if (op == 'x'){
        result = a * b;
    } else{
         printf("Usage: %s <num> <+|-|/|x> <num>\n", argv[0]);
         return 1;
    }
    printf("%s %s %s = %d\n", argv[1], argv[2], argv[3], result);
    return 0;
}