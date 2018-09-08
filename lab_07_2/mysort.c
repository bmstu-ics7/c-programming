#include "mysort.h"

// По возрастанию
int compare_inc(const void* p, const void* q)
{
    return *(int*)p - *(int*)q;
}

// По убыванию
int compare_dec(const void* p, const void* q)
{
    return *(int*)q - *(int*)p;
}

void swap(void* to, void* from, size_t len)
{
    char tmp;
    char* tmp_to = to;
    char* tmp_from = from;

    for (size_t i = 0; i < len; i++)
    {
        tmp = tmp_to[i];
        tmp_to[i] = tmp_from[i];
        tmp_from[i] = tmp;
    }
}

void mysort(void *base, size_t nmemb, size_t size,
	     int (*compar)(const void*, const void*))
{
    for (int i = 0; i < nmemb; i++)
    {
        void* max = base;
        for (void* j = base; j < base + (nmemb - i) * size; j += size)
            if (compar(j, max) > 0)
            {
                max = j;
            }
        
        swap(max, base + (nmemb - 1 - i) * size, size);    
    }
}
