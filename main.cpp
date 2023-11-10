#include <stdio.h>
#include <random>
#include <ctime>

void getNM(int &n, int &m)
{
    printf("Введите размеры матрицы: ");
    scanf("%d%d", &n, &m);
}

int** init(int n, int m)
{
    int **matr = new int*[n];
    for(int i = 0; i < n; i++)
    {
        matr[i] = new int[m];
    }
    return matr;
}
void InputMatrRand(int **matr, int n, int m, int l, int r)
{
    srand(time(0));
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j++)
            matr[i][j] = rand() % (l-r) + l;
    printf("Матрица введена\n");
}

void  Inputmatr(int **matr, int n, int m)
{
    printf("Введите матрицу:\n");
    for(int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &matr[i][j]);
    printf("Матрица введена!\n");
}

void  OutputMAtr(int **matr, int n, int m)
{
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            printf("%d ", matr[i][j]);
        printf("\n");
    }
}

void MatrMin(int **matr, int n,  int m)
{
    int min = matr[0][0];
    for(int i = 0; i < n; i ++)
        for (int j = 0; j < m; j++)
            if (matr[i][j] < min)
                min = matr[i][j];
    printf("Минимум матрицы: %d\n", min);
    printf("Выберите следующий пункт: ");
}

void MatrMax(int **matr, int n,  int m)
{
    int max = matr[0][0];
    for(int i = 0; i < n; i ++)
        for (int j = 0; j < m; j++)
            if (matr[i][j] > max)
                max = matr[i][j];
    printf("Максимум матрицы: %d\n", max);
    printf("Выберите следующий пункт: ");
}

void TransponMatr(int **matr, int n, int m)
{
    int **a = new int*[m];
    for(int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    int k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            k = matr[i][j];
            a[j][i] = k;
        }
    printf("Транспонированная матрица\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }


    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}

void printmatr90(int**matr, int n, int m)
{}
void clearmem(int **matr, int n)
{
    for (int i = 0; i< n; i++)
        delete[] matr[i];
    delete[] matr;
}
int main()
{
    int n,m, poz = -1;
    int p = 0;
    int **matr;
    printf("\nВыберите пункт меню\n");
    printf("\n********************\n");
    printf("1) Ввод матрицы\n");
    printf("2) Вывод матрицы\n");
    printf("3) Минимум матрицыя\n");
    printf("4) Максимум матрицы\n");
    printf("5) Транспонровать матрицу\n");
    printf("0) Выход\n");
    while (poz != 0)
    {
        scanf("%d", &poz);
        if (poz == 1){
            getNM(n,m);
            matr = init(n,m);
            int ask;
            printf("1) Заполнить случайно;\n2) Заполнить вручную;\n");
            scanf("%d", &ask);
            if (ask == 1){
                int l, r;
                printf("Введите границы чисел в матрице: ");
                scanf("%d%d",&l,&r);
                InputMatrRand(matr, n, m, l, r);
                p = 1;
                printf("Выберите следующий пункт: ");
            }
            if (ask == 2){
                Inputmatr(matr,n,m);
                p = 1;
                printf("Выберите следующий пункт: ");
            }
            if ((ask != 1) && (ask != 2)){
                printf("Выберите номер от 1 до 2!!!!");
                scanf("%d", &ask);
            }
        }

        else if (poz == 2)
        {
            if (p == 0)
                printf("Матрица не введена!!!\nВыберите пункт 1, чтобы ввести матрицу\n");
            else
                OutputMAtr(matr,n,m);
        }
        else if (poz == 3)
        {
            if (p == 0)
                printf("Матрица не введена!!!\nВыберите пункт 1, чтобы ввести матрицу\n");
            else
                MatrMin(matr, n,m);
        }
        else if (poz == 4)
        {
            if (p == 0)
                printf("Матрица не введена!!!\nВыберите пункт 1, чтобы ввести матрицу\n");
            else
                MatrMax(matr, n, m);
        }
        else if (poz == 5)
        {
            if (p == 0)
                printf("Матрица не введена!!!\nВыберите пункт 1, чтобы ввести матрицу\n");
            else
                TransponMatr(matr, n ,m);
        }
    }





    if (poz == 0)
    {
        if(p == 0)
            printf("Удачи!\n");
        if (p == 1){
            clearmem(matr,n);
            printf("Удачи!\n");
        }
    }
    return 0;
}
