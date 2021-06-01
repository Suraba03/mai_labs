#include <stdio.h>
#include "matrix.h"
#include "vector.h"

int main(void)
{
    vector v, v1, v2;

    printf("Напишите '?' для получения помощи в использовании программы:\n");
    char c;

    while ((c = getchar()) != EOF) {
        if (c == '?') {
            printf("Набор команд:\n");
            printf("i - считать матрицу из файла и вывести в логическом виде, в виде вектора (следуйте указаниям в терминале).\n");
            printf("t - выполнить задание (следуйте указаниям в терминале).\n");
            printf("e - закончить сеанс.\n");
        } else if (c == 'i') {
            task_print(matrix_input(&v)); 
            printf("готово\n");
        } else if (c == 't') {
            multiply(&v1, &v2); 
            printf("все, результат получен\n");
        } else if (c == 'e') {
            printf("все на сегодня...\n");
            return 0;
        } else if (c != '?' && c != 'c' && c != 'p' && c != 'f' && c != 'd' && c != '\n' && c != '\t' && c != ' ') {
            printf("Не та буковка, попробуйте еще раз...\n");
        }
    }
    return 0;
}

