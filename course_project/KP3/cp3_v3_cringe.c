#include <math.h>
#include <stdio.h>

double fact(double n)
{
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int main(void)
{
    int n;
    double eps = 1.0, x = 0, taylor_series, func;
    scanf("%d", &n);
    double interval = 1.0 / n;

    while ((1.0 + eps / 2.0) > 1.0) {
        eps = eps / 2.0;
    }
    printf ("      *----------------------------------*\n------| Machine epsilon = %.8e |------\n      *----------------------------------*\n*----------------------------------------------*\n", eps);

    for (int i = 0; i <= n; i++) {
        taylor_series = 0;
        func = sin(x);

        int counter = 0;

        while (fabs(taylor_series - func) >= eps * 10) {
            taylor_series += pow(-1, counter) * (pow(x, 2 * counter + 1) / fact(2 * counter + 1));
            counter++;
        }
        printf ("| %.2lf | %.13lf | %.13lf | %d |\n", x, taylor_series, func, counter);
        printf("*----------------------------------------------*\n");
        x += interval;
    }
    return 0;
}
