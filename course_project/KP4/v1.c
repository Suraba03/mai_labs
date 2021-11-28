#include <math.h>
#include <stdio.h>

double epsilon()
{
    double eps = 1.0;
    while ((1.0 + eps / 2.0) > 1.0) {
        eps = eps / 2.0;
    }
    return eps;
}

double func1(double x) {
	return x - 2 + sin(1 / x);
}

double der_f1(double x) {
	return 1 - cos(1 / x) / (x * x);
}

double func1_used(double x) {
	return 2 - sin(1 / x);
}

double func2(double x) {
	return exp(x) + log(x) - 10 * x;
}

double der_f2(double x) {
	return exp(x) + 1 / x - 10;
}

double func2_used(double x) {
	return exp(x) / 10 + log(x) / 10;
}

double Newton(double f(double), double d_f(double), double a, double b, double eps)
{
    double x = b;
    while (fabs(f(x) / d_f(x)) >= eps) {
		x -= f(x) / d_f(x);
	}
	return x;
}

double Dichotomy(double f(double), double a, double b, double eps)
{
	double c = 0;
	while (f(c) != 0 && fabs(b - a) > eps) {
		c = (a + b) / 2;
		(f(c) * f(a) > 0) ? (a = c) : (b = c);
	}
	return c;   
}

double Iteration(double f(double), double a, double b, double eps)
{
    double curr = (a + b) / 2, prev = curr + 1;
    while(fabs(curr - prev) > eps) {
        prev = curr;
        curr = f(prev);
    }
    return curr;   
}

int main(void)
{
    double eps = epsilon();
	printf("function: x - 2 + sin(1 / x)\n");
	printf("Newton Method value: %13f\n", Newton(func1, der_f1, 1.2, 2, eps));
    printf("Dichotomy Method value: %10f\n", Dichotomy(func1, 1.2, 2, eps));
    printf("Iteration Method value: %10f\n\n", Iteration(func1_used, 1.2, 2, eps));
	printf("function: exp(x) + log(x) - 10 * x\n");
	printf("Newton Method value: %13f\n", Newton(func2, der_f2, 3, 4, eps));
    printf("Dichotomy Method value: %10f\n", Dichotomy(func2, 3, 4, eps));
}
