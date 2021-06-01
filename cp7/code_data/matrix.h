#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

#define SIZE 30

int cnt_elem(char name[SIZE]);
int cnt_lines(char name[SIZE]);
vector *matrix_input(vector *v);
void task_print(vector *v);
void natural_print(vector *v);
int search(vector *v, int i, int j);
void multiply(vector *v1, vector *v2);

#endif