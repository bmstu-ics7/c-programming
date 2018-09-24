#include <stdio.h>
#include <stdlib.h>

#ifndef INPUT_ARRAY_H
#define INPUT_ARRAY_H

#define SUCCESS 0
#define VOID_FILE -1
#define INCORRECT_FILE -2

#define SIZE sizeof(int)

int input_array(FILE* file, int **arr, int *n);

#endif
