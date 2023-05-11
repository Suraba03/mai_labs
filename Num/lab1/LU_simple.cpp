#include <stdio.h>
#include <stdlib.h>
#include <xmmintrin.h>
const int sz = 20;

bool PII_LUDecomposition(float m[sz][sz], int n, double &det, int *ri, int *irow)
{
    // Factors "m" matrix into A=LU where L is lower triangular and U is upper
    // triangular. The matrix is overwritten by LU with the diagonal elements
    // of L (which are unity) not stored. This must be a square n x n matrix.
    // ri[n] and irow[n] are scratch vectors used by LUBackSubstitution.
    // d is returned +-1 indicating that the
    // number of row interchanges was even or odd respectively.
    //
    int i, j, k;
    int size, last, end, pe;
    int last8, end8, pe8;
    float frcp, tmp, pivel;
    register float *tmpptr;
    float *ptr2, *ptr;
    float *pdata = m[0];
    det = 1.0;
    // Initialize the pointer vector.
    for (i = 0; i < n; i++)
        ri[i] = i;
    // LU factorization.
    for (int p = 1; p <= n - 1; p++)
    {
        // Find pivot element.
        for (i = p + 1; i <= n; i++)
        {
            if (std::abs(m[ri[i - 1]][p - 1]) > std::abs(m[ri[p - 1]][p - 1]))
            {
                // Switch the index for the p-1 pivot row if necessary.
                int t = ri[p - 1];
                ri[p - 1] = ri[i - 1];
                ri[i - 1] = t;
                det = -det;
            }
        }
        if (m[ri[p - 1]][p - 1] == 0)
        {
            // The matrix is singular.
            return false;
        }
        // Multiply the diagonal elements.
        det = det * m[ri[p - 1]][p - 1];
        // Form multiplier.
        for (i = p + 1; i <= n; i++)
        {
            m[ri[i - 1]][p - 1] /= m[ri[p - 1]][p - 1];
            // Eliminate [p-1].
            for (int j = p + 1; j <= n; j++)
                m[ri[i - 1]][j - 1] -= m[ri[i - 1]][p - 1] * m[ri[p - 1]][j - 1];
        }
    }
    det = det * m[ri[n - 1]][n - 1];
    return det != 0.0;
}
void printout(float m[sz][sz])
{
    int i, j;
    printf("{");
    for (i = 0; i < sz; i++)
    {
        printf("{");
        for (j = 0; j < sz; j++)
        {
            printf("%f%c", m[i][j], j == sz - 1 ? ' ' : ',');
        }
        printf("}%c\n", i == sz - 1 ? ' ' : ',');
    }
    printf("}\n\n");
}
int main(int argc, char *argv[])
{
    float m[sz][sz];
    int v1[sz];
    int v2[sz];
    int i, j;
    for (i = 0; i < sz; i++)
    {
        for (j = 0; j < sz; j++)
        {
            m[i][j] = (float)rand() / RAND_MAX;
        }
    }
    printout(m);
    double det;
    PII_LUDecomposition(m, sz, det, v1, v2);
    printout(m);
}