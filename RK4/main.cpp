#include <stdio.h>
#include <string.h>
struct Footballer
{
    char surname[50];
    int age;
    int goals;
};
void GetN(int &n){
    printf("Введите количество футболистов: ");
    scanf("%d", &n);
    while (n <= 0 || n > 20){
        printf("Введите значение от 1 до 20!!!\n");
        scanf("%d", &n);
    }
}
Footballer* InputFootballers(int n){
    Footballer * fbs = new Footballer[n];
    for (int i = 0; i < n; i++){
        printf("Введите фамилию футболиста №%d: ", i+1);
        scanf("%s",fbs[i].surname);
        printf("Введите возраст футболиста: ");
        scanf("%d", &fbs[i].age);
        printf("Введите количество забитых голов: ");
        scanf("%d", &fbs[i].goals);
    }
    return fbs;
}
void OutputFootballers(Footballer * fbs, int n){
    printf("\tФутболисты\nФамилия\tВозраст\tКоличество голов\n");
    for (int i = 0; i < n; i++)
        printf("%-7s\t%-7d\t%-16d\n",fbs[i].surname, fbs[i].age, fbs[i].goals);
}
void Max_Minlength(Footballer * fbs, int n){
    int max = strlen(fbs[0].surname)-1, min = strlen(fbs[0].surname)+1;
    int i = 0, cur = 0;
    char cursmax[50];
    char cursmin[50];
    while (i != n){
        cur = strlen(fbs[i].surname);
        if (cur > max){
            strcpy(cursmax, "");
            max = cur;
            strcpy(cursmax, fbs[i].surname);
        }
        if (cur < min){
            strcpy(cursmin, "");
            min = cur;
            strcpy(cursmin, fbs[i].surname);
        }
        i++;
    }
    printf("Максимальная длина: %d - %s\n",max, cursmax);
    printf("Минимальная длина: %d - %s\n",min, cursmin);

}
bool UpLetters(Footballer fbs){
    char s[50];
    strcpy(s, "QWERTYUIOPASDFGHJKLZXCVBNM");
    char *p = strpbrk(fbs.surname, s);
    int count = 0;
    while (p != NULL && p != s){
        count++;
        p = strpbrk(p+1, s);
    }
    if (count >= 2)
        return true;
    return false;
}
bool Goals(Footballer fbs){
    if (fbs.goals >= 5)
        return true;
    else
        return false;
}
bool Ages(Footballer fbs){
    if (fbs.age > 30)
        return true;
    else
        return false;
}

Footballer * New_FBS(Footballer * fbs, int n, int & c, int &pos){
    c = 0;
    pos = -1;
    for (int i = 0; i < n; i++){
        if (UpLetters(fbs[i]) && Goals(fbs[i]) && Ages(fbs[i]))
            c++;
    }
    Footballer * nfbs = new Footballer[c];
    int j = 0;
    for (int i = 0; i < n; i++){
        if (UpLetters(fbs[i]) && Goals(fbs[i]) && Ages(fbs[i])){
            nfbs[j] = fbs[i];
            j++;
            pos = 1;
        }
    }
    return nfbs;
}
int main()
{
    int n, c, pos;
    GetN(n);
    Footballer * fbs;
    fbs = InputFootballers(n);
    OutputFootballers(fbs, n);
    Max_Minlength(fbs, n);
    Footballer * nfbs;
    nfbs = New_FBS(fbs,n, c, pos);
    if (pos == 1)
        OutputFootballers(nfbs, c);
    else
        printf("Таких футболистов нет!!!\n");


    delete[] fbs;
    delete[] nfbs;
}
