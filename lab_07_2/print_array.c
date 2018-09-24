#include "print_array.h"

void print_array(FILE* file, const int *const pa, const int *const pb)
{
    for (const int *p = pa; p < pb; p++)
        fprintf(file, "%d ", *p);

    fprintf(file, "\n");
}
