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
        str = malloc(size + 1);
    else
    {
        str = malloc(++size + 1);
        str[0] = '-';
        n *= -1;
    }

    for (int i = size - 1; n; i--)
    {
        str[i] = (char)(n % 10 + 48);
        n /= 10;
    }

    str[size] = '\0';

    return str;
}

int my_snprintf(char *restrict str, size_t size, const char *restrict format, ...)
{
    va_list args;
    va_start(args, format);

    int len_format = len((char*)format);

    int n = SIZE;
    char *out = malloc(n);
    int result_n = 0;

    for (int i = 0, j = 0; i < len_format; i++)
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
                            out = realloc(out, n * 2 + 1);
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
                        out = realloc(out, n * 2 + 1);
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
                            out = realloc(out, n * 2 + 1);
                            n *= 2;
                        }
                    }

                    free(numb_str);
                }
            }
        }
        else
            out[j++] = format[i];

        if (j == n)
        {
            out = realloc(out, n * 2);
            n *= 2;
        }

        result_n = j;
    }

    va_end(args);

    out[result_n] = '\0';
    int len_result = len(out);

    if (len_result > size)
        out[size] = '\0';

    if (str == NULL)
    {
        free(out);
        return len_result;
    }

    for (int i = 0; i < len_result; i++)
        str[i] = out[i];

    free(out);
    va_end(args);
    return len_result;
}

