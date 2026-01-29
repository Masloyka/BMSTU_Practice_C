#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    if (argc != 3){
        fprintf(stderr, "Usage %s <src_name> <dst_name>\n", argv[0]);
        return 1;
    }
    if (strcmp(argv[1], argv[2]) == 0){
        fprintf(stderr, "ERROR Failed copy file onto itself %s\n", argv[1]);
        return 1;
    }
    FILE* src = fopen(argv[1], "rb");
    if (!src){
        fprintf(stderr, "ERROR Cannot open file: %s\n", argv[1]);
    }
    FILE* dst = fopen(argv[2], "wb");
    if (!dst){
        fprintf(stderr, "ERROR Cannot open file: %s\n", argv[2]);
    }

    unsigned char buffer[1024*32];
    size_t c;
    while ((c = fread(buffer, 1, sizeof buffer, src)) > 0)
    {
        size_t w = fwrite(buffer, 1, c, dst);
    }
    if (fclose(src) != 0) {
        fprintf(stderr, "ERROR Failed close file: %s\n", argv[1]);
        return 1;
    }
    if (fclose(dst) != 0) {
       fprintf(stderr, "ERROR Failed close file: %s\n", argv[2]);
        return 1;
    }
    return 0;
}