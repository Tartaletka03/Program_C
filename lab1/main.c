#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    double a = 1.0, b = 6.0, c = 3.0;
    double x1, x2, d;

    d = b*b - 4*a*c;

    if (d < 0) {
        printf("нет корней: d = %lf\n", d);
    } else {
        if (d == 0) {
            x1 = -b / (2 * a);
            printf("один корень:\n");
            printf("x1 = %lf\n", x1);
        } else {
            x1 = (-b + sqrt(d)) / (2*a);
            x2 = (-b - sqrt(d)) / (2*a);

            printf("x1 = %lf\n", x1);
            printf("x2 = %lf\n", x2);
        }
    }

    return 0;
}