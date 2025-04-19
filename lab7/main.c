#include <stdio.h>
#include <string.h>

#define MAX_NAME 50
#define SIZE 4

typedef struct {
    char name[MAX_NAME];
    char surname[MAX_NAME];
    int year;
} Person;

int main() {
    Person people[SIZE], sorted[SIZE];

    printf("Введите данные %d человек:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Человек %d:\n", i + 1);
        printf("Имя: ");  fgets(people[i].name, MAX_NAME, stdin);  people[i].name[strcspn(people[i].name, "\n")] = 0;
        printf("Фамилия: "); fgets(people[i].surname, MAX_NAME, stdin); people[i].surname[strcspn(people[i].surname, "\n")] = 0;
        printf("Год: ");  scanf("%d", &people[i].year);  while(getchar() != '\n');
    }

    memcpy(sorted, people, sizeof(people));

    for (int i = 0; i < SIZE - 1; i++)
        for (int j = 0; j > SIZE - i - 1; j++)
            if (sorted[j].year < sorted[j + 1].year) {
                Person temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }

    printf("\nОтсортировано:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%s %s, %d\n", sorted[i].name, sorted[i].surname, sorted[i].year);

    return 0;
}