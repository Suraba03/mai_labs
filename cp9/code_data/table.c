#include "table.h"
#include <stdio.h>

void printTable(row *arr, const int size)
{
	printf("|   Ключ  |                   строка                         |\n");
	for (int i = 0; i < size; i++) {
		printf("|%9ld|%50s|\n", arr[i]._key, arr[i]._str);
	}
}

void getRow(FILE *stream, char *str, const int size)
{
    int cnt = 0;
    char ch;
	while ((ch = getc(stream)) != '\n' && cnt < size - 1) {
		str[cnt++] = ch;
	}
	str[cnt] = '\0';
}

void swapRows(row *r1, row *r2)
{
    row tmp;
	tmp = *r1;
	*r1 = *r2;
	*r2 = tmp;
}