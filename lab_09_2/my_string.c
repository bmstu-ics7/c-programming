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

    (*lineptr)[len(*lineptr) - 1] = '\0';
    *n = len(*lineptr);

    return *n;
}

char* str_replace(const char *source, const char *search, const char *replace)
{
    int size = len((char*)source);
    int result_size = size;
    char *result = malloc(size);

    for (int i = 0, j = 0, src = 0; i < size; i++)
    {
        if (source[i] == search[src])
        {
            src++;

            if (src == len((char*)search))
            {
                for (int k = 0; k < len((char*)replace); k++)
                {
                    result[j++] = replace[k];
                }

                src = 0;
            }
        }
        else
        {
            for (int k = src; k >= 0; k--)
                result[j++] = source[i - k];

            src = 0;
        }

        if (j == result_size)
            result = realloc(result, result_size * 2);
    }

    return result;
}

void free_string(char *str)
{
    if (str)
        free(str);
}

