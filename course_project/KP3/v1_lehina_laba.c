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

void taylor(int counter, double x, double taylor_series) {
    taylor_series += (pow(-1, counter) * (pow(x, 2 * counter + 1) / fact(2 * counter + 1)));
    counter++;
}

int main(void)
{
    double eps = 1.0, x = 0, taylor_series, func;

    while ((1.0 + eps / 2.0) > 1.0) {
        eps = eps / 2.0;
    }
    printf ("Machine epsilon = %.8e\n\n", eps);

    for (int i = 0; i < 20; i++) {
        taylor_series = 0;
        func = sin(x);

        int counter = 0;

        while (fabs(taylor_series - func) >= eps) {
            taylor(counter, x, taylor_series);
        }
        printf ("| %.2f | %.16f | %.16f | %d |\n", x, taylor_series, func, counter);
        x += 0.05;
    }
    return 0;
}
