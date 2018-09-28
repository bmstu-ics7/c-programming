#include "mysort.h"

/*
 * Функция сравнения для сортировки по возрастанию
 *
 * @param p [in]
 * @param q [in]
 *
 * @return возвращает разность между первым и вторым элементами
 */

int compare_inc(const void *p, const void *q)
{
    return *(int*)p - *(int*)q;
}

/*
 * Функция сравнения для сортировки по убыванию
 *
 * @param p [in]
 * @param q [in]
 *
 * @return возвращает разность между вторым и первым элементами
 */

int compare_dec(const void *p, const void *q)
{
    return *(int*)q - *(int*)p;
}

/*
 * Меняет значения двух void*
 *
 * @param to [out]
 * @param from [out]
 * @param len [in]
 */

void swap(void *to, void *from, size_t len)
{
    char tmp;
    char *tmp_to = to;
    char *tmp_from = from;

    for (size_t i = 0; i < len; i++)
    {
        tmp = tmp_to[i];
        tmp_to[i] = tmp_from[i];
        tmp_from[i] = tmp;
    }
}

/*
 * Сортирует массив методом выбора
 *
 * @param base [out]
 * @param nmemb [in]
 * @param size [in]
 * @param compar [in]
 */

void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
    for (int i = 0; i < nmemb; i++)
    {
        char *max = base;
        for (char *j = base; j < (char*)base + (nmemb - i) * size; j += size)
            if (compar(j, max) > 0)
            {
                max = j;
            }
        
        swap(max, (char*)base + (nmemb - 1 - i) * size, size);
    }
}
