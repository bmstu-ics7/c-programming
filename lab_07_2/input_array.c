#include "input_array.h"

int input_array(FILE* file, int **array, int *size)
{
    int check;
    *size = 0;

    while (fscanf(file, "%d", &check) == 1)
        (*size)++;

    if (*size == 0 && feof(file))
    {
        fprintf(stderr, "Void file!");
        return VOID_FILE;
    }
    else if (!feof(file))
    {
        fprintf(stderr, "Incorrect file!");
        return INCORRECT_FILE;
    }

    fseek(file, 0, SEEK_SET);

    *array = malloc(*size * SIZE);
    int *pa = *array;

    for (int i = 0; i < *size; i++)
        if (fscanf(file, "%d", pa++) != 1)
        {
            free(array);
            return INCORRECT_FILE;
        }

    return SUCCESS;
}
