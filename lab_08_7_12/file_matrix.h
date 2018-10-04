#include <stdio.h>

#include "work_memory.h"

#ifndef __FILE_MATRIX_H
#define __FILE_MATRIX_H

#define SUCCESS 0
#define ALLOCATE_ERROR -1
#define INCORRECT_FILE -2

int input_matrix(FILE* file, double ***matrix, int *n, int *m);

void print_matrix(FILE* file, double **matrix, const int n, const int m);

#endif
