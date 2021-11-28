#include <stdio.h>

int is_space(char c)
{
    return (c == ' ' || c == ',' || c == '\n' || c == '\t' || c == '\0');
}

int vowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main(void)
{
    int vowel_1 = 0;
    char c;
    while ((c = getchar()) != EOF) {
        if (vowel(c)) {
            vowel_1 = c;
        }
        else if (is_space(c)) {
            if ()
        }
    return 0;
}