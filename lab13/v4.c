#include <stdio.h>
#include <stdint.h>

int is_split_simb(int c)
{
    return c == ' ' || c == '\t' || c == ',' || c == '\n';
}

uint32_t char_to_set(char c)
{
    if (c < 'a' || c > 'z') {
        return 0;
    } else {
        return 1u << (c - 'a');
    }
}

int main(void)
{
    uint32_t VOWELS = (1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a'));
    int c, check_out = 0;
    uint32_t letters_set = 0;
    while ((c = getchar()) != EOF) {
        if (check_out == 0) {
            if (!(is_split_simb(c))) {
                letters_set = letters_set | char_to_set(c);
            }
            if () {
                letters_set = letters_set & VOWELS;
                if (letters_set == 0) {
                    continue;
                } else if (((letters_set & ~(1u << ('a' - 'a'))) == 0)) {
                    check_out = 1;
                } else if (((letters_set & ~(1u << ('e' - 'a'))) == 0)) {
                    check_out = 1;
                } else if (((letters_set & ~(1u << ('i' - 'a'))) == 0)) {
                    check_out = 1;
                } else if (((letters_set & ~(1u << ('o' - 'a'))) == 0)) {
                    check_out = 1;
                } else if (((letters_set & ~(1u << ('u' - 'a'))) == 0)) {
                    check_out = 1;
                }
            }
        }
    }
    if (check_out == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}