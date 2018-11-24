#include "file.h"

int **allocate_matrix(const int n, const int m)
{
    int **matrix = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
        matrix[i] = calloc(m, sizeof(int));

    return matrix;
}

int input_matrix(int ***matrix, int *n, int *m, FILE *stream)
{
    if (stream == NULL || matrix == NULL || n == NULL || m == NULL)
        return INPUT_ERROR;

    if (fscanf(stream, "%d", n) != 1)
        return INPUT_ERROR;

    if (fscanf(stream, "%d", m) != 1)
        return INPUT_ERROR;

    *matrix = allocate_matrix(*n, *m);

    while (TRUE)
    {
        int i1, i2, value;

        if (feof(stream))
            break;

        if (fscanf(stream, "%d %d %d", &i1, &i2, &value) != 3)
            return INPUT_ERROR;

        (*matrix)[i1 - 1][i2 - 1] = value;
    }

    return SUCCESS;
}

void print_matrix(int **matrix, const int n, const int m, FILE *stream)
{
    int count = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] != 0)
                count++; 

    fprintf(stream, "%d %d %d\n", n, m, count);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] != 0)
                fprintf(stream, "%d %d %d\n", i + 1, j + 1, matrix[i][j]);
}

void free_matrix(int **matrix, const int n)
{
    for (int i = 0; i < n; i++)
        free(matrix[i]);

    free(matrix);
}

