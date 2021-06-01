#include <stdio.h>
#include "tree.h"


int main(int argc, char *argv[])
{
    printf("Напишите '?' для получения помощи в использовании программы:\n");

    char c;
    int value, node_v;
    int cnt_root = 0;
    tree *root;

    while ((c = getchar()) != EOF) {
        if (c == '?') {
            printf("Набор команд:\n");
            printf("c - создать корень (введите значение корня).\n");
            printf("a - добавить узел в дерево (введите значение нового узла).\n");
            printf("d - удалить узел из дерева (введите значение удаляемого узла).\n");
            printf("p - вывести дерево.\n");
            printf("i - вывести элементы дерева в порядке возрастания.\n");
            printf("l - все ли листья на одном уровне?\n"); // лучше f
            printf("b - удалить дерево.\n"); // лучше r
            printf("e - завершить сеанс.\n");
        } else if (c == 'c' && cnt_root == 0) {
            printf("начало\n");
            cnt_root++;
            printf("введите значение корня: ");
            scanf("%d", &value);
            root = tree_node_create(value);
            printf("конец\n");
        } else if (c == 'c' && cnt_root != 0) {
            printf("Корень уже существует!\n");
        } else if (c == 'a' && cnt_root != 0) {
            printf("начало\n");
            printf("введите значение узла: ");
            scanf("%d", &node_v);
            printf("конец\n");
            tree_add_node(root, node_v);
        } else if (c == 'a' && cnt_root == 0) {
            printf("Дерево не существует.\n");
        } else if (c == 'd' && cnt_root != 0) {
            printf("начало\n");
            printf("введите значение узла: ");
            scanf("%d", &node_v);
            printf("конец\n");
            root = tree_delete_node(root, node_v);
        } else if (c == 'd' && cnt_root == 0) {
            printf("Дерево не существует.\n");
        } else if (c == 'p' && cnt_root != 0) {
            printf("начало\n");
            printf("а вот и дерево: \n");
            print_tree(root, 0);
            printf("конец\n");
        } else if (c == 'p' && cnt_root == 0) {
            printf("Дерево не существует.\n");
        } else if (c == 'l' && cnt_root != 0) {
            printf("начало\n");
            if (check(root)) {
                printf("Все листья на одном уровне\n");
            } else {
                printf("Не все листья на одном уровне\n");
            }
            printf("конец\n");
        } else if (c == 'l' && cnt_root == 0) {
            printf("Дерево не существует.\n");
        } else if (c == 'b' && cnt_root != 0) {
            printf("начало\n");
            delete_tree(root);
            cnt_root--;
            printf("конец\n");
        } else if (c == 'b' && cnt_root == 0) {
            printf("Дерево не существует.\n");
        } else if (c == 'i' && cnt_root != 0) {
            printf("начало\n");
            inorder(root);
            printf("конец\n");
        } else if (c == 'i' && cnt_root == 0) {
            printf("Дерево не существует.\n");    
        } else if (c == 'e') {
            printf("все на сегодня\n");
            return 0;
        } 
    }
    return 0;
}
