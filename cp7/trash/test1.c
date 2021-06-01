#include <stdio.h>
#include "vector.h" 
#include "matrix.h" 

int main(void)
{
    /*vector v;
    create_vector(&v);
    push_back(&v, 1); // 1 1 1 2 3 0 2 3 2 0 3 2 2 0 0
    push_back(&v, 1);
    push_back(&v, 1);
    push_back(&v, 2);
    push_back(&v, 3);
    push_back(&v, 0);
    push_back(&v, 2);
    push_back(&v, 3);
    push_back(&v, 2);
    push_back(&v, 0);
    push_back(&v, 3);
    push_back(&v, 2);
    push_back(&v, 2);
    push_back(&v, 0);
    push_back(&v, 0);
    push_back(&v, 4);
    push_back(&v, 1);
    push_back(&v, 0);
    push_back(&v, 0);
    printf("вот столько элементов = %d\n", count_elements(&v));
    printf("вот вектор: ");
    print_vector(&v);
    int i = 1; int k = 2;
    printf("серч v для i=%d k=%d == %d\n", i, k, search(&v, i, k));

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("%d ", search(&v, i, j));
        }
        printf("\n");
    }*/
    int c[3][3] = {{1, 0, 0}, 
                   {0, 3, 0},
                   {0, 0, 0}};
    printf("диагональная?\n");
    int flag = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
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
    return 0;
}