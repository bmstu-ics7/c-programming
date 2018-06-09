#include <stdio.h>
#include <assert.h>

#ifndef INPUT_ARRAY_H
#define INPUT_ARRAY_H

#define SUCCESS 0
#define INPUT_ERROR -2

#define N 100

int input_array(FILE* f, int* a, int* size);

#endif
