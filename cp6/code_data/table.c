#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "table.h"

#define SIZE 128

void create_dataset()
{
    FILE *f;
    char name[SIZE];

    printf("Пожалуйста, введите название файла с датасетом: ");
    scanf("%s", name);

    if ((f = fopen(name, "w")) == NULL) {
        printf("Ошибка, невозможно открыть файл");
        exit(1);
    }
    int number_of_strings;

    printf("Сколько человек хотите записать? ");
    scanf("%d", &number_of_strings);

    performance prf;

    for(int i = 0; i < number_of_strings; i++) {
        if (i == 0) {
            printf("\t\tНОВЫЙ СТУДЕНТ\n");
        } else if (i == 1) {
            printf("\t\tЕЩЕ ОДИН\n");   
        } else {
            printf("\t\tИ ЕЩЕ ОДИН\n");   
        }
        printf("Пожалуйста, введите номер группы студента (студентки): ");
        scanf("%d", &prf.group_number);
        printf("Фамилию: ");
        scanf("%s", prf.surname);
        printf("Инициалы: ");
        scanf("%s", prf.initials);
        printf("Пол: ");
        scanf("%s", prf.gender);
        printf("Результат за матан: ");
        scanf("%d", &prf.calculus_score);
        printf("Результат за линал: ");
        scanf("%d", &prf.linal_score);
        printf("Результат за дм: ");
        scanf("%d", &prf.dm_score);
        printf("Результат за прогу: ");
        scanf("%d", &prf.cs_score);
        printf("Результат за курсач: ");
        scanf("%d", &prf.course_project_score);

        fwrite(&prf, sizeof(performance), 1, f);
    }
    fclose(f);
    printf("\nвсе, датасет создан, вводите следующую команду\n");
}

void add_to_dataset()
{
    FILE *f;
    char name[SIZE];

    printf("Пожалуйста, введите название файла с датасетом: ");
    scanf("%s", name);

    if ((f = fopen(name, "a")) == NULL) {
        printf("Ошибка, невозможно открыть файл");
        exit(1);
    }
    int number_of_strings;

    printf("Сколько человек хотите записать? ");
    scanf("%d", &number_of_strings);

    performance prf;

    for(int i = 0; i < number_of_strings; i++) {
        if (i == 0) {
            printf("\t\tНОВЫЙ СТУДЕНТ\n");
        } else if (i == 1) {
            printf("\t\tЕЩЕ ОДИН\n");   
        } else {
            printf("\t\tИ ЕЩЕ ОДИН\n");   
        }
        printf("Пожалуйста, введите номер группы студента (студентки): ");
        scanf("%d", &prf.group_number);
        printf("Фамилию: ");
        scanf("%s", prf.surname);
        printf("Инициалы: ");
        scanf("%s", prf.initials);
        printf("Пол: ");
        scanf("%s", prf.gender);
        printf("Результат за матан: ");
        scanf("%d", &prf.calculus_score);
        printf("Результат за линал: ");
        scanf("%d", &prf.linal_score);
        printf("Результат за дм: ");
        scanf("%d", &prf.dm_score);
        printf("Результат за прогу: ");
        scanf("%d", &prf.cs_score);
        printf("Результат за курсач: ");
        scanf("%d", &prf.course_project_score);

        fwrite(&prf, sizeof(performance), 1, f);
    }
    fclose(f);
    printf("\nвсе, студенты добавлены в датасет, вводите следующую команду\n");
}

void print_dataset()
{
    FILE *f;

    printf("Пожалуйста, введите название файла с датасетом, который хотите распечатать: ");
    char name_dataset[SIZE];
    scanf("%s", name_dataset);
    
    if ((f = fopen(name_dataset, "r")) == NULL) {
        printf("Ошибка, невозможно открыть файл! ");
        exit(1);
    }
    performance prf_2;
    
    printf("\n| group number |     surname     | initials | gender | calculus score | linal score | dm score | comp science score | course project score |\n");
    
    while(fread(&prf_2, sizeof(performance), 1, f) != EOF && !feof(f)) {
        printf("| %12d | %15s | %8s | %6s | %14d | %11d | %8d | %18d | %20d |\n", prf_2.group_number, prf_2.surname, prf_2.initials, prf_2.gender, prf_2.calculus_score,
                                                                                           prf_2.linal_score, prf_2.dm_score, prf_2.cs_score, prf_2.course_project_score);
    }
    fclose(f);
    printf("\nвсе, датасет распечатан, вводите следующую команду\n");
}

void print_unique(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                arr[i] = 0;
                break;
            }
        }
    }    
}

float max_diff(float arr[], int cnt)
{
    float min = arr[0], max = arr[0]; 
    for (int i = 0; i < cnt; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    for (int i = 0; i < cnt; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return (max - min);
}

int parametr()
{
    FILE *f;
    char dataset_name[SIZE];
    
    printf("Название файла с датасетом: ");
    scanf("%s", dataset_name);
    
    if ((f = fopen(dataset_name, "r")) == NULL) {
        printf("Ошибка, невозможно открыть файл! ");
        exit(1);
    }
    performance prf_;
    performance *data = &prf_;

    int groups[SIZE] = {0};
    int i = 0;

    while (fread(data, sizeof(performance), 1, f) != EOF && !feof(f)) {
        groups[i] = prf_.group_number;
        i++;
    }
    print_unique(groups, i);

    float max = -1;
    int group_max;

    for (int j = 0; j < i; j++) {
        if (groups[j] != 0) {
            float av_sc[SIZE];
            int n = 0;
            rewind(f);
            while (fread(data, sizeof(performance), 1, f) != EOF && !feof(f)) {
                if (prf_.group_number == groups[j]) {
                    av_sc[n] = (prf_.calculus_score + prf_.linal_score + prf_.dm_score + prf_.cs_score + prf_.course_project_score) / 5;   
                    n++; 
                }
            }
            if (max_diff(av_sc, n) > max) {
                max = max_diff(av_sc, n);
                group_max = groups[j];
            }
        }

    }
    fclose(f);

    return group_max;

}

void delete_dataset()
{
    char dataset_name[SIZE];
    printf("Название файла с датасетом: ");
    scanf("%s", dataset_name);
    remove(dataset_name);
    printf("\nвсе, датасет удален, вводите следующую команду\n");
}
