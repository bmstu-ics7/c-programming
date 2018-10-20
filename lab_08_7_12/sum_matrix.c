#include "sum_matrix.h"

/*
 * Складывает две матрицы и возвращает результат
 *
 * @param mat1 [in]
 * @param n1 [in]
 * @param m1 [in]
 * @param mat2 [in]
 * @param n2 [in]
 * @param m2 [in]
 * @param n [out]
 * @param m [out]
 *
 * @return возвращает NULL в случае ошибки и результат
 * сложения при успешном выполнении
*/

double **sum_matrix(double **mat1, const int n1, const int m1, double **mat2, const int n2, const int m2, int *n, int *m)
{
    if (n1 != n2 || m1 != m2)
        return NULL;
    
    double **mat = allocate_matrix(n1, m1);
    
    if (mat == NULL)
        return NULL;
    
    *n = n1;
    *m = m1;
    
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++)
            mat[i][j] = mat1[i][j] + mat2[i][j];
    
    return mat;
}
