#include <stdio.h>
#include <stdlib.h>
#include <xmmintrin.h>

const int sz = 20;

bool PIII_LUDecomposition(float m[sz][sz], int n, double &det, int *ri, int *irow)
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
    {
        ri[i] = i;
        irow[i] = i * n;
    }
    // LU factorization.
    for (int p = 1; p <= n - 1; p++)
    {
        // Find pivot element.
        for (i = p + 1; i <= n; i++)
        {
            if (std::abs((pdata + irow[i - 1])[p - 1]) > std::abs((pdata + irow[p - 1])[p - 1]))
            {
                // Switch the index for the p-1 pivot row if necessary.
                int t = ri[p - 1];
                ri[p - 1] = ri[i - 1];
                ri[i - 1] = t;
                t = irow[p - 1];
                irow[p - 1] = irow[i - 1];
                irow[i - 1] = t;
                det = -det;
            }
        }
        pivel = *(pdata + irow[p - 1] + p - 1);
        if (pivel == 0)
        {
            // The matrix is singular.
            return false;
        }
        // Multiply the diagonal elements.
        det = det * pivel;
        // Form multiplier.
        __asm (
            "movss xmm1, DWORD PTR pivel;"
            "movss xmm2, xmm1;"
            "rcpss xmm1, xmm1;"
            "movss xmm3, xmm1;"
            "mulss xmm1, xmm1;"
            "mulss xmm2, xmm1;"
            "addss xmm3, xmm3;"
            "subss xmm3, xmm2;"
            "movss DWORD PTR frcp, xmm3;"
        ); // calculates 1/pivel using reciprocal division
        // 1. A[p+1:n][n] = A[p+1:n][n] / A[p][p]
        size = n - p;
        last8 = size & 7;
        end8 = size - last8;
        pe8 = n - last8;
        last = size & 3;
        end = size - last;
        pe = n - last;
        for (i = p + 1; i <= pe; i += 4)
        {
            (pdata + irow[i - 1])[p - 1] *= frcp;
            (pdata + irow[i])[p - 1] *= frcp;
            (pdata + irow[i + 1])[p - 1] *= frcp;
            (pdata + irow[i + 2])[p - 1] *= frcp;
        } // end 1 and form multiplier
        if (last)
        {
            for (i = p + 1 + end; i <= n; i++)
            {
                (pdata + irow[i - 1])[p - 1] *= frcp;
            }
        } // end 1 and form multiplier
        // 2. A[p+1:n][p+1:n] = A[p+1:n][p+1:n] - A[p+1:n][p] * A[p][p+1:n]
        ptr2 = pdata + irow[p - 1] - 1;
        for (j = p + 1; j < pe8; j += 8)
        { // loop for 8 columns
            tmpptr = ptr2 + j;
            __asm (
                "mov eax, DWORD PTR[tmpptr];"
                "movups xmm0, XMMWORD PTR[eax];"
                "movups xmm7, XMMWORD PTR[eax + 16];"
            ); //!!!
            for (i = p + 1; i < pe; i += 4)
                { // loop for 4 rows
                    ptr = pdata + irow[i - 1];
                    tmpptr = ptr + p - 1;
                    __asm (mov eax, DWORD PTR[tmpptr] __asm movss xmm1, DWORD PTR[eax] __asm shufps xmm1, xmm1, 0 __asm movaps xmm3, xmm1 __asm mulps xmm1, xmm0 __asm mulps xmm3, xmm7 tmpptr = ptr + j - 1);
                    __asm (mov eax, DWORD PTR[tmpptr] __asm movups xmm2, XMMWORD PTR[eax] __asm subps xmm2, xmm1 __asm movups xmm4, XMMWORD PTR[eax + 16] __asm subps xmm4, xmm3 __asm movups XMMWORD PTR[eax], xmm2 __asm movups XMMWORD PTR[eax + 16], xmm4 ptr = pdata + irow[i]);
                    
                    tmpptr = ptr + p - 1;
                    
                    __asm (mov eax, DWORD PTR[tmpptr] __asm movss xmm1, DWORD PTR[eax] __asm shufps xmm1, xmm1, 0 __asm movaps xmm3, xmm1 __asm mulps xmm1, xmm0 __asm mulps xmm3, xmm7 tmpptr = ptr + j - 1);
                    __asm (mov eax, DWORD PTR[tmpptr] __asm movups xmm2, XMMWORD PTR[eax] __asm subps xmm2, xmm1 __asm movups xmm4, XMMWORD PTR[eax + 16] __asm subps xmm4, xmm3 __asm movups XMMWORD PTR[eax], xmm2 __asm movups XMMWORD PTR[eax + 16], xmm4 ptr = pdata + irow[i + 1]);
                    
                    tmpptr = ptr + p - 1;
                    
                    __asm (mov eax, DWORD PTR[tmpptr] __asm movss xmm1, DWORD PTR[eax] __asm shufps xmm1, xmm1, 0 __asm movaps xmm3, xmm1 __asm mulps xmm1, xmm0 __asm mulps xmm3, xmm7 tmpptr = ptr + j - 1);
                    __asm (mov eax, DWORD PTR[tmpptr] __asm movups xmm2, XMMWORD PTR[eax] __asm subps xmm2, xmm1 __asm movups xmm4, XMMWORD PTR[eax + 16] __asm subps xmm4, xmm3 __asm movups XMMWORD PTR[eax], xmm2 __asm movups XMMWORD PTR[eax + 16], xmm4 ptr = pdata + irow[i + 2]);
                    
                    tmpptr = ptr + p - 1;
                    
                    __asm (mov eax, DWORD PTR[tmpptr] __asm movss xmm1, DWORD PTR[eax] __asm shufps xmm1, xmm1, 0 __asm movaps xmm3, xmm1 __asm mulps xmm1, xmm0 __asm mulps xmm3, xmm7 tmpptr = ptr + j - 1);
                    __asm (mov eax, DWORD PTR[tmpptr] __asm movups xmm2, XMMWORD PTR[eax] __asm subps xmm2, xmm1 __asm movups xmm4, XMMWORD PTR[eax + 16] __asm subps xmm4, xmm3 __asm movups XMMWORD PTR[eax], xmm2 __asm movups XMMWORD PTR[eax + 16], xmm4
                }
            if (last)
            {
                for (i = p + 1 + end; i <= n; i++)
                { // calculates last rows
                    ptr = pdata + irow[i - 1];
                    tmpptr = ptr + p - 1;
                    __asm mov eax, DWORD PTR[tmpptr] __asm movss xmm1, DWORD PTR[eax] __asm shufps xmm1, xmm1, 0 __asm movaps xmm3, xmm1 __asm mulps xmm1, xmm0 __asm mulps xmm3, xmm7 tmpptr = ptr + j - 1;
                    __asm mov eax, DWORD PTR[tmpptr] __asm movups xmm2, XMMWORD PTR[eax] __asm subps xmm2, xmm1 __asm movups xmm4, XMMWORD PTR[eax + 16] __asm subps xmm4, xmm3 __asm movups XMMWORD PTR[eax], xmm2 __asm movups XMMWORD PTR[eax + 16], xmm4
                } // end calculates last rows
            }     // end loop for rows
        }
        if (last8 > 3)
        {
            tmpptr = ptr2 + p + 1 + end8;
            __asm mov eax, DWORD PTR[tmpptr] __asm movups xmm0, XMMWORD PTR[eax] for (i = p + 1; i < pe; i += 4)
            { // loop for rows
                ptr = pdata + irow[i - 1];
                tmpptr = ptr + p - 1;
                __asm mov eax, DWORD PTR[tmpptr] __asm movss xmm1, DWORD PTR[eax] __asm shufps xmm1, xmm1, 0 __asm mulps xmm1, xmm0 tmpptr = ptr + pe8;
                __asm mov eax, DWORD PTR[tmpptr] __asm movups xmm2, XMMWORD PTR[eax] __asm subps xmm2, xmm1 __asm movups XMMWORD PTR[eax], xmm2 ptr = pdata + irow[i];
                tmpptr = ptr + p - 1;
                __asm mov eax, DWORD PTR[tmpptr] __asm movss xmm3, DWORD PTR[eax] __asm shufps xmm3, xmm3, 0 __asm mulps xmm3, xmm0 tmpptr = ptr + pe8;
                __asm mov eax, DWORD PTR[tmpptr] __asm movups xmm4, XMMWORD PTR[eax] __asm subps xmm4, xmm3 __asm movups XMMWORD PTR[eax], xmm4 ptr = pdata + irow[i + 1];
                tmpptr = ptr + p - 1;
                __asm mov eax, DWORD PTR[tmpptr] __asm movss xmm5, DWORD PTR[eax] __asm shufps xmm5, xmm5, 0 __asm mulps xmm5, xmm0 tmpptr = ptr + pe8;
                __asm mov eax, DWORD PTR[tmpptr] __asm movups xmm6, XMMWORD PTR[eax] __asm subps xmm6, xmm5 __asm movups XMMWORD PTR[eax], xmm6 ptr = pdata + irow[i + 2];
                tmpptr = ptr + p - 1;
                __asm mov eax, DWORD PTR[tmpptr] __asm movss xmm3, DWORD PTR[eax] __asm shufps xmm3, xmm3, 0 __asm mulps xmm3, xmm0 tmpptr = ptr + pe8;
                __asm mov eax, DWORD PTR[tmpptr] __asm movups xmm4, XMMWORD PTR[eax] __asm subps xmm4, xmm3 __asm movups XMMWORD PTR[eax], xmm4
            }
            if (last)
            {
                for (i = p + 1 + end; i <= n; i++)
                { // calculates last rows
                    ptr = pdata + irow[i - 1];
                    tmpptr = ptr + p - 1;
                    __asm mov eax, DWORD PTR[tmpptr] __asm movss xmm1, DWORD PTR[eax] __asm shufps xmm1, xmm1, 0 __asm mulps xmm1, xmm0 tmpptr = ptr + pe8;
                    __asm mov eax, DWORD PTR[tmpptr] __asm movups xmm2, XMMWORD PTR[eax] __asm subps xmm2, xmm1 __asm movups XMMWORD PTR[eax], xmm2
                } // end calculates last rows
            }     // end loop for rows
        }         // end loop for columns
        switch (last)
        { // calculates last columns
        case 0:
            break;
        case 3:
            ptr2 = pdata + irow[p - 1] + p + end;
            for (i = p + 1; i <= n; i++)
            {
                ptr = pdata + irow[i - 1] + p;
                tmp = *(ptr - 1);
                ptr += end;
                *ptr -= tmp * (*ptr2);
                *(ptr + 1) -= tmp * (*(ptr2 + 1));
                *(ptr + 2) -= tmp * (*(ptr2 + 2));
            }
            break;
        case 2:
            ptr2 = pdata + irow[p - 1] + p + end;
            for (i = p + 1; i <= n; i++)
            {
                ptr = pdata + irow[i - 1] + p;
                tmp = *(ptr - 1);
                ptr += end;
                *ptr -= tmp * (*ptr2);
                *(ptr + 1) -= tmp * (*(ptr2 + 1));
            }
            break;
        case 1:
            ptr2 = pdata + irow[p - 1] + p + end;
            for (i = p + 1; i <= n; i++)
            {
                ptr = pdata + irow[i - 1] + p;
                tmp = *(ptr - 1);
                ptr += end;
                *ptr -= tmp * (*ptr2);
            }
            break;
        } // end 2 and calculates last columns
    }
    det = det * (pdata + irow[n - 1])[n - 1];
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
    PIII_LUDecomposition(m, sz, det, v1, v2);
    printout(m);
}