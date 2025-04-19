#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    double a, b, c;
    double x1, x2, d;

    while (1) {
        printf("input a: ");
        if (scanf("%lf", &a) != 1) {
            printf("Invalid input for a.  Exiting.\n");
            break;
        }
        printf("input b: ");
        if (scanf("%lf", &b) != 1) {
            printf("Invalid input for b.  Exiting.\n");
            break;
        }
        printf("input c: ");
        if (scanf("%lf", &c) != 1) {
            printf("Invalid input for c.  Exiting.\n");
            break;
        }

        d = b * b - 4 * a * c;

        if (d < 0) {
            printf("нет корней: d = %lf\n", d);
        } else {
            if (d == 0) {
                x1 = -b / (2 * a);
                printf("один корень:\n");
                printf("x1 = %lf\n", x1);
            } else {
                x1 = (-b + sqrt(d)) / (2 * a);
                x2 = (-b - sqrt(d)) / (2 * a);

                printf("x1 = %lf\n", x1);
                printf("x2 = %lf\n", x2);
            }
        }
        printf("\n");
    }

    return 0;
}