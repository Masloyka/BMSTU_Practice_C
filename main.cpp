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
    printf("Матрица:\n");
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
    for(int i = 0; i < m; i++)
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
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    for (int i = 0; i < m; i++)
        delete[] a[i];
    delete[] a;
}
void ReplaceChis(int **matr, int n, int m)
{
    int ch, sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            ch = matr[i][j];
            while (ch != 0)
            {
                sum += ch % 10;
                ch /= 10;
            }
            matr[i][j] = sum;
            sum = 0;
    }
    for (int i = 0; i< n; i++){
    for (int j = 0; j < m; j++)
            printf("%d ",matr[i][j]);
    printf("\n");
    }
}

void Chang_Col(int **matr, int n, int m)
{
    int x,y;
    int k;
    printf("Введите номера столбцов");
    scanf("%d%d", &x,&y);
    while ((x > m) || (y > m))
    {
    printf("Введите столбец от 1 до %d", m);
    }
    for(int i = 0; i < n; i++)
    {
        k = matr[i][y-1];
        matr[i][y-1] = matr[i][x-1];
        matr[i][x-1] = k;
    }
    printf("Замена выполнена");
}
void Chang_Str(int **matr, int n, int m)
{
    int x,y;
    int k;
    printf("Введите номера строк");
    scanf("%d%d", &x,&y);
    while ((x > n) || (y > n))
    {
        printf("Введите столбец от 1 до %d", m);
    }
    for(int i = 0; i < n; i++)
    {
        k = matr[i][y];
        matr[i][y] = matr[i][x];
        matr[i][x] = k;
    }
    printf("Замена выполнена");
}
void summ_gldiag(int **matr, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += matr[i][i];
    printf("Сумма элементов главной диагонали: %d", sum);

}

void summ_pbdiag(int **matr, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += matr[n-i-1][i];
    printf("Сумма элементов побочной диагонали: %d", sum);

}
void diagprog(int **matr, int n)
{
    int sum = 0, sumprog = 0;
    for (int i = 0; i < n;i++)
        sum += matr[i][i];
    sumprog = (matr[0][0] + matr[n][n])/2;
    if (sumprog == sum)
        printf("Главная диагональ является арифметической прогрессией");
    else
        printf("Главная диагональ не является арифметической прогрессией");
}
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
    while (poz != 0)
    {
        printf("\nВыберите пункт меню\n");
        printf("\n********************\n");
        printf("1) Ввод матрицы\n");
        printf("2) Вывод матрицы\n");
        printf("3) Минимум матрицыя\n");
        printf("4) Максимум матрицы\n");
        printf("5) Транспонровать матрицу\n");
        printf("6) Заменить элементы на сумму цифр элементов\n");
        printf("7) Поменять местами столбец x и y\n");
        printf("8) Поменять местами строки x и y\n");
        if (n == m)
        {
          printf("9) Найти сумму элементов главной диагонали\n");
          printf("10) Найти сумму элементов побочной диагонали\n");
          printf("11) Проверить являеться ли главная диагональ арифметической прогрессией\n");
          printf("12) Найти сумму элементов и вывести сами элементы верхнего треугольника\n");
          printf("13) Правого\n");
          printf("14) Нижнего\n");
          printf("15) Левого\n");
          printf("16) Повернуть матрицу на 90 градусов по часовой стрелке\n");
          printf("17) Повернуть матрицу на 90 градусов против часовой стрелке\n");
        }
        printf("Выберите пункт:\n");
        scanf("%d", &poz);
        if (poz == 1){
            getNM(n,m);
            matr = init(n,m);
            int ask;
            printf("1) Заполнить случайно;\n2) Заполнить вручную;\n");
            scanf("%d", &ask);
            while (((ask != 1) && (ask != 2)))
            {
                printf("Выберите номер от 1 до 2!!!!\n");
                scanf("%d", &ask);
            }
            if (ask == 1){
                int l, r;
                printf("Введите границы чисел в матрице: ");
                scanf("%d%d",&l,&r);
                InputMatrRand(matr, n, m, l, r);
                p = 1;
            }
            if (ask == 2){
                Inputmatr(matr,n,m);
                p = 1;
            }
        }

        else if (poz == 2)
        {
            if (p == 0)
                printf("Матрица не введена!!!\n");
            else
                OutputMAtr(matr,n,m);
        }
        else if (poz == 3)
        {
            if (p == 0)
                printf("Матрица не введена!!!\n");
            else
                MatrMin(matr, n,m);
        }
        else if (poz == 4)
        {
            if (p == 0)
                printf("Матрица не введена!!!\n");
            else
                MatrMax(matr, n, m);
        }
        else if (poz == 5)
        {
            if (p == 0)
                printf("Матрица не введена!!!\n");
            else
                TransponMatr(matr, n ,m);
        }
        else if (poz == 6){
            if (p == 0)
                printf("Матрица не введена!!!\n");
            else
                ReplaceChis(matr, n, m);
        }
        else if (poz == 7){
            if (p == 0)
                printf("Матрица не введена!!!\n");
            else
                Chang_Col(matr, n, m);
        }
        else if (poz == 8){
            if (p == 0)
                printf("Матрица не введена!!!\n");
            else
                Chang_Str(matr, n, m);
        }
        else if (poz == 9){
            if (p == 0)
                printf("Матрица не введена!!!\n");
            else
                summ_gldiag(matr,n);
        }
        else if (poz == 10){
            if (p == 0)
                printf("Матрица не введена!!!\n");
            else
                summ_pbdiag(matr,n);
        }
        else if (poz == 11){
            if (p == 0)
                printf("Матрица не введена!!!\n");
            else
                diagprog(matr, n);
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
