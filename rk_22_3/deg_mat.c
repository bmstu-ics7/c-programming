#include "deg_mat.h"

void deg_mat(const int* const a, const int size_a, 
            const int* const b, const int size_b,
            int* c, int* size_c)
{
    *size_c = size_a;
    //Строки на столбцы
    int size = sqrt(size_a);

    for (int i = 0; i < *size_c; i++)
        c[i] = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            //i-e j-e
            //i-я строчка a j-й столбец b
            for (int k = 0; k < size; k++)
            {
                c[i * size + j] += a[i * size + k] * b[k * size + j];
            }
        }
    }
}
