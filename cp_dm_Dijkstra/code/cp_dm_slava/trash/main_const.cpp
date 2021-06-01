#include <cstdlib>
#include <iostream>
#include <fstream>
#include <climits>
#include <string.h>
#include <ctype.h>

#define V 6

using namespace std;

char *itoa(int value, char* result, int base)
{
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }
 
    char* ptr = result, *ptr1 = result, tmp_char;
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
    //ifstream in(name);
    ifstream in("mat.txt");
    int razmer=0,i,j;
    in >> razmer;
    razmer--;
  
    int matrix[V][V];      
    
    for (int i = 0; i <= V - 1; i++) {
        for (int j = 0; j <= V - 1; j++) {
            in >> matrix[i][j];
        }   
    }
    in.close();

    //////// Algorithm    
    for (int l = 1; l <= 6; l++) { 
        int distance[V], count, index, i, u, st = l - 1, m = st + 1; //index, u, m = i + 1, st = m - 1;
        bool visited[V];
        int matr[V];
        for (i = 0; i < V; i++) {
            distance[i] = INT_MAX;
            visited[i] = false;
        }
        distance[st] = 0;

        for (count = 0; count < V - 1; count++) {
            int min = INT_MAX;
            for (i = 0; i < V; i++) {
                if (!visited[i] && distance[i] <= min) {
                    min = distance[i];
                    index = i;
                }
            }
            u = index;
            visited[u] = true;

            for (i = 0; i < V; i++) {
                if (!visited[i] && matrix[u][i] && (distance[u] != INT_MAX) && (distance[u] + matrix[u][i] < distance[i])) {
                    distance[i] = distance[u] + matrix[u][i];
                }
            }
        }
        //cout << "Стоимость пути из начальной вершины до остальных:\t\n";
        for (int k = 0; k < V; k++) {
            if (distance[k] != INT_MAX) {
                matr[k] = distance[k];
                //cout << m << " > " << i + 1 << " = " << distance[i] << endl;
            } else {
                matr[k] = 0;
                //cout << m << " > " << i + 1 << " = " << 0 << endl;
            }
        }
        for (int k = 0; k < V; k++) {
            matrix[l - 1][k] = matr[k];
        }
        //cout << endl;
    } 
    /*cout << "матрица" << endl; // это маё)))
    for (int x = 0; x < V; x++) {
        for (int y = 0; y < V; y++) {
            cout << matrix[x][y] << " ";
        }
        cout << endl;
    }*/
    
    /*for (i = 0; i <= V - 1; i++) {
        for (j = 0; j <= V - 1; j++) {
            if (matrix[i][j] != 0) matrix[i][j] = 0;
            else if (i != j) matrix[i][j] = 1;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }*/
    //Saving new matrix
    fstream out;
    out.open("mat.txt");
    out.clear();
    char buffer [33];
    itoa(razmer+1,buffer,10);
    out << buffer << "\n";
    for(int i=0; i<=razmer;i++) {
    for(int j=0;j<=razmer;j++) {
    out << matrix[i][j];
    if(j!=razmer) out << " ";
    }
    if(i!=razmer) out << "\n";
    }
    out.close();
}