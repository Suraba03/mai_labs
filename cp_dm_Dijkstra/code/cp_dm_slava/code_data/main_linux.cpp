#include <cstdlib> // i686-w64-mingw32-g++ -static-libgcc -static-libstdc++ FILE.cpp
#include <iostream>
#include <fstream>
#include <climits>
#include <string.h>
#include <ctype.h>

#define STR 10

using namespace std;

char *itoa(int value, char* result, int base) // функция перевода int в char[]
{
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }
 
    char *ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;
 
    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );
 
    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

int main(int argc, char *argv[])
{
    //Loading matrix
    char name[STR];
    cout << "введите название файла: ";
    cin >> name;
    ifstream in(name);
    int razmer = 0, i, j;
    in >> razmer;
    razmer--;
  
    int matrix[razmer + 1][razmer + 1];      
    
    for (int i = 0; i <= razmer; i++) {
        for (int j = 0; j <= razmer; j++) {
            in >> matrix[i][j];
        }   
    }
    in.close();

    //////// Algorithm    
    for (int l = 1; l <= razmer + 1; l++) { 
        int distance[razmer + 1]; // массив минимальных расстояний
        int count, index, i, u, st = l - 1, m = st + 1; // st источник
        bool visited[razmer + 1]; // посещенные вершины, добавленные в особый путь
        int matr[razmer + 1];
        for (i = 0; i < razmer + 1; i++) {
            distance[i] = INT_MAX; // сохраняем бесконечность в расстояния
            visited[i] = false; // делаем вершины непосешенными
        }
        distance[st] = 0; // путь из v1 -> v1 = 0

        for (count = 0; count < razmer; count++) {
            int min = INT_MAX;
            for (i = 0; i < razmer + 1; i++) { // ищем минимальные пути в каждую вершину
                if (!visited[i] && distance[i] <= min) {
                    min = distance[i];
                    index = i;
                }
            }
            u = index; // индекс вершины, добавленной в особый путь
            visited[u] = true;

            for (i = 0; i < razmer + 1; i++) { // ищем меньшую длину пути, если есть (через другие вершины)
                if (!visited[i] && matrix[u][i] && (distance[u] != INT_MAX) && (distance[u] + matrix[u][i] < distance[i])) {
                    distance[i] = distance[u] + matrix[u][i];
                }
            }
        }
        for (int k = 0; k < razmer + 1; k++) {
            if (distance[k] != INT_MAX) {
                matr[k] = distance[k]; // записываем в массив кратчайшие пути
            } else {
                matr[k] = 0; // если пути нет
            }
        }
        for (int k = 0; k < razmer + 1; k++) {
            matrix[l - 1][k] = matr[k]; // конкатенируем матрицы, получаем матрицу смежности
        }
    }

    //Saving new matrix
    fstream out;
    char name_out[STR];
    cout << "введите выходной файл: ";
    cin >> name_out;

    out.open(name_out);
    out.clear();
    
    char buffer [33];
    itoa(razmer+1,buffer,10);
    out << buffer << "\n";
    
    for(int i=0; i<=razmer;i++) {
        for(int j=0;j<=razmer;j++) {
            out << matrix[i][j];
            if(j != razmer) out << " ";
        }
            out << "\n";
    }
    out.close();
}
