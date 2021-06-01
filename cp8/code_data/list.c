#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void create_list(list *l, int capacity) // нужно
{
    l->capacity = capacity;
    l->number_of_elements = 0;
    l->elements = malloc(sizeof(Actions) * l->capacity);
}

void printAction(Actions action)
{
    if (action == STEP_FORW)
        printf("[step forward]");
    else if (action == STEP_BACK)
        printf("[step back]");
    else if (action == STEP_LEFT)
        printf("[step left]");
    else if (action == STEP_RIGHT)
        printf("[step right]");
    else if (action == CH_DIR_180)
        printf("[change direction by 180 degrees]");
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
    l->elements = realloc(l->elements, sizeof(Actions) * l->capacity);
}

void push_back(list *l, Actions act) // нужно
{
    if (l->number_of_elements == l->capacity) {
        resize(l);
    }
    l->elements[l->number_of_elements] = act;
    l->number_of_elements++;
}

void print_list(list *l) // нужно
{
    printf("Печать списка:\n");
    
    if (is_list_empty(l)) {
        printf("Список пуст((\n");
    }
    for (int i = 0; i < l->number_of_elements; i++) {
        if (i == l->number_of_elements - 1) {
            printAction(l->elements[i]); printf("\n");
        } else {
            printAction(l->elements[i]); printf("->");
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
    Actions act, tmp_1, tmp_2;

    printf("Введите какое-нибудь действие: STEP_FORW, STEP_BACK, STEP_LEFT, STEP_RIGHT или CH_DIR_180 котoрое вы хотите добавить: ");
    scanf("%d", &act);
    printf("введите индекс, куда хотите добавить: ");
    scanf("%d", &index);

    if (index == l->number_of_elements) {
        push_back(l, act);
        flag = 1;
    } else {
        while ((index > l->number_of_elements - 1) || (index < 0)) {
            printf("Слишком большой индекс, введите поменбше. максимально возможный индекс = %d\n", l->number_of_elements);
            scanf("%d", &index);
            if (index == l->number_of_elements && flag == 0) {
                push_back(l, act);
                break;
            }
        }
        tmp_2 = l->elements[index];
        tmp_1 = act;

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

void add_to_K_elements(list *l, Actions act, int k) // нужно
{
    if (l->number_of_elements < k) {
        while (l->number_of_elements < k) {
            push_back(l, act);  
        }
    }
}

