#ifndef list_h
#define list_h

#include <stdlib.h>
#include <stdio.h>

typedef struct list{
    int number_of_elements;
    int capacity;
    char *elements;
} list;

void list_create(list *l,int capacity);
int is_list_empty(list *l);
int size(list *l);
void resize(list *l);
void push_back(list *l, char c);
void list_print(list *l);
void delete_element_of_list(list *l);
void list_add_index(list *l);
int number_of_elements_on_lists(list *l);
void reverse(list *l);

#endif