#include <stdio.h>
#include <stdlib.h>
#include "arr_func.h"

/*ЗАДАНИЕ 5

Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double 
(значения n и элементы массивов ввести с консоли). А также ввести с консоли знак операции: '+', '-' или '*'. 
Написать функцию, вычисляющую сумму, разность или произведение данных матриц (их передать по указателю) и 
возвращающую указатель на массив-результат. Разместить эту функцию в отдельном модуле (отличном от того, где располагается функция main()). 
Выдать на консоль значения по-лученного вектора.*/


int main(int argc, char *argv[]){
    int n;
    printf("ВведиТЕ размер для двух массивов n на n: ");
    scanf("%d", &n);

    double **arr_1;
    double **arr_2;
    char c;

    arr_1 = (double**)malloc(n*sizeof(double*));
    arr_2 = (double**)malloc(n*sizeof(double*));
    for (int i  = 0; i<n; i++) arr_1[i] = (double*)malloc(n*sizeof(double));
    for (int i  = 0; i<n; i++) arr_2[i] = (double*)malloc(n*sizeof(double));

    double **arr_3;

    printf("Введите элементы первого массива:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Элемент [%d][%d]: ", i, j);
            scanf("%lf", &arr_1[i][j]);
        }
    }

    printf("Введите элементы второго массива:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Элемент [%d][%d]: ", i, j);
            scanf("%lf", &arr_2[i][j]);
        }
    }

    printf("Введите +, - или *:\n");
    scanf("%c", &c);

    if ('+' == c) arr_3 = arr_sum(arr_1, arr_2, n);



    printf("Итоговый массив:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", &arr_3[i][j]);
        }
        printf("/n");
    }


    return 0;
}