#include <stdlib.h>

#ifndef __WORK_MEMORY_H
#define __WORK_MEMORY_H

double **allocate_matrix(int n, int m);

void free_matrix(double **matrix);

#endif
