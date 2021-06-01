#ifndef structure_h
#define structure_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SIZE 128

typedef struct performance {
    int group_number;
    char surname[SIZE];
    char initials[SIZE];
    char gender[SIZE];
    int calculus_score;
    int linal_score;
    int dm_score;
    int cs_score;
    int course_project_score;
} performance;

void create_dataset();
void add_to_dataset();
void print_dataset();
void print_unique(int arr[], int n);
float max_diff(float arr[], int cnt);
int parametr();
void delete_dataset();

#endif