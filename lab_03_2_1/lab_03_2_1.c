/*
 * Найти количество чисел, значение которых больше среднего арифметического
 * минимального и максимального чисел.
*/
#include <stdio.h>

#define SUCCESS 0
#define ARG_ERROR -1
#define VOID_FILE -2
#define INCORECT_FILE -3
#define NOT_FILE -4

#define ZERO 0
#define ONE 1
#define TWO 2

#define TRUE 1
#define FALSE 0

int find_average(FILE* file, float* average)
{
    float num;
    float max = ZERO, min = ZERO;
    int first_iteration = TRUE;

    while(fscanf(file, "%f", &num) == ONE)
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

    *average = (max + min) / TWO;
    return SUCCESS;
}

int find_count(FILE* file, const float average, int* count)
{
    float num;
    *count = ZERO;

    while(fscanf(file, "%f", &num) == ONE)
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
    if (argc != TWO)
    {
        printf("Некоректное количество входных данных\n");
        return ARG_ERROR;
    }

    float average;
    int count;

    FILE* file = NULL;
    file = fopen(argv[ONE], "r");

    if (file == NULL)
    {
        printf("Файла нет!");
        return NOT_FILE;
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

    fclose(file);

    file = fopen(argv[ONE], "r");
    find_count(file, average, &count);
    fclose(file);

    file = fopen("out.txt", "w");
    write_file(file, count);
    fclose(file);

    return SUCCESS;
}
