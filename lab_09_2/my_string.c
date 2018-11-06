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

    if (lineptr == NULL || stream == NULL || n == NULL)
        return GETLINE_ERROR;

    if (*n == 0)
        *n = 255;

    ssize_t size = 0;

    if (*lineptr == NULL)
    {
        *n = 255;
        *lineptr = malloc(*n);
    }

    while (fgets(buffer, 255, stream) != NULL)
    {
        size += len(buffer);
        
        *lineptr = realloc(*lineptr, size);

        if (*lineptr == NULL)
            return GETLINE_ERROR;
        
        for (int i = size - len(buffer), j = 0; i < size; i++, j++)
        {
            (*lineptr)[i] = buffer[j];
        }

        if ((*lineptr)[*n - 1] == '\n')
            break;
    }

    if (lineptr == NULL)
        return GETLINE_ERROR;

    if (len(*lineptr) == 0)
        return GETLINE_ERROR;

    (*lineptr)[size] = '\0';

    if (size == 0)
        return GETLINE_ERROR;

    return size;
}

char *str_replace(const char *source, const char *search, const char *replace)
{
    int size = len((char*)source);
    char *result = malloc(size);
    int n = size;

    if (source == NULL || search == NULL || replace == NULL || result == NULL)
    {
        free_string(result);
        return NULL;
    }

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


