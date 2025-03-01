#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(int argc, char *argv[]) {
    int n;
    printf("ВведиТЕ размер для двух массивов n на n: ");
    scanf("%d", &n);

    double **arr_1;
    double **arr_2;
    char c;

    arr_1 = (double**)malloc(n * sizeof(double*));
    arr_2 = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) arr_1[i] = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) arr_2[i] = (double*)malloc(n * sizeof(double));

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

    printf("Введите +, -, или *:\n");
    scanf(" %c", &c); // Важно добавить пробел перед %c

    if ('+' == c) arr_3 = arr_sum(arr_1, arr_2, n);
    else if ('-' == c) arr_3 = arr_sub(arr_1, arr_2, n);
    else if ('*' == c) arr_3 = arr_mul(arr_1, arr_2, n);
    else {
        printf("Некорректная операция\n");
        return 1; // Или другая обработка ошибки
    }

    printf("Итоговый массив:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", arr_3[i][j]); // ИСПРАВЛЕНО: убран &
        }
        printf("\n"); // ИСПРАВЛЕНО: Правильный перевод строки
    }

   // Освобождение памяти
    for (int i = 0; i < n; i++) {
        free(arr_1[i]);
        free(arr_2[i]);
        free(arr_3[i]);
    }
    free(arr_1);
    free(arr_2);
    free(arr_3);


    return 0;
}