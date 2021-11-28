#include <stdio.h>

typedef enum {
    S0, S1, S2, S3
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
    int num_10 = 0;
    if (x <= 'F' && x >= 'A') {
        num_10 = x - 55;
        return num_10;
    }
    else if (x <= 'f' && x >= 'a') {
        num_10 = x - 87;
        return num_10;
    }
    else if (x <= '9' && x >= '0') {
        num_10 = x - 48;
        return num_10;
    }
}

int main()
{
    State st = S0;
    char c;
    int cnt_0 = 0, num_decim = 0, check = 0;
    while ((c = getchar()) != EOF) {
        if (st == S0) {
            if (is_split_simb(c)) {
                printf("%c", c);
            }
            else {
                st = S1;
            } 
        }
        if (st == S1) {
            if (c == '0') {
                cnt_0++;
            }
            else {
                st = S2;
            }
       
        }
        if (st == S2) {
            if (is_hex_symb(c)) {
                num_decim += hex_simb_to_int(c);
                if (num_decim != 0 || check == 1) {
                    printf("%X", num_decim);
                    check = 1;
                    num_decim = 0;
                } else if (check == 0) {
                    cnt_0++;
                }
            }
            if (is_split_simb(c)) {
                if (cnt_0 != 0) {
                    for (int i = 0; i < cnt_0; i++) {
                        printf("0");
                    }  
                }
                printf("%c", c);
                cnt_0 = 0;
                num_decim = 0;
                st = S0;
                check = 0;
            }       
        }   
    }
        if (cnt_0 != 0) {
            for (int i = 0; i < cnt_0; i++) {
                printf("0");
            }
        }
}