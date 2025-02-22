#include <stdio.h>
#include <math.h>

double triangle_perimeter(double a, double b, double c) {
    return a + b + c;
}

double triangle_area(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}


int main(int argc, char *argv[]){
    double a, b, c;

    printf("Стороны треугольника a b c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        fprintf(stderr, "Числа нужно было 3\n");
        return 1;
    }

    // Проверка на корректность неравенства треугольника
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        fprintf(stderr, "Не бывает такого\n");
        return 1;
    }

    // Вычисляем периметр и площадь, используя функции из triangle_utils.c
    double perimeter = triangle_perimeter(a, b, c);
    double area = triangle_area(a, b, c);

    printf("Периметр треугольника: %.2lf\n", perimeter);
    printf("Площадь треугольника: %.2lf\n", area);

    return 0;
}
