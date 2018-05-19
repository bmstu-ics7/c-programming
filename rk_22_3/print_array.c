#include "print_array.h"

int print_array(FILE* f, const int* const a, const int size)
{
    fprintf(f, "%d\n", size);

    for (int i = 0; i < size; i++)
        fprintf(f, "%d ", a[i]);

    return SUCCESS;
}
