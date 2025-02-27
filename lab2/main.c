#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*ЗАДАНИЕ 2

Объявить массив данных типа double размером 3 на 3.
 Ввести с консоли его значения, вывести на консоль сумму его элементов, 
 расположенных на главной диагонали и сумму элементов, расположенных на побочной диагонали.

Объявить массив данных типа int размером 2 на 2. Ввести с консоли его значения, вывести на консоль квадрат данной матрицы.*/


int main(int argc, char *argv[]){
    // запрошиваем юзера ввести в терминал значения массива, предварительно наметив его
    double double_array[3][3];
    double main_diagonal_sum = 0.0;
    double secondary_diagonal_sum = 0.0;

    printf("Введите элементы массива 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Элемент [%d][%d]: ", i, j);
            scanf("%lf", &double_array[i][j]);

            if (i == j) {
                main_diagonal_sum += double_array[i][j];
            }
            if (i + j == 2) {
                secondary_diagonal_sum += double_array[i][j];
            }
        }
    }

    printf("Сумма элементов главной диагонали: %lf\n", main_diagonal_sum);
    printf("Сумма элементов побочной диагонали: %lf\n", secondary_diagonal_sum);

    // массив с целыми числами 2 на 2
    int int_array[2][2];
    int squared_array[2][2];

    printf("Введите элементы массива int 2x2:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Элемент [%d][%d]: ", i, j);
            scanf("%d", &int_array[i][j]);
        }
    }

    // суммирую в циклах
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            squared_array[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                squared_array[i][j] += int_array[i][k] * int_array[k][j];
            }
        }
    }

    printf("Квадрат матрицы:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", squared_array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
