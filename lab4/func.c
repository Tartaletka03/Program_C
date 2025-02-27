#include <math.h>
#include "func.h"

double triangle_perimeter(double a, double b, double c) {
    return a + b + c;
}

double triangle_area(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}