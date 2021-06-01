#ifndef FUNC_H
#define FUNC_H

#include "table.h"

int binSearch(const row *mass, const int size, const long int key); // Бинарный поиск в таблице по ключу
void shakerSort(row *mass, const int count); // Сортировка шейкером
void shuffle(row *mass, const int size); // Перемешивание данных в таблице
void reverse(row *mass, const int size); // Реверс данных в таблице
int randomAB(const int a, const int b); 
int isSorted(const row *mass, const int size); // Проверка на отсортированность таблицы

#endif