#include <time.h>
#include <stdlib.h>
#include "table.h"
#include <stdio.h>

int binSearch(const row *mass, const int size, const long int key)
{
    int start = 0, end = size - 1, mid;

	if (size <= 0)
		return -1;

	while (start < end) {
		mid = start + (end - start) / 2;
		if (mass[mid]._key == key) {
			return mid;
		} else if (mass[mid]._key < key) {
			start = mid + 1;
		} else {
			end = mid;
		}
	}
	if (mass[end]._key == key) {
		return end;
	}
	return -1;
}

// Функция Шейкер-сортировки
void shakerSort(row *mass, const int count)
{
    int left = 0, right = count - 1;
    int flag = 1;

    while ((left < right) && flag > 0) {
        flag = 0;

        for (int i = left; i<right; i++) {
            if (mass[i]._key > mass[i + 1]._key) {
                swapRows(&mass[i], &mass[i+1]);
                flag = 1;
            }
        }
        right--;

        for (int i = right; i>left; i--) {
            if (mass[i - 1]._key > mass[i]._key) {
                swapRows(&mass[i], &mass[i-1]);
                flag = 1;
            }
        }
        left++;
    }
}

int randomAB(const int a, const int b)
{
    return a + rand() % (b - a + 1);
}

void shuffle(row *mass, const int size)
{
	int i, j, k;

	srand((unsigned int)time(0));

	for (k = 0; k < size; k++) {
		i = randomAB(0, size - 1);
		j = randomAB(0, size - 1);
		swapRows(&mass[i], &mass[j]);
	}
} 

void reverse(row *mass, const int size)
{
  int i, j;
	for (i = 0, j = size - 1; i < j; i++, j--) {
		swapRows(&mass[i], &mass[j]);
	}
}

int isSorted(const row *mass, const int size)
{
	for (int i = 0; i < size - 1; i++) {
		if (mass[i]._key > mass[i + 1]._key) {
			return 0;
		}
	}
	return 1;
}