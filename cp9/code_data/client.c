#include <stdio.h>
#include <stdlib.h>
#include "func.h"


int main(void)
{
    printf("Напишите '?' для получения помощи в использовании программы:\n");
    char c;

    const int N = 50;
	int i, cnt, action;
	long key;
	char ch;
	row mass[N];
	FILE *file = fopen("test.txt", "r");

    if (file == NULL) {
        printf("Ошибка при открытии файла\n");
        return 0;
    }
    i = 0;
    while (i < N && fscanf(file, "%ld", &mass[i]._key) == 1) {
        fscanf(file, "%c", &ch);
        getRow(file, mass[i]._str, sizeof(mass[i]._str));
        i++;
    }
    fclose(file);
    cnt = i;

    while ((c = getchar()) != EOF) {
        if (c == '?') {
            printf("Набор команд:\n");
            printf("1 - вывести таблицу.\n");
            printf("2 - найти и вывести в таблице строку по ключу.\n");
            printf("3 - отсортировать таблицу по ключам.\n");
            printf("4 - перемешать строки таблицы.\n");
            printf("5 - перевести таблицу в обратный порядок.\n");
            printf("6 - закончить сеанс.\n");
        } else if (c == '1') {
            printTable(mass, cnt); 
        } else if (c == '2') {
            if (!isSorted(mass, cnt)) {
                printf("Таблица не отсортирована...\n");
            } else {
                printf("Ввелите ключик: ");
                scanf("%ld", &key);
                i = binSearch(mass, cnt, key);
                if (i > -1) {
                    printf("строка по ключу: %s\n", mass[i]._str);
                } else {
                    printf("Элементов с таким ключом не существует!\n");
                }
            } 
        } else if (c == '3') {
            shakerSort(mass, cnt);
        } else if (c == '4') {
            shuffle(mass, cnt);
        } else if (c == '5') {
            reverse(mass, cnt);
        } else if (c == '6') {
            printf("все на сегодня...\n");
            return 0;
        } else if (c != '?' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '\n' && c != '\t' && c != ' ') {
            printf("Не та буковка, попробуйте еще раз...\n");
        }
    }
    return 0;
}
