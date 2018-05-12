#include <stdio.h>

#ifndef INPUT_ARRAY_H
#define INPUT_ARRAY_H

#define SUCCESS 0
#define COUNT_ERROR -2
#define VOID_FILE -3
#define INCORRECT_FILE -4

int input_array(FILE* file, int* array, int* count);

#endif
