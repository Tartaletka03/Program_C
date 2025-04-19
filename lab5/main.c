#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(int argc, char *argv[]) {
    int n;
    printf("Введите размер для двух массивов n на n: "); // Исправлена опечатка
    scanf("%d", &n);

    double **arr_1;
    double **arr_2;
    double **arr_3 = NULL; // Инициализируем arr_3, чтобы избежать неопределенного значения
    char c;

    // Выделение памяти для массивов
    arr_1 = (double**)malloc(n * sizeof(double*));
    if (arr_1 == NULL) {
        perror("Ошибка выделения памяти для arr_1");
        return 1;
    }
    arr_2 = (double**)malloc(n * sizeof(double*));
    if (arr_2 == NULL) {
        perror("Ошибка выделения памяти для arr_2");
        free(arr_1);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        arr_1[i] = (double*)malloc(n * sizeof(double));
        if (arr_1[i] == NULL) {
            perror("Ошибка выделения памяти для arr_1[i]");
            for (int j = 0; j < i; j++) {
                free(arr_1[j]);
            }
            free(arr_1);
            free(arr_2);
            return 1;
        }
    }
    for (int i = 0; i < n; i++) {
        arr_2[i] = (double*)malloc(n * sizeof(double));
        if (arr_2[i] == NULL) {
            perror("Ошибка выделения памяти для arr_2[i]");
            for (int j = 0; j < i; j++) {
                free(arr_2[j]);
            }
            free(arr_2);

            for (int j = 0; j < n; j++) {
                free(arr_1[j]);
            }
            free(arr_1);
            return 1;
        }
    }


    printf("Введите элементы первого массива:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Элемент [%d][%d]: ", i, j);
            if (scanf("%lf", &arr_1[i][j]) != 1) {
                fprintf(stderr, "Ошибка ввода\n");
                // Освобождение памяти перед выходом
                for (int k = 0; k < n; k++) {
                    free(arr_1[k]);
                    free(arr_2[k]);
                }
                free(arr_1);
                free(arr_2);
                return 1;
            }
        }
    }

    printf("Введите элементы второго массива:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Элемент [%d][%d]: ", i, j);
            if (scanf("%lf", &arr_2[i][j]) != 1) {
                fprintf(stderr, "Ошибка ввода\n");
                // Освобождение памяти перед выходом
                for (int k = 0; k < n; k++) {
                    free(arr_1[k]);
                    free(arr_2[k]);
                }
                free(arr_1);
                free(arr_2);
                return 1;
            }
        }
    }

    printf("Введите +, -, или *:\n");
    scanf(" %c", &c);

    if ('+' == c) arr_3 = arr_sum(arr_1, arr_2, n);
    else if ('-' == c) arr_3 = arr_sub(arr_1, arr_2, n);
    else if ('*' == c) arr_3 = arr_mul(arr_1, arr_2, n);
    else {
        printf("Некорректная операция\n");
        // Освобождение памяти перед выходом
        for (int i = 0; i < n; i++) {
            free(arr_1[i]);
            free(arr_2[i]);
        }
        free(arr_1);
        free(arr_2);
        return 1;
    }

    if (arr_3 == NULL) {
        fprintf(stderr, "Ошибка при выполнении операции с массивами.\n");
        // Освобождение памяти перед выходом
        for (int i = 0; i < n; i++) {
            free(arr_1[i]);
            free(arr_2[i]);
        }
        free(arr_1);
        free(arr_2);
        return 1;
    }



    printf("Итоговый массив:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", arr_3[i][j]);
        }
        printf("\n");
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