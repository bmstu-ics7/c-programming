#include "operation.h"
#include "file_matrix.h"

double **operation(double **mat, int n, int m, int *nr, int *mr)
{
    // Нули на главной диагонали ломают прогу
    
    if (n != m)
        return NULL;
    
    double **ed = allocate_matrix(n, m);
    
    if (ed == NULL)
        return NULL;
    
    *nr = n;
    *mr = m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ed[i][j] = i == j ? 1 : 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            for (int k = 0; k < m; k++)
            {
                mat[j][k] *= mat[i][i];
                ed[j][k] *= ed[i][i];
            }
        
        for (int j = i + 1; j < n; j++)
        {
            while (mat[j][i] != 0)
            {
                if (mat[j][i] * mat[i][i] >= 0)
                    for (int k = 0; k < m; k++)
                    {
                        mat[j][k] -= mat[i][k];
                        ed[j][k] -= ed[i][k];
                    }
                else
                    for (int k = 0; k < m; k++)
                    {
                        mat[j][k] += mat[i][k];
                        ed[j][k] += ed[i][k];
                    }
            }
        }
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            mat[i][j] /= mat[i][i];
            ed[i][j] /= ed[i][i];
        }
    
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int v = mat[i][j];
            for (int k = 0; k < m; k++)
            {
                mat[i][k] -= v * mat[j][k];
                ed[i][k] -= v * ed[j][k];
            }
        }
    }
    
    return ed;
}
