#include <stdio.h>
#include <string.h>

#define STR_LEN 100000

// функция: ищем максимальную цифру в строке, ее и возвращаем
int minPartitions(char *n)
{
    int m = 0;
    for (int i = 0; i < strlen(n); i++) {
        if (n[i] - 48 > m) {
            m = n[i] - 48;
        }
    }
    return m;
}

int main(void)
{
    char str[STR_LEN];
    printf("введите строку\n");
    scanf("%s", str);
    printf("минимальное кол-во слагаемых = %d\n", minPartitions(str));
    return 0;
}
