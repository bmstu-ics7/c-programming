/*
 * input_array.c
*/
#include <stdio.h>
#include "input_array.h"

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

