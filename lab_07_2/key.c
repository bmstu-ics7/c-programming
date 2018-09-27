#include "key.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int size = 0;
    
    if (pb_src == NULL)
    {
        fprintf(stderr, "Null array!");
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
