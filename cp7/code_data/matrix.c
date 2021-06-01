#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "vector.h"

int cnt_elem(char name[SIZE])
{
    int el = 0, cnt = 0;
    FILE* f = fopen(name, "r");

    while (fscanf(f, "%d", &el) && !feof(f)) {
        cnt++;
    }
    fclose(f);
    return cnt;
}

int cnt_lines(char name[SIZE])
{
    int cnt = 0;
    FILE* f = fopen(name, "r");

    while (!feof(f)) {
        if (fgetc(f) == '\n') {
            cnt++;
        }
    }
    fclose(f);
    return cnt;
}

vector *matrix_input(vector *v)
{
    create_vector(v);

    char name[SIZE];
    printf("введи название файла с матрицей пж: ");
    scanf("%s", name);

    FILE *f = fopen(name, "r");
    if (f == NULL) {
        printf("Файл не открылся, может создашь его...\n");
        exit(1);
    }
    int n, m;
    n = cnt_lines(name);
    m = cnt_elem(name) / n;
    int c[n][m];

    int el;
    // считывание
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(f, "%d", &el);
            c[i][j] = el;
        }
    }
    // заполнение вектора 
    for (int p = 0; p < n; p++) {
        int flag = 0;
        //
        for (int g = 0; g < m; g++) {
            if (c[p][g] != 0) { // смотрим только ненулевые элементы
                if (flag == 0) { // первый элемент в строке
                    //push_back(&v, p + 1);
                    push_back(v, p + 1); // кладем в вектор номер строки (тут конец строки)
                    flag = 1;
                }
                push_back(v, g + 1); // кладем в вектор номер столбца
                push_back(v, c[p][g]); // и само значение 
            }
        }
        //
        if (flag != 0) { // вектор заполеен
            push_back(v, 0);
        }
    }
    push_back(v, 0);
    push_back(v, n);
    push_back(v, m);
    fclose(f);
    return v;
}

void task_print(vector *v)
{
    if (v != NULL) {
        printf("логический вид: ( ");
        for (int i = 0; i < v->size - 2; i++) {
            printf("%d ", v->data[i]);
        }
        printf(")\n");
        printf("физический вид:\n");
        // здесь вывод
        for (int i = 1; i <= v->data[v->size - 2]; i++) {
            for (int j = 1; j <= v->data[v->size - 1]; j++) {
                printf("%d ", search(v, i, j));
            }
            printf("\n");
        }   
    }
}

void natural_print(vector* v)
{
    int n = v->data[v->size - 2];
    int m = v->data[v->size - 1];
    int a[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }
    if (v->size == 0) {
        return;
    }
    int l = 0; // индекс строки
    int k = 0; // индекс столбца
    int count = 0;
    int value;
    for (int i = 0; i < v->size - 5; i++) {
        if (count == 0) {
            l = v->data[i] - 1;
            k = v->data[i + 1] - 1;
            value = v->data[i + 2];
            a[l][k] = value;
            count++;
            if (v->data[i + 3] == 0) {
                count--;
                i = i + 4;
            } else {
                i = i + 3;
            }
        } else {
            k = v->data[i] - 1;
            value = v->data[i + 1];
            a[l][k] = value;
            if (v->data[i + 2] == 0) {
                count--;
                i = i + 3;
            } else {
                i = i + 2;
            }
        }
    }
    printf("Естественная форма матрицы:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int search(vector *v, int i, int j)  // 
{
    int a = 0;
    while (v->data[a] <= i) {
        if (v->data[a] == i) 
        {
            a++;
            while (v->data[a] != j) {
                if (v->data[a] != 0) {
                    a += 2;
                } else {
                    return 0;
                }
            }
            if (v->data[a] == j) {
                return v->data[a + 1];
            }
        }
        else
        {
            while (v->data[a] != 0) {
                a++;    
            } 
            a++;
        }
    }   
}

void multiply(vector *v1, vector *v2)
{
    printf("файл с мат1: ");
    v1 = matrix_input(v1);
    task_print(v1);
    printf("файл с мат2: ");
    v2 = matrix_input(v2);
    task_print(v2);
    int g = v1->data[v1->count_elem - 2];
    int l = v2->data[v2->count_elem - 1];
    int c[g][l];

    if (v1->data[v1->count_elem - 1] != v2->data[v2->count_elem - 2]) {
        printf("умножение невозможно!\n");
    }
    else 
    {
        for (int i = 1; i <= g; i++) { // строки первой
            for (int j = 1; j <= l; j++) { // столбцы второй
                c[i][j] = 0;
                for (int k = 1; k <= v1->data[v1->count_elem - 1]; k++) {
                    c[i][j] = c[i][j] + search(v1, i, k) * search(v2, k, j); //A[i][k] * B[k][j];
                }
            }
        }
        printf("результат\n");
        for (int i = 1; i <= g; i++) {
            for (int j = 1; j <= l; j++) {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
        printf("диагональная?\n");
        int flag = 1;
        for (int i = 1; i <= g; i++) {
            for (int j = 1; j <= l; j++) {
                if (i != j && c[i][j] != 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }
        if (flag == 1) printf("Да\n");
        if (flag == 0) printf("Нет\n");
    }
}
