#include "my_sprintf.h"

int len(char *str)
{
    int n = 0;
    while (str[n] != '\n') n++;
    return n;
}

int my_sprintf(char *format, ...)
{
    va_list args;
    va_start(args, format);

    va_arg(args);

    va_end(args);
    return 0;
}
