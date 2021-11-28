#include <stdio.h>

typedef enum {
    S0, S1, S2, S3, S4
//  0   1   2   3   4
} State;


int is_alphanum(char c)
{
    if (c <= 'Z' && c >= 'A' || c <= 'z' && c >= 'a' || c <= '9' && c >= '0') {
        return 1;
    }
    return 0;
}

int is_space(char c)
{
    if (c == ' ' || c == '\n') {
        return 1;
    }
    return 0;
}
// abdvdvdv%email@com.ru
int main(void)
{
    char c;
    int cnt = 0;
    State state = S0;

    while ((c = getchar()) != EOF) {
        switch (state) {
            case S0:
                if (is_alphanum(c)) {
                    state = S1;
                }
                break;

            case S1:
                if (is_alphanum(c)) {
                    state = S1;
                } else if (c == '@') {
                    state = S2;
                } else {
                    state = S0;
                }
                break;

            case S2:
                if (is_alphanum(c)) {
                    state = S2;
                } else if (c == '.') {
                    state = S3;
                } else {
                    state = S0;
                }
                break;

            case S3:
                if (is_alphanum(c)) {
                    state = S4;
                } else {
                    state = S0;
                }
                break;

            case S4:
                if (is_alphanum(c)) {
                    state = S4;
                } else if (c == '.') {
                    state = S3;
                } else if (is_space(c)) {
                    // email@com.ru ...
                    //             ^
                    cnt++;
                    state = S0;
                } else {
                    state = S0;
                }
                break;
        }
    }

    printf("%d\n", cnt);
    return 0;   
}