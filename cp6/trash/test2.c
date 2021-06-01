#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SIZE 128


void print_unique(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                arr[i] = 0;
                break;
            }
        }
    }
}

int main(void)
{
    int array[9] = {1, 2, 3, 1, 2, 3, 4, 5, 4};
    print_unique(array, 9);
    for (int i = 0; i < 9; i++) {
        if (array[i] != 0) {
            printf("%d ", array[i]);
        }
    }    
    return 0;
}