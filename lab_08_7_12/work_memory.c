#include "work_memory.h"

/*
 * Создает область памяти для матрицы
 *
 * @param n [in]
 * @param m [in]
 *
 * @return возвращает NULL в случае ошибки и
 * указатель на матрицу в случае успеха
*/

double **allocate_matrix(int n, int m)
{
    double **pointers, *data;
    
    pointers = malloc(n * sizeof(pointers[0]));
    
    if (pointers == NULL)
        return NULL;
    
    data = malloc(n * m * sizeof(data[0]));
    
    if (data == NULL)
    {
        free(pointers);

        return NULL;
    }
    
    for (int i = 0; i < n; i++)
        pointers[i] = data + i * m;
    
    return pointers;
}

/*
 * Освобождает память, выделенную под матрицу
 *
 * @param matrix [in]
*/

void free_matrix(double **matrix)
{
    free(matrix[0]);
    
    free(matrix);
}
