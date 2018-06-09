#include "input_array.h"

int input_array(FILE* f, int* a, int* size)
{
    if (fscanf(f, "%d", size) != 1)
    {
        printf("Некоректный ввод");
        return INPUT_ERROR;
    }

    if (*size > N || *size < 0)
    {
        printf("Некоректный ввод");
        return INPUT_ERROR;
    }

    assert(*size < N && *size > 0);

    for (int i = 0; i < *size; i++)
        if (fscanf(f, "%d", a + i) != 1)
        {
            printf("Некорректный ввод");
            return INPUT_ERROR;
        }

    return SUCCESS;
}
