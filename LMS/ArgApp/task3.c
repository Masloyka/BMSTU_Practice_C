#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    FILE* file = fopen("data.txt", "r");
    if (!file){
        perror("[ERR#1] fopen");
        return 1;
    }

    
    if (fclose(file) != 0) {
        perror("ERR#2 fclose");
        return 1;
    }
    return 0;
}