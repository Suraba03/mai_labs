#include <stdio.h>

typedef enum {
    STATE0,
    STATE1,
    STATE2
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
    State st = STATE0;
    char c;
    int cnt_0 = 0, num_decim = 0, check_size;
    while ((c = getchar()) != EOF) {
        switch (st) {
            case STATE0:
                if (is_split_simb(c)) {
                    printf("%c", c);
                } else {
                    if (c != '0') {
                        printf("%c", c);
                    } else {
                        cnt_0++;    
                    }
                    st = STATE1;
                }
                break;
            case STATE1:
                if (c == '0') {
                    cnt_0++;
                } else {
                    st = STATE2;
                }
            case STATE2:
                if (is_hex_symb(c)) {
                    if (c <= 'f' && c >= 'a') {
                        check_size = 0;
                    } else {
                        check_size = 1;
                    }
                    num_decim *= 16;
                    num_decim += hex_simb_to_int(c);
                } else if (is_split_simb(c)) {
                    if (num_decim != 0) {
                        if (check_size) {
                            printf("%X", num_decim);
                        } else {
                            printf("%x", num_decim);
                        }
                    }
                    if (cnt_0 != 0) {
                        for (int i = 0; i < cnt_0; i++) {
                            printf("0");
                        }
                    }
                    printf("%c", c);
                    cnt_0 = 0;
                    num_decim = 0;
                    st = STATE0;
                } else {
                    if (cnt_0 != 0) {
                        for (int i = 0; i < cnt_0; i++) {
                            printf("0");
                        }
                    }
                    if (num_decim != 0) {
                        if (check_size) {
                            printf("%X", num_decim);
                        } else {
                            printf("%x", num_decim);
                        }
                    }
                    printf("%c", c);
                    cnt_0 = 0;
                    num_decim = 0;
                }
        }
    }
    return 0;
}