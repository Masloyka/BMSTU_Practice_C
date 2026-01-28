// подключите библиотеки для работы с вводом, выводом и памятью
#include <stdio.h>
#include <stdlib.h>
// возьмите заготовку функции InitMatrix из лекции
static int** InitMatrix(const int rows, const int cols){
    int** result = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i){
        result[i] = calloc(cols, sizeof(int));
        for (int j = 0; j < cols; ++j){
            scanf("%d", &result[i][j]);
        }
    }
    return result;
}
// возьмите заготовку функции PrintMatrix из лекции
static void PrintMatrix(int** matrix, const int rows, const int cols){
    printf("{\n");
    for (int i = 0; i < rows; i++){
        printf("  {");
        for (int j = 0; j < cols; j++){
            printf("%d", matrix[i][j]);
            if (j != cols - 1){
                printf(", ");
            }
            else {
                printf("}");
            }
        }
        if (i != rows - 1){
            printf(",\n");
        }
        else{
            printf("\n}\n");
        }
    }
}
// Функция подсчитывает сумму элементов матрицы
static int MatrixSum(int** matrix, const int rows, const int cols){
    int Sum = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            Sum += matrix[i][j];
        }
    }
    return Sum;
}

// Функция возвращает транспонированную матрицу
static int** Transparent(int** matrix, const int rows, const int cols){
    int** result = calloc(cols, sizeof(int*));
    for (int i = 0; i < cols; i++){
        result[i] = calloc(rows, sizeof(int));
        for (int j = 0; j < rows; j++){
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}

// возьмите заготовку функции FreeMatrix из лекции
static void FreeMatrix(int** matrix, const int rows, const int cols){
    for (int i =0 ; i < rows; ++i){
        free(matrix[i]);
    }
    free(matrix);
}
/*
Данная функция находит максимальный и минимальный элемент матрицы
и возвращает массив из 6 элементов: max, max_i, max_j, min, min_i, min_j
*/
static int* MaxMinElement(int** matrix, const int rows, const int cols){
    int max = matrix[0][0], max_i = 0, max_j = 0;
    int min = matrix[0][0], min_i = 0, min_j = 0;

    int* MaxMinArray = calloc(6,sizeof(int));

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (matrix[i][j] > max){
                max = matrix[i][j];
                max_i = i;
                max_j = j;
            }
            if (matrix[i][j] < min){
                min = matrix[i][j];
                min_i = i;
                min_j = j;
            }
        }
    }
    MaxMinArray[0] = max;
    MaxMinArray[1] = max_i;
    MaxMinArray[2] = max_j;
    MaxMinArray[3] = min;
    MaxMinArray[4] = min_i;
    MaxMinArray[5] = min_j;
    printf("Min element: %d (%d,%d); Max element: %d (%d,%d);", min, min_i, min_j, max, max_i, max_j);
    return MaxMinArray; 
}

int main() {
    // Обработайте пользовательский ввод размеров матрицы
    int rows = 0, cols = 0;
    scanf("%d %d", &rows, &cols);
    // Инициализируйте матрицу используя InitMatrix
    int** matrix = InitMatrix(rows, cols);
    // Выведите матрицу используя printf("Matrix:\n"); + PrintMatrix()
    printf("Matrix:\n");
    PrintMatrix(matrix, rows, cols);
    // Выведите сумму элементво матрицы в формате: Matrix sum: %d;\n
    int sum = MatrixSum(matrix, rows, cols);
    printf("Matrix sum: %d;\n", sum);
    // Инициализируйте транспонированную матрицу используя функцию Transparent
    int** trans_matrix = Transparent(matrix, rows, cols);
    // Выведите транспонированную матрицу используя printf("Transparent:\n"); + PrintMatrix()
    printf("Transparent:\n");
    PrintMatrix(trans_matrix, cols, rows);
    /*
      Инициализируйте переменную максимального и минимального элемента,
      полученных с помощью функции MaxMinElement
    */
    int* MaxMin = MaxMinElement(matrix, rows, cols);
    // Освободите память под переменную максимального и минимального элемента
    free(MaxMin);
    // Освободите память для transparent
    FreeMatrix(trans_matrix, cols, rows);
    // Освободите matrix
    FreeMatrix(matrix, rows, cols);

    return 0;
}