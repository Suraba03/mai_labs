#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    list l;
    Actions act;
    char c;
    int k, flag = 0;

    printf("Напишите '?' для получения помощи в использовании программы:\n");

    while ((c = getchar()) != EOF) {
        if (c == '?') {
            printf("цифры от 0 до 4 = STEP_FORW(0), STEP_BACK,(1) STEP_LEFT(2), STEP_RIGHT(3), CH_DIR_180(4)).\n");
            printf("Набор команд:\n");
            printf("c - создать списочек.\n");
            printf("b - добавить элемент в конец списка(введите цифры от 0 до 4, они обозначают действия: STEP_FORW(0), STEP_BACK,(1) STEP_LEFT(2), STEP_RIGHT(3) или CH_DIR_180(4)).\n");
            printf("p - напечатать список.\n");
            printf("d - удалить элемент по индексу.\n");
            printf("a - добавить элемент по индексу.\n");
            printf("е - закончить сеанс.\n");
            printf("k - количество элементов в списке.\n");
            printf("f - увеличить список до К элементов введенным элементом.\n");
        }
        else if (c == 'c') {
            printf("создаем списочек\n");
            create_list(&l, 0);
            flag = 1;
            printf("все, список создан, вводите следующую команду\n");
        }
        else if (c == 'b' && flag != 0) {
            printf("введите действие: ");
            scanf("%d", &act);
            while (act < 0 || act > 4) {
                printf("Введите чиселки от 0 до 4\n");
                scanf("%d", &act);  
            }
            printf("добаляем элемент ");
            printAction(act);
            printf(" в конец списка\n");
            push_back(&l, act);
            printf("все, элемент добавлен в конец, вводите следующую команду\n");
        }
        else if (c == 'p' && flag != 0) {
            printf("печатаем списочек\n");
            print_list(&l);
            printf("все, список напечатан, вводите следующую команду\n");
        }
        else if (c == 'd' && flag != 0) {
            printf("удаляем элемент по индексу\n");
            delete_element_by_index(&l);
            printf("все, элемент удален, вводите следующую команду\n");
        }
        else if (c == 'a' && flag != 0) {
            printf("добавляем элемент по индексу\n");
            add_by_index(&l);
            printf("все, элемент добавлен, вводите следующую команду\n");

        }
        else if (c == 'e') {
            printf("все на сегодня...\n");
            return 0;
        }
        else if (c == 'k' && flag != 0) {
            printf("выводим количество элементов в списке\n");
            printf("%d\n", number_of_elements(&l));
            printf("все, готово, вводите следующую команду\n");
        }
        else if (c == 'f' && flag != 0) {
            printf("увеличиваем список\n");
            printf("введите действие: ");
            scanf("%d", &act);
            while (act < 0 || act > 4) {
                printf("Введите чиселки от 0 до 4\n");
                scanf("%d", &act);  
            }
            printf("введите новое количество элементов: ");
            scanf("%d", &k);
            add_to_K_elements(&l, act, k);
            printf("все, элементы добавлен, вводите следующую команду\n");
        }
        else if (flag == 0 && (c == 'c' || c == 'b' || c == 'p' || c == 'd' || c == 'a' || c == 'e' || c == 'k' || c == 'f' || c == '?') && (c != ' ' && c != '\n' && c != '\t')) {
            printf("список не создан, используйте команду _с_\n");
        }
    }
    return 0;

}