#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char side;
    scanf("%c", &side);

    if (side == 'l') {
        printf("left\n");
    }
    if (side == 'r') {
        printf("right");
    }
    return 0;
}
