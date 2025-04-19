#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 40
#define FILE_NAME "D:\\Education\\Program_C\\lab8\\people.txt"

typedef struct {
    char name[MAX_NAME];
    int year;
    char gender;
    float height;
} Person;

// выбор пользователя
int sort_field1;
int sort_field2;

//чтение
int readFromFile(Person **people, int *count) {
    FILE *file = fopen(FILE_NAME, "r");

    *people = NULL;
    *count = 0;

    Person temp;

    while (fscanf(file, "%s %d %c %f", temp.name, &temp.year, &temp.gender, &temp.height) == 4) {
        (*count)++;

        *people = (Person *)realloc(*people, (*count) * sizeof(Person));

        strcpy((*people)[*count - 1].name, temp.name);
        (*people)[*count - 1].year = temp.year;
        (*people)[*count - 1].gender = temp.gender;
        (*people)[*count - 1].height = temp.height;
    }

    fclose(file);

    return 1; // гуд
}

// функции сравненияч
int compareByYear(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return p1->year - p2->year;
}

int compareByName(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return strcmp(p1->name, p2->name);
}

int compareByGender(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return p1->gender - p2->gender;
}

int compareByHeight(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;

    if (p1->height < p2->height) {
        return -1;
    } else if (p1->height > p2->height) {
        return 1;
    } else {
        return 0;
    }
}

// Функция для сравнения нескольких полей
int compareMultiple(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    int result = 0;

    // Сначала сравниваем по первому полю
    if (sort_field1 == 1) {
        result = compareByYear(a, b);
    } else if (sort_field1 == 2) {
        result = compareByName(a, b);
    } else if (sort_field1 == 3) {
        result = compareByGender(a, b);
    } else if (sort_field1 == 4) {
        result = compareByHeight(a, b);
    } //ПЫСЫ я немножко лентяй, поэтому без массива указателей

    // Если первые поля равны, сравниваем по второму полю
    if (result == 0) {
        if (sort_field2 == 1) {
            result = compareByYear(a, b);
        } else if (sort_field2 == 2) {
            result = compareByName(a, b);
        } else if (sort_field2 == 3) {
            result = compareByGender(a, b);
        } else if (sort_field2 == 4) {
            result = compareByHeight(a, b);
        }
    }

    return result;
}

// Функция для вывода данных на экран
void printData(Person *people, int count) {
    for (int i = 0; i < count; i++) {
        printf("Имя: %s, Год: %d, Пол: %c, Рост: %.2f\n",
               people[i].name, people[i].year, people[i].gender, people[i].height);
    }
}

int main() {
    Person *people = NULL; // Указатель на массив людей
    int count = 0;        // Количество людей

    // Читаем данные из файла
    if (!readFromFile(&people, &count)) {
        return 1; // Если ошибка, выходим
    }

    if (count == 0) {
        printf("В файле нет данных.\n");
        return 0;
    }

    // Получаем выбор пользователя
    printf("Выберите первое поле для сортировки (1: Дата рождения, 2: Имя, 3: Пол, 4: Рост): ");
    scanf("%d", &sort_field1);

    printf("Выберите второе поле (0 - нет, 1: Дата рождения, 2: Имя, 3: Пол, 4: Рост): ");
    scanf("%d", &sort_field2);

    // Сортируем данные
    if (sort_field2 == 0) { // Сортируем только по одному полю
        if (sort_field1 == 1) {
            qsort(people, count, sizeof(Person), compareByYear);
        } else if (sort_field1 == 2) {
            qsort(people, count, sizeof(Person), compareByName);
        } else if (sort_field1 == 3) {
            qsort(people, count, sizeof(Person), compareByGender);
        } else if (sort_field1 == 4) {
            qsort(people, count, sizeof(Person), compareByHeight);
        } else {
            printf("Неверный выбор поля.\n");
            free(people);
            return 1;
        }
    } else { // Сортируем по нескольким полям
        qsort(people, count, sizeof(Person), compareMultiple);
    }

    // Освобождаем память
    free(people);

    return 0;
}