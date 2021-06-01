#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SIZE 128

typedef struct performance {
    int group_number;
    char surname[SIZE];
    char initials[SIZE];
    char gender[SIZE];
    int calculus_score;
    int linal_score;
    int dm_score;
    int cs_score;
    int course_project_score;
} performance;

void create_dataset()
{
    FILE *f;
    char name[SIZE];

    printf("Please, enter a name of your dataset: ");
    scanf("%s", name);

    if ((f = fopen(name, "w")) == NULL) {
        printf("Error, can't open a file!");
        exit(1);
    }
    int number_of_strings;

    printf("How much strings you want to do? ");
    scanf("%d", &number_of_strings);

    performance prf;

    for(int i = 0; i < number_of_strings; i++) {
        printf("\t\tNEW STUDENT\n");
        printf("Please, enter number of group: ");
        scanf("%d", &prf.group_number);
        printf("Please, enter surname: ");
        scanf("%s", prf.surname);
        printf("Please, enter initials: ");
        scanf("%s", prf.initials);
        printf("Please, enter gender: ");
        scanf("%s", prf.gender);
        printf("Please, enter calculus score: ");
        scanf("%d", &prf.calculus_score);
        printf("Please, enter linal score: ");
        scanf("%d", &prf.linal_score);
        printf("Please, enter discrete math score: ");
        scanf("%d", &prf.dm_score);
        printf("Please, enter computer science score: ");
        scanf("%d", &prf.cs_score);
        printf("Please, enter course project score: ");
        scanf("%d", &prf.course_project_score);

        fwrite(&prf, sizeof(performance), 1, f);
    }
    fclose(f);
}

void print_dataset()
{
    FILE *f;

    printf("Enter a name of dataset which you want print: ");
    char name_dataset[SIZE];
    scanf("%s", name_dataset);
    
    if ((f = fopen(name_dataset, "r")) == NULL) {
        printf("Error,can't open a file!");
        exit(1);
    }
    performance prf_2;
    
    printf("\n| group number |     surname     | initials | gender | calculus score | linal score | dm score | comp science score | course project score | average score |\n");
    
    while(fread(&prf_2, sizeof(performance), 1, f) != EOF && !feof(f)) {
        printf("| %12d | %15s | %8s | %6s | %14d | %11d | %8d | %18d | %20d | %13.5f |\n", prf_2.group_number, prf_2.surname, prf_2.initials, prf_2.gender, prf_2.calculus_score,
                                                                                           prf_2.linal_score, prf_2.dm_score, prf_2.cs_score, prf_2.course_project_score, 4.345);
    }
    fclose(f);
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
    
    printf("Name of dataset: ");
    scanf("%s", dataset_name);
    
    if ((f = fopen(dataset_name, "r")) == NULL) {
        printf("Error, can't open a file!");
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


    //
    printf("142 строка: Вот такой массивчик получился с нулями: ");
    for (int y = 0; y < i; y++) {
        printf("%d ", groups[y]);
    }
    printf("\n");
    //



    float max = -1;
    int group_max;

    for (int j = 0; j < i; j++) {
        if (groups[j] != 0) {
            //
            printf("\n157 строка: вот такая группа сейчас будет рассматриваться: (((%d)))\n\n", groups[j]);
            //
            float av_sc[SIZE];
            int n = 0;
            rewind(f);
            while (fread(data, sizeof(performance), 1, f) != EOF && !feof(f)) {
                //
                printf("163 строка, группа из таблицы: %d, группа из собранного мной массива: %d\n\n", prf_.group_number, groups[j]);
                //
                if (prf_.group_number == groups[j]) {
                    //
                    printf("зашел в иф на 167 строке\n\n");
                    //
                    av_sc[n] = (prf_.calculus_score + prf_.linal_score + prf_.dm_score + prf_.cs_score + prf_.course_project_score) / 5;   
                    n++; 
                }
            }
            //
            printf("\n\n174 строка: Вот такой массивчик (колво эл-ов: %d) из средних получился: ", n);
            for (int y = 0; y < n; y++) {
                printf("%.3f ", av_sc[y]);
            }
            printf("\n\n");
            //
            //
            printf("\n\n181 строка: max_diff = %.3f\n\n", max_diff(av_sc, n));
            //
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
    printf("Name of dataset: ");
    scanf("%s", dataset_name);
    remove(dataset_name);
}

int main(void)
{
    create_dataset();
    print_dataset();
    printf("Ответ = %d\n", parametr());
    return 0;
}