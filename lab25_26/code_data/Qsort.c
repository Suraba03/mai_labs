#include "Qsort.h"
#include <stdio.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void qs(int* s_arr, int first, int last)
{
    int i = first, j = last, x = s_arr[(first + last) / 2];
  
    do {
        while (s_arr[i] < x) i++;
        while (s_arr[j] > x) j--;
  
        if (i <= j) {
            if (s_arr[i] > s_arr[j]) {
                swap(&s_arr[i], &s_arr[j]);
            }
            i++;
            j--;
        }
    } while (i <= j);
  
    if (i < last)
        qs(s_arr, i, last);
    if (first < j)
        qs(s_arr, first, j);
}
