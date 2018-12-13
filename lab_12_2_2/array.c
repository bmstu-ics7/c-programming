#include "array.h"

void fibb_arr(int *array, const int size)
{
    if (array == NULL || size == 0)
        return;

    if (size == 1)
    {
        array[0] = 1;
        return;
    }

    array[1] = 1;

    for (int i = 2; i < size; i++)
        array[i] = array[i - 1] + array[i - 2];
}

void cp_no_dublicates(int **new_array, const int *const cp_array, int *new_size, const int cp_size)
{
    if (cp_array == NULL || cp_size == 0)
        return;

    int *cp = malloc(cp_size * sizeof(int));
    *new_size = 0;

    for (int i = 0; i < cp_size; i++)
    {
        int was = 0;
        for (int j = 0; j < *new_size; j++)
        {
            if (cp_array[i] == cp[j])
            {
                was = 1;
                break;
            }
        }

        if (!was)
            cp[(*new_size)++] = cp_array[i];
    }

    *new_array = malloc(*new_size * sizeof(int));
    for (int i = 0; i < *new_size; i++)
        (*new_array)[i] = cp[i];

    free(cp);
}

void print_array(const int *const array, const int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}
