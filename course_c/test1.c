#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, p;
    scanf("%lf%lf%lf", &a, &b, &c);
    p = (a + b + c) / 2
    printf("%d\n", sqrt(p * (p - a) * (p - b) * (p - c)));
    return 0;
}


// rad =  grad * 3.141593 / 180;