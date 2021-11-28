#include <stdio.h>
#include <stdlib.h>
#include <time.h> // чтобы использовать функцию time()
 
int main(void) {
  srand(time(NULL));
/* генерируем пять случайных целых чисел из отрезка [80;100] */
  printf("%d\n", 80 + rand() % (100 - 80 + 1)); // [a; b]: {{a + rand() % (b - a + 1)}} 
  printf("%d\n", 80 + rand() % (100 - 79));
  printf("%d\n", 80 + rand() % 21);
  printf("%d\n", 80 + rand() % 21);
  printf("%d\n", 80 + rand() % 21);
}