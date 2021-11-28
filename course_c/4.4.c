#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int s, e;
    scanf("%d%d", &s, &e);
    printf("%d\n", s + rand() % (e - s + 1));
    return 0;
}