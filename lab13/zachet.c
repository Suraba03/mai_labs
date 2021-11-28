#include <stdio.h>

int main()
{
    int n;
    scanf("%d%d", &n);
    int arr[n][n];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            
        }
    }
    return 0;
}

/*

Исходная матрица:
1(00) 2(01) 3(02) 4(03)
5(10) 6(11) 7(12) 8(13)

Транспонированная матрица:
1(00) 5(01)
2(10) 6(11)
3(20) 7(21)
4(30) 8(31)

*/


















/* #include <stdio.h>

int main()
{
    int n, min = 32767, max = 0;
    scanf("%d", &n);
    int arr[n];
    for (int j = 0; j < n; j++) {
        scanf("%d", &arr[j]);
        if (arr[j] < min) {
            min = arr[j];
        }
        if (arr[j] > max) {
            max = arr[j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == min) {
            printf("%d ", max);
        } else if (arr[i] == max) {
            printf("%d ", min);    
        } else {
            printf("%d ", arr[i]);
        }
    }
    return 0;
} */
/*
for (int i = 0; i < n; i++) {
        if (arr[i] < arr[n - 1] && arr[i] > arr[0]) {
            printf("%d ", arr[i]);
            is_exist_output = 1;
        }
    }
    if (!is_exist_output) {
        printf("0");
    }
*/


/*
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    for (int k = 0; k < n; k++) {
        if (arr[k] % 2 == 1) {
            printf("%d ", arr[k]);
        }
    }
*/

/* 10 93 3 22 75 12
    0  1 2  3  4  5
*/