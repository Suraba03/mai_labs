#include <cstdlib>
#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int main(int argc, char *argv[])
{
    //Loading matrix
    /*ifstream in(argv[1]);*/

    int razmer = 0, i, j;
    //in >> razmer;
    cin >> razmer; 
    
    razmer--;   
    int matrix[razmer + 1][razmer + 1];      
    
    for (int i = 0; i <= razmer; i++) {
        for (int j = 0; j <= razmer; j++) {
            /*in*/cin >> matrix[i][j];
        }   
    }
    //in.close();

    //////// Algorithm    
    cout << endl;
    for (int l = 1; l <= 6; l++) { 
        int distance[razmer + 1], count, index, i, u, st = l - 1, m = st + 1; //index, u, m = i + 1, st = m - 1;
        bool visited[razmer + 1];
        int matr[razmer + 1];
        for (i = 0; i < razmer + 1; i++) {
            distance[i] = INT_MAX;
            visited[i] = false;
        }
        distance[st] = 0;

        for (count = 0; count < razmer; count++) {
            int min = INT_MAX;
            for (i = 0; i < razmer + 1; i++) {
                if (!visited[i] && distance[i] <= min) {
                    min = distance[i];
                    index = i;
                }
            }
            u = index;
            visited[u] = true;

            for (i = 0; i < razmer + 1; i++) {
                if (!visited[i] && matrix[u][i] && (distance[u] != INT_MAX) && (distance[u] + matrix[u][i] < distance[i])) {
                    distance[i] = distance[u] + matrix[u][i];
                }
            }
        }
        //cout << "Стоимость пути из начальной вершины до остальных:\t\n";
        for (int k = 0; k < razmer + 1; k++) {
            if (distance[k] != INT_MAX) {
                matr[k] = distance[k];
                //cout << m << " > " << i + 1 << " = " << distance[i] << endl;
            } else {
                matr[k] = 0;
                //cout << m << " > " << i + 1 << " = " << 0 << endl;
            }
        }
        for (int k = 0; k < razmer + 1; k++) {
            cout << matr[k] << " ";
        }
        cout << endl;
    }
    
    /*for (i = 0; i <= razmer; i++) {
        for (j = 0; j <= razmer; j++) {
            if (matrix[i][j] != 0) matrix[i][j] = 0;
            else if (i != j) matrix[i][j] = 1;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }*/
    //Saving new matrix
    
    /*fstream out;
    out.open(argv[1]);
    out.clear();
    char buffer [33];
    itoa(razmer+1,buffer,10); 
    out << buffer << "\n";    
    for(i=0; i<=razmer;i++) {
        for(j=0;j<=razmer;j++) { 
            out << matrix[i][j];
            if(j!=razmer) out << " ";
        }
        if(i!=razmer) out << "\n";
    }
    out.close();*/
}
