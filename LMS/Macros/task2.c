#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define LogError(msg) \
    fprintf( \
        stderr, \
        "[ERROR]: %s: %d - %s\n", \
        __func__, \
        __LINE__, \
        msg \
    ) // макрос 

#define LOG_ERROR(fmt, ...) \
    fprintf( \
        stderr, \
        "[ERROR] %s:%d " fmt "\n", \
        __FILE__, \
        __LINE__, \
        ##__VA_ARGS__ \
    ) // макрос 

#define LOG_WARNING(fmt, ...) \
    fprintf( \
        stdout, \
        "[WARNING]: %s:%d:" fmt "\n", \
        __FILE__, \
        __LINE__, \
        ##__VA_ARGS__ \
    ) // макрос ##__VA_ARGS__ - вариативное число аргументов!

#define LOG_DEBUG(fmt, ...) \
    fprintf( \
        stdout, \
        "[DEBUG]: %s:%d: " fmt "\n", \
        __FILE__, \
        __LINE__, \
        ##__VA_ARGS__ \
    )

#define ASSERT(cond, fmt, ...) \
    do {\
        if (!(cond)){ \
            fprintf(stderr, "[ASSERT] %s:%d (%s): " fmt "\n", \
                __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
                abort(); \
            } \
        } while(0)

bool TrueIsFalse(const bool v){
    if (v) {
        LogError("Was True!");
    } else {
        LogError("Was False!");
    }
    return !v;
}

int main(){
    TrueIsFalse(true);
    TrueIsFalse(false);
    LOG_DEBUG("x = %d", 5);
    LOG_ERROR("File '%s' not found", "filename");
    ASSERT(2 + 2 == 5, "Макросы волшебны! У нас %d, а тест ожидал %d\n", 2+2, 5);
    return 0;
}