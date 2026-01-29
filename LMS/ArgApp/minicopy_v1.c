#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    if (argc != 3){
        fprintf(stderr, "Usage: %s <src_file> <dst_file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], argv[2]) == 0){
        fprintf(stderr, "[ERROR] Unable to copy file onto itself: %s\n", argv[1]);
    }

    FILE* src = fopen(argv[1], "rb");
    if (!src){
        fprintf(stderr, "[ERROR] Cannot open file: %s\n", argv[1]);
    }
    FILE* dst =  fopen(argv[2], "wb");
    if (!dst){
        fprintf(stderr, "[ERROR] Cannot open file: %s\n", argv[3]);
    }
    int ch = 0;
    while ((ch = fgetc(src)) != EOF){
        fputc(ch, dst);
    }

    fclose(src);
    fclose(dst);
}