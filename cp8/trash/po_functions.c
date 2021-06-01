#include <stdlib.h>
#include <stdio.h>
#include "ponomarev_header.h"

void list_create(list *l,int capacity)
{
    l->capacity = capacity;
    l->number_of_elements = 0;
    l->elements = malloc(sizeof(char) * l->capacity);
}

int is_list_empty(list *l)
{
    return ((l->number_of_elements == 0) ? 1 : 0);
}

int size(list *l)
{
    return l->capacity;
}

void resize(list *l)
{
    l->capacity++;
    l->elements = realloc(l->elements, sizeof(char) * l->capacity);
}

void push_back(list *l, char c)
{
    if (l->number_of_elements == l->capacity) {
        resize(l);
    }
    l->elements[l->number_of_elements] = c;
    l->number_of_elements++;
}

void list_print(list *l)
{
    printf("List printing: ");
    
    if (is_list_empty(l)) {
        printf("list is empty!\n");
    }
    for (int i = 0; i < l->number_of_elements; i++) {
        if(i == l->number_of_elements - 1) {
            printf("[%c]\n", l->elements[i]);
        } else {
            printf("[%c]->", l->elements[i]);
        }
    }
}

void delete_element_of_list(list *l)
{
    int number;

    printf("Please, enter number of element which will deleted: ");
    scanf("%d", &number);
     
    if (l->number_of_elements == 0) {
        printf("List already empty");
        return;
    }
    while (number >= l->number_of_elements) {
        printf("Error, please enter corrent number:");
        scanf("%d", &number);
    }
    l->elements[number] = 0;

    for(int i = 0; i < l->number_of_elements - 1 - number; i++) {
        l->elements[i + number] = l->elements[i + number + 1];
    }
    l->number_of_elements--;
}

void list_add_index(list *l)
{
    if(l->capacity < l->number_of_elements + 1) {
        resize(l);
    }
    int index;
    char a, tmp_1, tmp_2;

    printf("Please, enter char which you want to add and index:\n");
    scanf("%c %d", &a, &index);

    while(index > l->number_of_elements - 1) {
        printf("Error!Please enter correct index!");
        scanf("%d", &index);
    }
    tmp_2 = l->elements[index];
    tmp_1 = a;

    l->number_of_elements++;

    for(int i = 0; i < l->number_of_elements - index + 1; i++) {
        if (l->capacity < l->number_of_elements + 1) {
            resize(l);
        }
        l->elements[index + i] = tmp_1;
        tmp_1 = tmp_2;
        tmp_2 = l->elements[index + i + 1];
    }
}

int number_of_elements_on_lists(list *l)
{
    return l->number_of_elements;
}

void reverse(list *l)
{
    char tmp;

    for (int i = 0; i < number_of_elements_on_lists(l) / 2; i++) {
        tmp = l->elements[number_of_elements_on_lists(l) - i - 1];
        l->elements[number_of_elements_on_lists(l) - i - 1] = l->elements[i];
        l->elements[i] = tmp;
    }
}