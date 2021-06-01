#ifndef list_h
#define list_h

#include <stdlib.h>
#include <stdio.h>

typedef enum {
    STEP_FORW = 0, // 0
    STEP_BACK, // 1
    STEP_LEFT, // 2
    STEP_RIGHT, // 3
    CH_DIR_180, // 4
} Actions;

typedef struct list {
    int number_of_elements;
    int capacity;
    Actions *elements;
} list;

void create_list(list *l,int capacity);
void printAction(Actions action);
int is_list_empty(list *l);
int size(list *l);
void resize(list *l);
void push_back(list *l, Actions act);
void print_list(list *l);
void delete_element_by_index(list *l);
void add_by_index(list *l);
int number_of_elements(list *l);
void add_to_K_elements(list *l, Actions act, int k);

#endif