#include "work_memory.h"

double **allocate_matrix(int n, int m)
{
    double **pointers, *data;
    
    pointers = malloc(n * sizeof(pointers[0]));
    
    if (pointers == NULL)
        return NULL;
    
    data = malloc(n * m * sizeof(data[0]));
    
    if (data == NULL)
        return NULL;
    
    for (int i = 0; i < n; i++)
        pointers[i] = data + i * m;
    
    return pointers;
}

void free_matrix(double **matrix)
{
    free(matrix[0]);
    
    free(matrix);
}
