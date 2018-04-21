/*
 * Найти количество чисел, значение которых больше среднего арифметического
 * минимального и максимального чисел.
*/
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define SUCCESS 0
#define ARG_ERROR -1
#define VOID_FILE -2
#define INCORECT_FILE -3
#define CLOSE_ERROR -4

#define TRUE 1
#define FALSE 0

int find_average(FILE* file, float* average)
{
    float num;
    float max = 0, min = 0;
    int first_iteration = TRUE;

    while(fscanf(file, "%f", &num) == 1)
    {
        if (first_iteration)
        {
            max = num;
            min = num;
            first_iteration = FALSE;
        }

        if (max < num)
            max = num;
        if (min > num)
            min = num;
    }

    if (first_iteration && feof(file))
        return VOID_FILE;

    if (!feof(file))
        return INCORECT_FILE;

    *average = (max + min) / 2;
    return SUCCESS;
}

int find_count(FILE* file, const float average, int* count)
{
    float num;
    *count = 0;

    while(fscanf(file, "%f", &num) == 1)
    {
        if (num > average)
            (*count)++;
    }

    return SUCCESS;
}

int write_file(FILE* file, const int count)
{
    fprintf(file, "%d", count);
    return SUCCESS;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Некоректное количество входных данных\n");
        return ARG_ERROR;
    }

    float average;
    int count;

    FILE* file = NULL;
    file = fopen(argv[0], "r");

    if (file == NULL)
    {
        printf("%s", strerror(errno));
        return errno;
    }

    switch (find_average(file, &average))
    {
        case VOID_FILE:
            printf("Файл пустой!");
            return VOID_FILE;

        case INCORECT_FILE:
            printf("Файл некорректный!");
            return INCORECT_FILE;
    }

    if (fclose(file) == EOF)
        return CLOSE_ERROR;

    file = NULL;
    file = fopen(argv[0], "r");

    if (file == NULL)
    {
        printf("%s", strerror(errno));
        return errno;
    }

    find_count(file, average, &count);

    if (fclose(file) == EOF)
        return CLOSE_ERROR;

    file = NULL;
    file = fopen("out.txt", "w");

    if (file == NULL)
    {
        printf("%s", strerror(errno));
        return errno;
    }

    write_file(file, count);

    if (fclose(file) == EOF)
        return CLOSE_ERROR;

    return SUCCESS;
}
