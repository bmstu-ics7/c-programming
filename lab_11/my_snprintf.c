#include "my_snprintf.h"

int len(char *str)
{
    int n = 0;
    while (str[n] != '\0') n++;
    return n;
}

char *int_to_str(int n)
{
    int num = n;
    int size = 0;

    while (num)
    {
        num /= 10;
        size++;
    }

    char *str;
    if (n >= 0)
        str = malloc(size);
    else
    {
        str = malloc(++size);
        str[0] = '-';
        n *= -1;
    }

    for (int i = size - 1; n; i--)
    {
        printf("%d\n", n);
        str[i] = (char)(n % 10 + 48);
        n /= 10;
    }

    return str;
}

int my_snprintf(char *restrict str, size_t size, const char *restrict format, ...)
{
    va_list args;
    va_start(args, format);

    int format_len = len((char*)format);

    int n = SIZE;
    char *out = malloc(n);

    for (int i = 0, j = 0; i < format_len; i++)
    {
        if (format[i] == '%')
        {
            if (format[++i] == 'h')
            {
                i++;

                if (format[i] == 'o' || format[i] == 'x')
                {
                    int numb = va_arg(args, int);
                    char *numb_str = int_to_str(numb);
                    int len_str = len(numb_str);

                    for (int k = 0; k < len_str; k++)
                    {
                        out[j++] = numb_str[k];

                        if (j == n)
                        {
                            out = realloc(out, n * 2);
                            n *= 2;
                        }
                    }

                    free(numb_str);
                }
            }
            else
            {
                if (format[i] == 'c')
                {
                    char symb = va_arg(args, int);
                    out[j++] = symb;

                    if (j == n)
                    {
                        out = realloc(out, n * 2);
                        n *= 2;
                    }
                }

                if (format[i] == 'o' || format[i] == 'x')
                {
                    int numb = va_arg(args, int);
                    char *numb_str = int_to_str(numb);
                    int len_str = len(numb_str);

                    for (int k = 0; k < len_str; k++)
                    {
                        out[j++] = numb_str[k];

                        if (j == n)
                        {
                            out = realloc(out, n * 2);
                            n *= 2;
                        }
                    }

                    free(numb_str);
                }
            }
        }

        out[j++] = format[i];

        if (j == n)
        {
            out = realloc(out, n * 2);
            n *= 2;
        }
    }

    int len_result = len(out);

    if (str == NULL)
        return len_result;

    for (int i = 0; i < len_result; i++)
        str[i] = out[i];

    free(out);
    va_end(args);
    return len_result;
}

