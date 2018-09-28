#include "print_array.h"

/*
 * Выводит массив в файл
 *
 * @param file [in]
 * @param pa [in]
 * @param pb [in]
 */

void print_array(FILE* file, const int *const pa, const int *const pb)
{
    for (const int *p = pa; p < pb; p++)
        fprintf(file, "%d ", *p);

    fprintf(file, "\n");
}
