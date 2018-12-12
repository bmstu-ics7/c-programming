#include <stdio.h>

#include "my_snprintf.h"

int main(void)
{
    char *str = malloc(100);
    char *my_str = malloc(100);

    char a = '@';
    int b = 0x12b;

    printf("n: %d\n", snprintf(str, 20, "kek%c %x\n", a, b));
    printf("my_n: %d\n", my_snprintf(my_str, 20, "kek%c %x\n", a, b));

    printf("str: %s\nmy_str: %s", str, my_str);

    free(str);
    free(my_str);
}

