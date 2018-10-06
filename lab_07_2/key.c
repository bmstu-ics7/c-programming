#include "key.h"

/*
 * Копирует в новый массив все элементы до первого отрицательного,
 * в случае отсутствия отрицательных элементов, полностью копирует массив
 *
 * @param pb_src [in]
 * @param pe_src [in]
 * @param pb_dst [out]
 * @param pe_dst [out]
 *
 * @return возвращает SUCCESS, если ошибки нет,
 * иначе возвращает VOID_ARRAY и NULL_ARRAY
 */

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int size = 0;
    
    if (pb_src == NULL)
    {
        fprintf(stderr, "Null array!");
        return NULL_ARRAY;
    }
    
    if (pb_src == pe_src)
    {
        fprintf(stderr, "Void arrat!");
        return VOID_ARRAY;
    }

    for (const int *pa = pb_src; pa < pe_src; pa++)
    {
        if (*pa >= 0)
            size++;
        else
            break;
    }

    if (size == 0)
    {
        fprintf(stderr, "Void array after key!");
        return VOID_ARRAY;
    }

    *pb_dst = malloc(size * SIZE);

    const int *pa = pb_src;
    int *pb = *pb_dst;

    for (int i = 0; i < size; i++)
        *(pb++) = *(pa++);

    *pe_dst = *pb_dst + size;

    return SUCCESS;
}
