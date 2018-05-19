#include "deg_mat.h"

void deg_mat(const int* const a, const int size_a, 
            const int* const b, const int size_b,
            int* c)
{
    //Строки на столбцы
    for (int i = 0; i < sqrt(size_a); i++)
    {
        for (int j = 0; j < sqrt(size_b); j++)
        {
            //i-e j-e
            //i-я строчка a j-й столбец b
            for (int k = 0; k < sqrt(size_a); k++)
            {
                c[i * 3 + j] = a[i * 3 + k] * b[k * 3 + j];
            }
        }
    }
}
