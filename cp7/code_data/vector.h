#ifndef VECTOR_H
#define VECTOR_H

typedef struct _vector vector;

struct _vector 
{
    int size;
    int *data;
    int count_elem;
};

void create_vector(vector *v);
int size(vector *v);
void resize(vector *v);
void push_back(vector *v, int value);
int count_elements(vector *v);
int is_empty(vector *v);
void print_vector(vector *v);
void destroy(vector *v);

#endif