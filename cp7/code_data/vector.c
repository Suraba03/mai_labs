#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"

void create_vector(vector *v)
{
    v->size = 0;
    v->data = (int *) malloc(sizeof(int) * v->size);
    v->count_elem = 0;
}

int size(vector *v)
{
    return v->size;
}

int is_empty(vector *v)
{
    return (v->count_elem == 0);
}

int count_elements(vector *v)
{
    return v->count_elem;
}

void resize(vector *v)
{
    v->size++;
    v->data = realloc(v->data, sizeof(int) * v->size);
}

void push_back(vector *v, int value)
{
    if (v->size == v->count_elem) {
        resize(v);
    }
    v->count_elem++;
    v->data[v->count_elem - 1] = value;
}

void print_vector(vector *v)
{
    if (is_empty(v)) {
        printf("вектор пуст\n");
    } else {
        printf("(");
        for (int i = 0; i < v->count_elem; i++) {
            if (i == v->count_elem - 1) {
                printf("%d", v->data[i]);
            } else {
                printf("%d ", v->data[i]);
            }
        }
        printf(")\n");
    }
}

void destroy(vector *v)
{
    v->count_elem = 0;
    v->size = 0;
    free(v->data);
}