#include "input_array.h"

int input_array(FILE* f, int* a, int* size)
{
    fscanf(f, "%d", size);

    for (int i = 0; i < *size; i++)
        fscanf(f, "%d", a + i);

    return SUCCESS;
}
