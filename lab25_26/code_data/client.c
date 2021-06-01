#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "Qsort.h"

int main()
{
    list l, l1, l2;
    int numb;
    char c;
    int k, flag = 0;

    printf("Напишите '?' для получения помощи в использовании программы:\n");

    while ((c = getchar()) != EOF) {
        if (c == '?') {
            printf("Набор команд:\n");
            printf("c - создать списочек.\n");
            printf("b - добавить элемент в конец списка (введите число).\n");
            printf("p - напечатать список.\n");
            printf("d - удалить элемент по индексу.\n");
            printf("a - добавить элемент по индексу.\n");
            printf("k - количество элементов в списке.\n");
            printf("f - увеличить список до К элементов введенным элементом.\n");
            printf("l - конкатенация двух списков и вывод отсортированного списка конкатенаций.\n");
            printf("е - закончить сеанс.\n");
        }
        else if (c == 'c') {
            printf("создаем списочек\n");
            create_list(&l, 0);
            flag = 1;
            printf("все, список создан, вводите следующую команду\n");
        }
        else if (c == 'b' && flag != 0) {
            printf("введите число: ");
            scanf("%d", &numb);
            printf("добаляем элемент [%d] в конец списка\n", numb);
            push_back(&l, numb);
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
            printf("введите число: ");
            scanf("%d", &numb);
            printf("введите новое количество элементов: ");
            scanf("%d", &k);
            add_to_K_elements(&l, numb, k);
            printf("все, элементы добавлен, вводите следующую команду\n");
        }
        else if (c == 'l') {
            printf("введите `1`, если хотите создать новые списки.\n");
            printf("введите `2`, если хотите использовать свои списки.\n");
            char ch;
            scanf("%c", &ch);
            if (ch == '1') {
                create_list(&l1, 0);
                create_list(&l2, 0);
                printf("введите колво элементов l1: ");
                list_input(&l1);
                printf("введите колво элементов вектора l2: ");
                list_input(&l2);
                printf("сконкатенированный список: ");
                list *L = lists_concat(&l1, &l2);
                print_list(L);
                qs(L->elements, 0, L->number_of_elements - 1);
                printf("отсортированный список:");
                print_list(L);
            } else {
                printf("здесь сконкатенированный список: ");
                print_list(lists_concat(&l1, &l2));
                printf("\n");
            }
            printf("готово\n");
        }
        else if (flag == 0 && (c == 'c' || c == 'b' || c == 'p' || c == 'd' || c == 'a' || c == 'e' || c == 'k' || c == 'f' || c == '?') && (c != ' ' && c != '\n' && c != '\t')) {
            printf("список не создан, используйте команду _с_\n");
        }
    }
    return 0;

}