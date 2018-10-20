#include "operation.h"

/*
 * Находит обратную матрицу методом элементарных преобразований и озвращает ее
 *
 * @param matrix [in]
 * @param n [in]
 * @param m [in]
 * @param nr [out]
 * @param mr [out]
 *
 * @return возвращает NULL в случае ошибки или обратную матрицу
 * в случае удачного выполнения
*/

double **operation(double **matrix, int n, int m, int *nr, int *mr)
{
    if (n != m)
        return NULL;

    int size = n;
    double **ed = allocate_matrix(size, size);

    if (ed == NULL)
        return NULL;

    *nr = size;
    *mr = size;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            ed[i][j] = i == j ? 1 : 0;

    for (int row = 0; row < size; row++)
    {
        if (fabs(matrix[row][row]) < 1e-8)
        {
            int change = 0;

            for (int i = row + 1; i < size; i++)
            {
                if (fabs(matrix[i][row]) > 1e-8)
                {
                    for (int j = 0; j < size; j++)
                    {
                        double temp;
                            
                        temp = matrix[row][j];
                        matrix[row][j] = matrix[i][j];
                        matrix[i][j] = temp;

                        temp = ed[row][j];
                        ed[row][j] = ed[i][j];
                        ed[i][j] = temp;
                    }

                    change = 1;
                    break;
                }
            }

            if (!change)
            {
                free_matrix(ed);
                return NULL;
            }
        }

        double v = matrix[row][row];

        for (int j = 0; j < size; j++)
        {
            matrix[row][j] /= v;
            ed[row][j] /= v;
        }

        for (int i = row + 1; i < size; i++)
        {
            double v = matrix[i][row];

            for (int j = 0; j < size; j++)
            {
                matrix[i][j] -= v * matrix[row][j];
                ed[i][j] -= v * ed[row][j];
            }
        }
    }

    for (int row = size - 1; row > 0; row--)
    {
        for (int i = row - 1; i >= 0; i--)
        {
            double v = matrix[i][row];

            for (int j = 0; j < size; j++)
            {
                matrix[i][j] -= v * matrix[row][j];
                ed[i][j] -= v * ed[row][j];
            }
        }
    }

    return ed;
}

