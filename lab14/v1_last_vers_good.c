#include <stdio.h>
#define maxn 100

int main(void)
{
    int n, t_cnt, m_sz;
    long long int arr[maxn][maxn];
    scanf("%d%d", &t_cnt, &m_sz);
    for (int l = 0; l < t_cnt; l++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lld", &arr[i][j]);
            }
        }
        int j2 = 1, i2 = 0, j2_const = 1, j1 = n - 1, i1 = n - 1, j1_const = n - 1;
        for (int k = 0; k < 2 * n - 1; k++) {
            if (k % 2 == 0) {
                while (j1 >= 0) {
                    printf("%lld ", arr[i1][j1]);
                    i1--;
                    j1--;
                }
                i1 = n - 1;
                j1_const--;
                j1 = j1_const;
            } else {
                while (j2 < n) {
                    printf("%lld ", arr[i2][j2]);
                    i2++;
                    j2++;
                }
                i2 = 0;
                j2_const++;
                j2 = j2_const;
            }
        }
        printf("\n");
    }
    return 0;
}