#include <stdio.h>
#include <string.h>
#include <math.h>
// EASY GAME
struct Watch
{
    char name[50];
    int price;
    double weight;
};
int Getn(){
    int n;
    printf("Введите количество часов: ");
    scanf("%d", &n);
    return n;
}
Watch* InputWatch(int n)
{
    Watch* watchs = new Watch[n];
    for (int i = 0; i < n; i++)
    {
        printf("Введите параметры часов №%d\n", i+1);
        printf("Введите название часов: ");
        scanf("%s", watchs[i].name);
        printf("Введите стоимость часов:");
        scanf("%d", &watchs[i].price);
        printf("Введите массу часов:");
        scanf("%lf", &watchs[i].weight);
    }
    return watchs;
}
void OutputWatches(Watch* watchs, int n)
{
    printf("Результат:\n");
    printf("Название часов\tСтоимость\tМасса\n");
    for (int i = 0; i < n; i++)
    {
        printf("%-14s\t%-9d\t%-5.2lf\n",watchs[i].name,watchs[i].price,watchs[i].weight);
    }
}
void First_ans(Watch* watchs, int n)
{
    int k = 0;
    for (int i = 0 ; i < n; i++){
        if ((watchs[i].price > 1000) && (watchs[i].weight < 300))
            k++;
    }
    Watch* newwat = new Watch[k];
    for (int i = 0; i < k; i++){
        if ((watchs[i].price > 1000) && (watchs[i].weight < 300))
            newwat[i] = watchs[i];
    }
    OutputWatches(newwat, k);
    delete[] newwat;
}

void Second_ans(Watch* watches, int n){
    int max = 0, c = 0;
    Watch* nw = new Watch[1];
    char s[10];
    strcpy(s,"aAаА");
    for (int i = 0; i < n; i++){
        char *p = strpbrk(watches[i].name, s);
        while (p != NULL && p != s){
            c++;
            p = strpbrk(p+1,s);
        }
        if (c == 3)
            if (watches[i].price > max){
                max = watches[i].price;
                nw[0] = watches[i];
                c = 0;
            }
        else
            c = 0;
        }
    OutputWatches(nw, 1);
    delete[] nw;
}
void deleteWatchs(Watch* watchs)
{
    delete[] watchs;
}
int main()
{
    int n = Getn();
    Watch * watchs;
    watchs = InputWatch(n);
    OutputWatches(watchs, n);
    First_ans(watchs, n);
    Second_ans(watchs, n);
    deleteWatchs(watchs);
}
