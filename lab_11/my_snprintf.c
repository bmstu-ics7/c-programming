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

char *int_to_8(int num)
{
    char *str = malloc(20 + 1);
    int size = 20;
    int i = 0;

    while (num)
    {
        str[i++] = (char)(num % 8 + 48);
        num /= 8;

        if (i == size)
        {
            str = realloc(str, size + 10 + 1);
            size += 10;
        }
    }

    str[i] = '\0';

    for (int j = 0; j < i / 2; j++)
    {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j- 1] = temp;
    }

    return str;
}

char *int_to_16(int num)
{
    char *str = malloc(20 + 1);
    int size = 20;
    int i = 0;

    while (num)
    {
        switch(num % 16)
        {
            case 10:
                str[i++] = 'a';
                break;
            case 11:
                str[i++] = 'b';
                break;
            case 12:
                str[i++] = 'c';
                break;
            case 13:
                str[i++] = 'd';
                break;
            case 14:
                str[i++] = 'e';
                break;
            case 15:
                str[i++] = 'f';
                break;
            default:
                str[i++] = (char)(num % 16 + 48);
                break;
        }

        num /= 16;

        if (i == size)
        {
            str = realloc(str, size + 10 + 1);
            size += 10;
        }
    }

    str[i] = '\0';

    for (int j = 0; j < i / 2; j++)
    {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j- 1] = temp;
    }

    return str;
}

int my_snprintf(char *restrict str, size_t size, const char *restrict format, ...)
{
    va_list args;
    va_start(args, format);

    int len_format = len((char*)format);

    int n = SIZE;
    char *out = malloc(n);
    int len_result = 0;

    for (int i = 0, j = 0; i < len_format; i++)
    {
        if (format[i] == '%')
        {
            if (format[++i] == 'h')
            {
                i++;

                if (format[i] == 'o')
                {
                    int numb = va_arg(args, int);
                    char *numb_str = int_to_8(numb);
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

                if (format[i] == 'x')
                {
                    int numb = va_arg(args, int);
                    char *numb_str = int_to_16(numb);
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

                if (format[i] == 'o')
                {
                    int numb = va_arg(args, int);
                    char *numb_str = int_to_8(numb);
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

                if (format[i] == 'x')
                {
                    int numb = va_arg(args, int);
                    char *numb_str = int_to_16(numb);
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

        len_result = j;
    }

    va_end(args);

    out[len_result] = '\0';

    if (size != 0)
        size--;
    
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
    return len_result;
}

