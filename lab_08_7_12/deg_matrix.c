#include "deg_matrix.h"

double **deg_matrix(double **mat1, const int n1, const int m1, double **mat2, const int n2, const int m2, int *n, int *m)
{
    if (m1 != n2)
        return NULL;
    
    double **mat = allocate_matrix(n1, m2);
    
    if (mat == NULL)
        return NULL;
    
    *n = n1;
    *m = m2;
    
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m2; j++)
        {
            mat[i][j] = 0;
            
            for (int k = 0; k < m1; k++)
                mat[i][j] += mat1[i][k] * mat2[k][j];
        }
    
    return mat;
}
