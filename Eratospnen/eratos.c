unsigned char nat[10000000];

#include <stdio.h>
#include <math.h>

#define SETBIT(b,k) (b |= (1 << (k&7)))
#define CLRBIT(b,k) (b &= ~(1 << (k&7)))
#define TESTBIT(b,k) ((b >> (k&7)) & 1)

int main(int argc, char **argv){

    long N;
    printf("input N:\n");
    scanf("%ld", &N);

    // Инициализация массива.
    for (long i = 0; i < (N + 7) / 8; i++) {
        nat[i] = 0xFF; // Все биты установлены в 1
    }

    // 0 и 1 не являются простыми числами.
    CLRBIT(nat[0], 0); // 0 не простое
    CLRBIT(nat[0], 1); // 1 не простое

    // Решето Эратосфена
    for (long i = 2; i <= sqrt(N); ++i) {
        if (TESTBIT(nat[i / 8], i)) { // Проверяем, является ли число простым
            for (long j = i * i; j <= N; j += i) {
                CLRBIT(nat[j / 8], j); // Помечаем кратные числа как составные
            }
        }
    }

    // Вывод простых чисел
    printf("Все простые числа до %ld:\n", N);
    for (long i = 2; i <= N; i++) {
        if (TESTBIT(nat[i / 8], i)) {
            printf("%ld ", i);
        }
    }
    printf("\n");

    return 0;
}