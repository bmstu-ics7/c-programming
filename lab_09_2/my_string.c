#include "my_string.h"

int len(char *string)
{
    int n = 0;
    while (string[n++] != '\0');
    return n - 1;
}

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    char buffer[255];
    *n = 0;

    *lineptr = NULL;

    while (fgets(buffer, 255, stream) != NULL)
    {
        *n += len(buffer);
        
        *lineptr = realloc(*lineptr, *n);

        if (*lineptr == NULL)
            return GETLINE_ERROR;
        
        for (int i = *n - len(buffer), j = 0; i < *n; i++, j++)
        {
            (*lineptr)[i] = buffer[j];
        }

        if ((*lineptr)[*n - 1] == '\n')
            break;
    }

    if (*lineptr == NULL)
        return GETLINE_ERROR;

    if (len(*lineptr) == 0)
        return GETLINE_ERROR;

    (*lineptr)[len(*lineptr) - 1] = '\0';
    *n = len(*lineptr);

    if (*n == 0)
        return GETLINE_RROR;

    return *n;
}

char *str_replace(const char *source, const char *search, const char *replace)
{
    int size = len((char*)source);
    char *result = malloc(size);
    int n = size;

    for (int i = 0, src = 0, j = 0; i < size; i++)
    {
        if (i == size - 1 && src != len((char*)search) - 1)
        {
            for (int k = src; k >= 0; k--)
            {
                result[j++] = source[i - k];

                if (j == n)
                {
                    result = realloc(result, n * 2);
                    n *= 2;
                }
            }
            continue;
        }

        if (source[i] == search[src])
        {
            src++;

            if (src == len((char*)search))
            {
                for (int k = 0; k < len((char*)replace); k++)
                {
                    result[j++] = replace[k];

                    if (j == n)
                    {
                        result = realloc(result, n * 2);
                        n *= 2;
                    }
                }

                src = 0;
            }
        }
        else
        {
            for (int k = src; k >= 0; k--)
            {
                result[j++] = source[i - k];

                if (j == n)
                {
                    result = realloc(result, n * 2);
                    n *= 2;
                }
            }

            src = 0;
        }
    }

    return result;
}

void free_string(char *str)
{
    if (str)
        free(str);
}


