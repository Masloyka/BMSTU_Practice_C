#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

// Функция проверяет полученную русскую букву на гласность
bool IsRussianVowelUtf8(const unsigned char *p, int *step) {
    unsigned char c1 = p[0];
    if (c1 < 128) {
        *step = 1;
        return false;
    }

    unsigned char c2 = p[1];
    *step = 2; // кириллица в UTF-8 всегда 2 байта

    if (c1 == 0xD0) {
        return (c2 == 0xB0 || // а
                c2 == 0xB5 || // е
                c2 == 0xB8 || // и
                c2 == 0xBE);  // о
    } else if (c1 == 0xD1) {
        return (c2 == 0x91 || // ё
                c2 == 0x83 || // у
                c2 == 0x8B || // ы
                c2 == 0x8D || // э
                c2 == 0x8E || // ю
                c2 == 0x8F);  // я
    }
    return false;
}

void IambOrTrochee(const char* s) {
    // Реализуйте функцию обработки полученной строки стихотворения
    // В рамках данного задания нет "подводных тестов". Они все открытые.
    // Отобразите "ямб", если стиль строки [0, 1, 0, 1...]
    // и хорей, если стиль [1, 0, 1, 0...]
    int number_slog = 0;
    int step = 0;
    for (int i = 0; i < strlen(s); i++){
        if (IsRussianVowelUtf8((unsigned char*)&s[i], &step)){
            number_slog++;
        }
        if (s[i] == '`'){
            if ((number_slog+1) % 2 != 0 && number_slog != 0){
                printf("хорей");
                break;
            } else if((number_slog+1) % 2 == 0 && number_slog != 0){
                printf("ямб");
                break;
            }
        }
    }

}

int main() {
    // зачитайте полностью строку (рекомендуется fgets)
    char str[100];
    fgets(str, 100, stdin);
    IambOrTrochee(str);
    // узнайте стиль
    return 0;
}
