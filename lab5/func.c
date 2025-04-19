#include <stdio.h>
#include <stdlib.h>
#include "func.h"

double** arr_sum(double** arr_1, double** arr_2, int n) {
    double** arr_3 = (double**)malloc(n * sizeof(double*));
    if (arr_3 == NULL) return NULL;
    for (int i = 0; i < n; i++) {
        arr_3[i] = (double*)malloc(n * sizeof(double));
        if (arr_3[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(arr_3[j]);
            }
            free(arr_3);
            return NULL;
        }
        for (int j = 0; j < n; j++) {
            arr_3[i][j] = arr_1[i][j] + arr_2[i][j];
        }
    }
    return arr_3;
}

double** arr_sub(double** arr_1, double** arr_2, int n) {
     double** arr_3 = (double**)malloc(n * sizeof(double*));
     if (arr_3 == NULL) return NULL;
    for (int i = 0; i < n; i++) {
        arr_3[i] = (double*)malloc(n * sizeof(double));
        if (arr_3[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(arr_3[j]);
            }
            free(arr_3);
            return NULL;
        }
        for (int j = 0; j < n; j++) {
            arr_3[i][j] = arr_1[i][j] - arr_2[i][j];
        }
    }
    return arr_3;
}

double** arr_mul(double** arr_1, double** arr_2, int n) {
    double** arr_3 = (double**)malloc(n * sizeof(double*));
    if (arr_3 == NULL) return NULL;
    for (int i = 0; i < n; i++) {
        arr_3[i] = (double*)malloc(n * sizeof(double));
        if (arr_3[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(arr_3[j]);
            }
            free(arr_3);
            return NULL;
        }
        for (int j = 0; j < n; j++) {
            arr_3[i][j] = 0;
            for (int k = 0; k < n; k++) {
                arr_3[i][j] += arr_1[i][k] * arr_2[k][j];
            }
        }
    }
    return arr_3;
}