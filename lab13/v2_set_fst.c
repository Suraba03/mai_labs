#include <stdio.h>

typedef enum {
    STATE0,
    STATE1
} State;

#define VOWELS 1u << (('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a')) 

int not_split_simb(int c)
{
    return !(c == ' ' && c == '\t' && c == ',' && c == '\n');
}

int is_split_simb(int c)
{
    return !(c == ' ' || c == '\t' || c == ',' || c == '\n');
}

unsigned int char_to_set(char c)
{
    if (c < 'a' || c > 'z') {
        return 0;
    } else {
        return 1u << (c - 'a');
    }
}

void is_include(int c, int letters_set)
{
    if (letters_set & ~(1u << (c - 'a')) == 0) {
        printf("Yes");
    }
}

int main(void)
{
    State st = STATE0;
    int c;
    unsigned int letters_set = 0, ls_without_a = 0, ls_without_e = 0, ls_without_i = 0, ls_without_o = 0, ls_without_u = 0;
    while ((c = getchar()) != EOF) {
            if ()
                while (not_split_simb(c = getchar())) {
                    letters_set = letters_set | char_to_set(c);
                }
                letters_set = letters_set & VOWELS; // если множество состоит из одного чара, то норм

                if (((letters_set & ~(1u << ('a' - 'a'))) == 0)) {
                    printf("Yes");
                } else if ((letters_set & ~(1u << ('e' - 'a'))) == 0) {
                    printf("Yes");
                } else if ((letters_set & ~(1u << ('i' - 'a'))) == 0) {
                    printf("Yes");
                } else if ((letters_set & ~(1u << ('o' - 'a'))) == 0) {
                    printf("Yes");
                } else if ((letters_set & ~(1u << ('u' - 'a'))) == 0) {
                    printf("Yes");
                } else {
                    
                }


        if (is_split_simb()) {
            while (is_split_simb(c = getchar())) {

            }
        }
    }
}