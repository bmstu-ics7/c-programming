#include "my_string.h"

/* 
 * Вычисляет длину строки
 *
 * @param string [in]
 *
 * @return Длина строки или LEN_ERROR в случае NULL
 */

int len(char *string)
{
    if (string == NULL)
        return LEN_ERROR;

    int n = 0;

    while (string[n] != '\0')
        n++;

    return n;
}

/* 
 * Считывает строку из файла
 *
 * @param lineptr [out]
 * @param n [out]
 * @param stream [in]
 *
 * @return Количество считанных байт или GETLINE_ERROR в случае ошибки
 */

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    char buffer[SIZE_BUF] = { '0' };

    if (lineptr == NULL || stream == NULL || n == NULL)
        return GETLINE_ERROR;

    ssize_t size = 0;

    if (*lineptr == NULL || *n == 0)
    {
        *n = SIZE_BUF;
        *lineptr = calloc(SIZE_BUF, sizeof(char));
    }

    while (fgets(buffer, SIZE_BUF, stream) != NULL)
    {
        size += len(buffer);

        if (*n < size)
        {
            *n *= 2;
            *lineptr = realloc(*lineptr, *n);
        }

        if (*lineptr == NULL)
            return GETLINE_ERROR;

        for (int i = size - len(buffer), j = 0; i < size; i++, j++)
        {
            (*lineptr)[i] = buffer[j];
        }

        if ((*lineptr)[size - 1] == '\n')
            break;
    }

    if (*lineptr == NULL)
        return GETLINE_ERROR;

    if (size == 0)
        return GETLINE_ERROR;

    (*lineptr)[size] = '\0';

    return size;
}

/* 
 * Заменят подсткроки в строке
 *
 * @param source [in]
 * @param search [in]
 * @param replace [in]
 *
 * @return Новая строка
 */

char *str_replace(const char *source, const char *search, const char *replace)
{
    if (source == NULL || search == NULL || replace == NULL)
        return NULL;

    int size = len((char*)source);
    char *result = NULL;
    int n = SIZE_BUF;

    result = calloc(SIZE_BUF, sizeof(char));

    if (result == NULL)
        return NULL;

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

/*
 * Очищает память с проверкой
 *
 * @param str [in]
 */

void free_string(char *str)
{
    if (str)
        free(str);
}


