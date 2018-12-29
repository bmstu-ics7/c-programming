#include "lab_07.h"

/*
 * Аллоцирует массив и считывает его из файла
 *
 * @param file [in]
 * @param array [out]
 * @param size [out]
 *
 * @return возвращает SUCCESS, если ошибки нет,
 * иначе возвращает VOID_FILE или INCORRECT_FILE
 */

int input_array(FILE* file, int **array, int *size)
{
    int check;
    *size = 0;

    while (fscanf(file, "%d", &check) == 1)
        (*size)++;

    if (*size == 0 && feof(file))
    {
        fprintf(stderr, "Void file!");
        return VOID_FILE;
    }
    else if (!feof(file))
    {
        fprintf(stderr, "Incorrect file!");
        return INCORRECT_FILE;
    }

    fseek(file, 0, SEEK_SET);

    *array = malloc(*size * SIZE);
    int *pa = *array;

    for (int i = 0; i < *size; i++)
        if (fscanf(file, "%d", pa++) != 1)
        {
            free(array);
            return INCORRECT_FILE;
        }

    return SUCCESS;
}

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

int key(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst)
{
    int size = 0;
    
    if (pb_src == NULL)
    {
        fprintf(stderr, "Null array!");
        return NULL_ARRAY;
    }
    
    if (pb_src == pe_src)
    {
        fprintf(stderr, "Void array!");
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

    const int *pa = pb_src;
    int *pb = pb_dst;

    for (int i = 0; i < size; i++)
        *(pb++) = *(pa++);


    pe_dst = pb_dst + size;

    return SUCCESS;
}
