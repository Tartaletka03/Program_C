#include <stdio.h>
#include <stdbool.h>
#include "func.h"

int main(int argc, char *argv[]) {
    double a = 1.0, b = 1.0, c = 1.0;

    printf("Введите длины сторон треугольника a b c: ");  // Более дружелюбное приглашение
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        fprintf(stderr, "Ошибка: Необходимо ввести три числа.\n"); // Более информативное сообщение об ошибке
        return 1; // Возвращаем код ошибки
    }

    // Проверка на корректность неравенства треугольника и положительность сторон
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        fprintf(stderr, "Ошибка: Треугольник с такими сторонами не существует.\n");
        return 1;
    }

    // Вычисляем периметр и площадь, используя функции из triangle_utils.c
    double perimeter = triangle_perimeter(a, b, c);
    double area = triangle_area(a, b, c);

    printf("Периметр треугольника: %.2lf\n", perimeter);
    printf("Площадь треугольника: %.2lf\n", area);

    return 0;
}