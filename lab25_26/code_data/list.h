#ifndef list_h
#define list_h

#include <stdlib.h>
#include <stdio.h>

typedef struct list {
    int number_of_elements;
    int capacity;
    int *elements;
} list;

void create_list(list *l, int capacity);
int is_list_empty(list *l);
int size(list *l);
void resize(list *l);
void push_back(list *l, int act);
void print_list(list *l);
void delete_element_by_index(list *l);
void add_by_index(list *l);
int number_of_elements(list *l);
void add_to_K_elements(list *l, int act, int k);
void list_input(list *l);
list *lists_concat(list *l1, list *l2);

#endif