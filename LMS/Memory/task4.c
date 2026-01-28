#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str = NULL;
    int size = 0;
    int capacity = 8;
    str = malloc(capacity * sizeof(char));
    
    char ch = ' ';
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (size + 1 >= capacity) {
            capacity *= 2;
            str = realloc(str, capacity * sizeof(char));
        }
        str[size++] = ch;
    }
    str[size] = '\0';
    

    int word_count = 1; 
    for (int i = 0; i < size; i++) {
        if (str[i] == ',') {
            word_count++;
        }
    }
    

    char **words = malloc(word_count * sizeof(char*));
    if (words == NULL) {
        free(str);
        return 1;
    }
    

    int word_index = 0;
    int word_start = 0;
    
    for (int i = 0; i <= size; i++) {
        if (str[i] == ',' || str[i] == '\0') {
            int word_len = i - word_start;
            
            words[word_index] = malloc((word_len + 1) * sizeof(char));
            
            for (int j = 0; j < word_len; j++) {
                words[word_index][j] = str[word_start + j];
            }
            words[word_index][word_len] = '\0';

            word_start = i + 1;
            word_index++;
        }
    }
    
    printf("[");
    for (int i = 0; i < word_count; i++) {
        printf("\"%s\"", words[i]);
        if (i < word_count - 1) {
            printf(", ");
        }
        free(words[i]);  
    }
    printf("]\n");
    
    free(words);
    free(str);
    
    return 0;
}