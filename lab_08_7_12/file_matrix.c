#include "file_matrix.h"

/*
 * Вводит матрицу из файла
 *
 * @param file [in]
 * @param matrix [out]
 * @param n [out]
 * @param m [out]
 *
 * @return возвращает SUCCESS при успешном вводе и
 * код ошибки в остальных случаях
*/

int input_matrix(FILE* file, double ***matrix, int *n, int *m)
{
    if (fscanf(file, "%d", n) != 1)
        return INCORRECT_FILE;
    
    if (fscanf(file, "%d", m) != 1)
        return INCORRECT_FILE;

    if (*n <= 0 || *m <= 0)
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

/*
 * Выводит матрицу в файл
 *
 * @param file [in]
 * @param matrix [in]
 * @param n [in]
 * @param m [in]
*/

void print_matrix(FILE* file, double **matrix, const int n, const int m)
{
    fprintf(file, "%d %d ", n, m);

    int count = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] != 0)
                count++;

    fprintf(file, "%d\n", count);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] != 0)
                fprintf(file, "%d %d %lf\n", i + 1, j + 1, matrix[i][j]);
}
