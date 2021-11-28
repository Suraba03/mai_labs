#include <stdio.h>

typedef enum {
    State0, State1, State2
} State;

int is_split_simb(int c)
{
    return c == ' ' || c == '\t' || c == ',' || c == '\n' || c == '+' || c == '-';
}

int is_hex_symb(int c)
{
    return (c <= 'F' && c >= 'A') || (c <= 'f' && c >= 'a') || (c <= '9' && c >= '0');
}

int hex_simb_to_int(char x)
{
    int n_10 = 0;
    if (x <= 'F' && x >= 'A') {
        n_10 = x - 55;
        return n_10;
    } else if (x <= 'f' && x >= 'a') {
        n_10 = x - 87;
        return n_10;
    } else {
        n_10 = x - 48;
        return n_10;
    }
}

int main(void)
{
    State st = State0;
    char c;
    int cnt_0 = 0, num_decim = 0;
    while ((c = getchar()) != EOF) {
        switch (st) {
            case State0: {
                if (is_split_simb(c)) {
                    printf("%c", c);
                } else {
                    st = State1;
                }
            }
            case State1: {
                if (c == '0') {
                    cnt_0++;
                } else {
                    st = State2;
                } 
            }
            case State2: {
                if (is_hex_symb(c)) {
                    num_decim *= 16;
                    num_decim += hex_simb_to_int(c);
                } else if (is_split_simb(c)) {
                    if (num_decim != 0) {
                        printf("%X", num_decim);
                    }
                    if (cnt_0 != 0) {
                        for (int i = 0; i < cnt_0; i++) {
                            printf("0");
                        }
                    }
                    printf("%c", c);
                    cnt_0 = 0;
                    num_decim = 0;
                    st = State0;  
                } else {
                    if (cnt_0 != 0) {
                        for (int i = 0; i < cnt_0; i++) {
                            printf("0");
                        }
                    }
                    if (num_decim != 0) {
                        printf("%X", num_decim);
                    }
                    printf("%c", c);
                    cnt_0 = 0;
                    num_decim = 0;
                }
            }
        }
    }
    return 0;  
}