#include "work.h"
#include "file.h"

void work(int **matrix, const int n, const int m, FILE *stream)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int have_zero = 0;

        for (int j = 0; j < m; j++)
            if (matrix[i][j] != 0)
            {
                have_zero++;
                break;
            }

        if (!have_zero)
            count++;
    }

    int **new_matrix = NULL;

    new_matrix = allocate_matrix(count, 1);
  
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        int have_zero = 0;

        for (int j = 0; j < m; j++)
            if (matrix[i][j] != 0)
            {
                have_zero++;
                break;
            }

        if (!have_zero)
            new_matrix[index++][0] = i + 1;
    }

    print_matrix(new_matrix, count, 1, stream);

    free_matrix(new_matrix, count);
}
