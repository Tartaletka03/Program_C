#include <stdio.h>
#include <stdlib.h>

double** arr_sum(double** arr_1, double** arr_2, int n){
    double **arr_3;
    arr_3 = (double**)malloc(n*sizeof(double*));
    for (int i  = 0; i<n; i++) arr_3[i] = (double*)malloc(n*sizeof(double));


    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            arr_3[i][j] = arr_1[i][j] + arr_2[i][j];
        }
    }

    return arr_3;
}