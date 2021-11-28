#include <stdio.h>
#include <math.h>

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d\n", (x + 1) % 2 - x % 2); // чет - 1 (+0), нечет - 0 (-1)
    return 0;
}