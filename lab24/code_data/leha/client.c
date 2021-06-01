#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    printf("Напишите 'h' для получения помощи в использовании программы:\n");
    char c;
    int value;
    int k = 0;
    int first, second;
    Tree *v;
    while ((c = getchar()) != EOF) {
        if (c == 'h') {
            printf("Набор команд:\n");
            printf("c - создать дерево (введите значение узла).\n");
            printf("a - добавить узел в дерево (введите значение родительского и нового узла).\n");
            printf("d - удалить узел из дерева (введите значение узла).\n");
            printf("p - графическое представление дерева.\n");
            printf("l - вывести число листьев.\n");
            printf("b - удалить дерево.\n");
        } else if (c == 'c' && k == 0) {
            k++;
            scanf("%d", &value);
            v = create_tree(value);
        } else if (c == 'c' && k != 0) {
            printf("Дерево уже существует.\n");
        } else if (c == 'a' && k != 0) {
            scanf("%d%d", &first, &second);
            Tree* first_finder = find_node(v, first);
            Tree* second_finder = find_node(v, second);
            if (first_finder != NULL && second_finder == NULL) {
                add_node(v, first, second);
            } else if (first_finder == NULL) {
                printf("Такой узел не существует.\n");
            } else if (second_finder != NULL) {
                printf("Такой узел уже существует.\n");
            }
        } else if (c == 'a' && k == 0) {
            printf("Дерево не существует.\n");
        } else if (c == 'd' && k != 0) {
            scanf("%d", &value);
            Tree* finder = find_node(v, value);
            if (finder != NULL) {
                if (finder == v) {
                    destroy_tree(&v);
                    v = NULL;
                    k--;
                } else {
                    delete_node(v, value);
                }
            } else {
                printf("Такой узел не существует.\n");
            }
        } else if (c == 'd' && k == 0) {
            printf("Дерево не существует.\n");
        } else if (c == 'p' && k != 0) {
            tree_print(v);
        } else if (c == 'p' && k == 0) {
            printf("Дерево не существует.\n");
        } else if (c == 'l' && k != 0) {
            int l = leaf_search(v);
            printf("Число листьев: %d\n", l);
        } else if (c == 'l' && k == 0) {
            printf("Дерево не существует.\n");
        } else if (c == 'b' && k != 0) {
            destroy_tree(&v);
            k--;
        } else if (c == 'b' && k == 0) {
            printf("Дерево не существует.\n");
        }
    }
}