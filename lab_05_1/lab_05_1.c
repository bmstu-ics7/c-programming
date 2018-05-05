/*
 * Вычислить значение x[0]*y[0] + x[1]*y[1] + ... + x[k]*y[k], где x[i] – отрицательные 
 * элементы массива a из n элементов, взятые в порядке их следования; y[i] – положительные 
 * элементы этого массива, взятые в обратном порядке; k = min(p,q), где p – количество 
 * положительных элементов массива a, q – количество отрицательных элементов этого массива.
*/
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define SUCCESS 0
#define ARG_ERROR -1
#define COUNT_ERROR -2
#define VOID_FILE -3
#define INCORRECT_FILE -4

#define N 100

int input_array(FILE* file, int* array, int* count)
{
    int num;
    *count = 0;

    while(fscanf(file, "%d", &num) == 1)
    {
        if (++(*count) > 100)
            return COUNT_ERROR;

        *(array++) = num;
    }

    if (*count == 0 && feof(file))
        return VOID_FILE;
    else if (!feof(file))
        return INCORRECT_FILE;

    return SUCCESS;
}

int calc(int* const begin, int* const end)
{
    int *i = begin, *j = end;
    int sum = 0;

    while (i <= end && j >= begin)
    {
        if (*i >= 0)
            i++;

        if (*j < 0)
            j--;

        if (*i < 0 && *j >= 0)
            sum += (*(i++)) * (*(j--));
    }

    return sum;
}

int read_error(err)
{
    switch(err)
    {
        case VOID_FILE:
            printf("Файл пустой!");
            return VOID_FILE;

        case INCORRECT_FILE:
            printf("Некорректный файл!");
            return INCORRECT_FILE;

        default:
            return SUCCESS;
    }
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Некорректное количество аргументов!");
        return ARG_ERROR;
    }

    FILE* file = NULL;
    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("%s", strerror(errno));
        return errno;
    }

    int array[N], count = 0;
    int error = 0;

    if ((error = input_array(file, array, &count)) != SUCCESS)
    {
        return read_error(error);
    }

    if (fclose(file) != 0)
    {
        printf("%s", strerror(errno));
        return errno;
    }

    printf("%d\n", calc(array, array + count - 1));
    return SUCCESS;
}
