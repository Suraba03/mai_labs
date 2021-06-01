#include <stdio.h>
#include "table.h"

int main(int argc, char *argv[])
{
    printf("Напишите '?' для получения помощи в использовании программы:\n");
    char c;

    while ((c = getchar()) != EOF) {
        if (c == '?') {
            printf("Набор команд:\n");
            printf("c - создать датасет (следуйте указаниям в терминале).\n");
            printf("a - добавить строки в датасет (следуйте указаниям в терминале).\n");
            printf("p - вывести датасет (следуйте указаниям в терминале).\n");
            printf("f - выполнить функцию (следуйте указаниям в терминале).\n");
            printf("d - удалить файл с датасетом (следуйте указаниям в терминале).\n");
            printf("e - закончить сеанс.\n");
        } else if (c == 'c') {
            create_dataset(); 
        } else if (c == 'a') {
            add_to_dataset(); 
        } else if (c == 'p') {
            print_dataset();
        } else if (c == 'f') {
            printf("Ответ = %d\n", parametr());
            printf("все, результат получен, вводите следующую команду\n");
        } else if (c == 'd') {
            delete_dataset();
        } else if (c == 'e') {
            printf("все на сегодня...\n");
            return 0;
        } else if (c != '?' && c != 'c' && c != 'p' && c != 'f' && c != 'd' && c != '\n' && c != '\t' && c != ' ') {
            printf("Не та буковка, попробуйте еще раз...\n");
        }
    }
    return 0;
}
