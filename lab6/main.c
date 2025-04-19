#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in = fopen("D:\\Education\\Program_C\\lab6\\input.txt", "r"), *out = fopen("D:\\Education\\Program_C\\lab6\\output.txt", "w");
    char name[256];
    int year;
    while (fscanf(in, "%s %*s %*s %d", name, &year) == 2)
        if (year > 1980) fprintf(out, "%s %d\n", name, year);
    fclose(in);
    fclose(out);
    return 0;
}