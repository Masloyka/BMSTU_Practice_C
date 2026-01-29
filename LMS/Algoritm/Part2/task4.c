// подключите библиотеки для работы с кучей, строками,
// логическими типами данных и ввода/вывода
#include <stdio.h>
#include <string.h>
int Counter(const char* s){
    return strlen(s);
}
void IsAnagram(char* s1, char* s2) {
    // Реализуйте функцию, которая обработает две строки
    // Вы можете реализовать дополнительные функции при необходимости.
    // Например:
    // - int* Counter(const char* s) - функция подсчета букв в строке
    // - bool Compare(const int* s1, const int* s2) - функция сравнения массивов
    int count_s1 = Counter(s1);
    int count_s2 = Counter(s2);
    if (count_s1 != count_s2){
        printf("False");
        return;
    }
    for (int i = 0; i < count_s1; i++){
        if (!strchr(s2, s1[i])){
            printf("False");
            return;
        }
    }
    printf("True");
}


int main() {
    // считайте s1
    char s1[100];
    scanf("%s", s1);
    // считатйте s2
    char s2[50];
    scanf("%s", s2);
    // Выведите IsAnagram(s1, s2)
    IsAnagram(s1, s2);
    // Учтите, что выводиться должно True или False
}