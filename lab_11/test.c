#include <stdio.h>

#include "my_snprintf.h"

int main(void)
{
    char *str = malloc(100);
    char *my_str = malloc(100);

    char a = '@';
    int b = 0x12b;
    int c = 123;

    printf("n: %d\n", snprintf(str, 100, "kek%c %x %o\n", a, b, c));
    printf("my_n: %d\n", my_snprintf(my_str, 100, "kek%c %x %o\n", a, b, c));

    printf("str: %s\nmy_str: %s", str, my_str);

    free(str);
    free(my_str);
}

