#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*ЗАДАНИЕ 3

Ввести с консоли строку символов произвольной длины (до 80 символов). 
По-менять в ней все маленькие символы ‘a’ и ‘b’ на заглавные и вывести на консоль полученную строку.*/


int main(int argc, char *argv[]){
    char str[81]; // Строка для ввода (до 80 символов + '\0')

    printf("Ввод: ");
    fgets(str, sizeof(str), stdin); // Читаем строку
    

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'b') {
            str[i] = toupper(str[i]); // Преобразуем в верхний регистр
        }
        if (str[i] == '.') {
            str[i] = '!';
        }
    }

    printf("Измененная строка: %s\n", str);

    return 0;
}