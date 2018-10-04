#include "file_matrix.h"

int input_matrix(FILE* file, double ***matrix, int *n, int *m)
{
    if (fscanf(file, "%d", n) != 1)
        return INCORRECT_FILE;
    
    if (fscanf(file, "%d", m) != 1)
        return INCORRECT_FILE;
    
    *matrix = allocate_matrix(*n, *m);
    
    if (*matrix == NULL)
        return ALLOCATE_ERROR;
    
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            if (fscanf(file, "%lf", &(*matrix)[i][j]) != 1)
                return INCORRECT_FILE;
    
    return SUCCESS;
}

void print_matrix(FILE* file, double **matrix, const int n, const int m)
{
    fprintf(file, "%d %d\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            fprintf(file, "%1.3f ", matrix[i][j]);
        
        fprintf(file, "\n");
    }
}
