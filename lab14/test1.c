#include <stdio.h>
#define maxn 100

int main()
{
    int n, t_cnt, m_sz;
    int j1, i1, j1_const;
    int j2 = 1, i2 = 0, j2_const = 1;
    long long int arr[maxn][maxn];
    scanf("%d%d", &t_cnt, &m_sz);
    for (int l = 0; l < t_cnt; l++) {
        scanf("%d", &n);
        j1 = n - 1;
        i1 = n - 1;
        j1_const = n - 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lld", &arr[i][j]);
            }
        }
        for (int k = 0; k < 2 * n - 1; k++) {
            if (k % 2 == 0) {
                while (j1 >= 0) { // () n + n - 1 = 2n - 1
                    printf("%lld ", arr[i1][j1]);
                    i1--;
                    j1--;
                }
                i1 = n - 1;
                j1_const--; // j1_const = j1 = n - 1;
                j1 = j1_const;
            } else {
                while (j2 < n) { // []
                    printf("%lld ", arr[i2][j2]);
                    i2++;
                    j2++;
                }
                i2 = 0;
                j2_const++; // j2_const = 1
                j2 = j2_const;
            }
        }
        printf("\n");
    }
    return 0;
}

/*
 4(00)   5(01)   11(02)  15(03)
10(10)   3(11)    6(12)  12(13)
14(20)   9(21)    2(22)   7(23)
16(30)  13(31)    8(32)   1(33)

... (33 22 11 00) [01 12 23] ... ... (32 21 10)   [02 13] ... ... (31 20)   [03] ... ... (30) .......

///////////////////////////////////////////////

for (int k = 0; k < 2 * n - 1; k++) {
    if (k % 2 == 0) {
        while (j1 >= 0) { // () n + n - 1 = 2n - 1
            printf("%lld", arr[i1][j1]);
            i1--;
            j1--;
        }
        i1 = n - 1;
        j1_const--; // j1_const = j1 = n - 1;
        j1 = j1_const;
    } else {
        while (j2 < n) { // []
            printf("%lld", arr[i2][j2]);
            i2++;
            j2++;
        }
        i2 = 0;
        j2_const++; // j2_const = 1
        j2 = j2_const;
    }
}
*/