#include <stdio.h>
#include <stdlib.h>

typedef enum {
    STEP_FORW,
    STEP_BACK,
    STEP_LEFT,
    STEP_RIGHT,
    CH_DIR_180,
} Actions;

typedef struct list {
    int number_of_elements;
    int capacity;
    Actions elements;
} list;

/*void printAction(Actions action)
{
    if (action == STEP_FORW)
        printf("step forward!\n");
    else if (action == STEP_BACK)
        printf("step back!\n");
    else if (action == STEP_LEFT)
        printf("step left!\n");
    else if (action == STEP_RIGHT)
        printf("step right!\n");
    else if (action == CH_DIR_180)
        printf("change direction by 180 degrees!\n");
}*/

int main(void)
{
    Actions act1; 
    if (act1 == STEP_FORW) {
        act1
    } 
    printf("%d", act1);
    return 0;
}