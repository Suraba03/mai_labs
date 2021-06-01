#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void create_list(list *l, int capacity) // нужно
{
    l->capacity = capacity;
    l->number_of_elements = 0;
    l->elements = malloc(sizeof(int) * l->capacity);
}

int is_list_empty(list *l)
{
    if (l->number_of_elements == 0) {
        return 1;
    } else {
        return 0;
    }
}

int size(list *l)
{
    return l->capacity;
}

void resize(list *l)
{
    l->capacity++;
    l->elements = realloc(l->elements, sizeof(int) * l->capacity);
}

void push_back(list *l, int numb) // нужно
{
    if (l->number_of_elements == l->capacity) {
        resize(l);
    }
    l->elements[l->number_of_elements] = numb;
    l->number_of_elements++;
}

void print_list(list *l) // нужно
{
    printf("\n");
    
    if (is_list_empty(l)) {
        printf("Список пуст((\n");
    }
    for (int i = 0; i < l->number_of_elements; i++) {
        if (i == l->number_of_elements - 1) {
            printf("[%d]\n", l->elements[i]);
        } else {
            printf("[%d]->", l->elements[i]);
        }
    }
}

void delete_element_by_index(list *l) // нужно
{
    int ind;

    printf("Введите индекс элемента, который хотите удалить: ");
    scanf("%d", &ind);
     
    if (l->number_of_elements == 0) {
        printf("Нечего удалять, список пуст((\n");
        return;
    }
    while ((ind >= l->number_of_elements) || (ind < 0)) {
        printf("Слишком большой или маленький индекс, введите поменбше/поболбше...\n");
        scanf("%d", &ind);
    }
    l->elements[ind] = 0;

    for (int i = 0; i < l->number_of_elements - 1 - ind; i++) {
        l->elements[i + ind] = l->elements[i + ind + 1];
    }
    l->number_of_elements--;
    printf("удаляем элемент с индексом %d...\n", ind);
}

void add_by_index(list *l) // нужно
{
    if ((l->capacity < l->number_of_elements + 1) && (l->number_of_elements != 0)) {
        resize(l);
    } 
    int index, flag = 0;
    int numb, tmp_1, tmp_2;

    printf("Введите какое-нибудь число, котoрое вы хотите добавить: ");
    scanf("%d", &numb);
    printf("введите индекс, куда хотите добавить: ");
    scanf("%d", &index);

    if (index == l->number_of_elements) {
        push_back(l, numb);
        flag = 1;
    } else {
        while ((index > l->number_of_elements - 1) || (index < 0)) {
            printf("Слишком большой индекс, введите поменбше. максимально возможный индекс = %d\n", l->number_of_elements);
            scanf("%d", &index);
            if (index == l->number_of_elements && flag != 1) {
                push_back(l, numb);
                flag == 1;
                return;
            }
        }
        tmp_2 = l->elements[index];
        tmp_1 = numb;

        l->number_of_elements++;

        for (int i = 0; i < l->number_of_elements - index + 1; i++) {
            if (l->capacity < l->number_of_elements + 1) {
                resize(l);
            }
            l->elements[index + i] = tmp_1;
            tmp_1 = tmp_2;
            tmp_2 = l->elements[index + i + 1];
        }
    }
}

int number_of_elements(list *l) // нужно
{
    return l->number_of_elements;
}

void add_to_K_elements(list *l, int numb, int k) // нужно
{
    if (l->number_of_elements < k) {
        while (l->number_of_elements < k) {
            push_back(l, numb);  
        }
    }
}

list *lists_concat(list *l1, list *l2)
{
    for (int i = 0; i < l2->number_of_elements; i++) {
        push_back(l1, l2->elements[i]);
    }
    return l1;
}

void list_input(list *l) 
{
    int n, a;
    scanf("%d", &n);
    printf("введите элементы списка: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        push_back(l, a);
    }
}