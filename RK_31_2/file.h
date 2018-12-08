#ifndef __FILE_H
#define __FILE_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define SUCCESS 0
#define INPUT_ERROR -1

int **allocate_matrix(const int n, const int m);

int input_matrix(int ***matrix, int *n, int *m, FILE *stream);

void print_matrix(int **matrix, const int n, const int m, FILE *stream);

void free_matrix(int **matrix, const int n);

#endif
