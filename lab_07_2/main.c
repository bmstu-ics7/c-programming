/*
 * Сортировка выбором
 *
 * Функция-фильтр:
 * В массиве остаются элементы от нулевого до m-го, где
 * m - индекс первого отрицательного элемента этого массива либо
 * число n (размер исходного массива), если такого элемента
 * в массиве нет. Т.е. отфильтрованный массив содержит элементы,
 * расположенные перед первым отрицательным элементом,
 * или весь исходный массив, если отрицательные элементы отсутствуют.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "input_array.h"
#include "key.h"
#include "mysort.h"
#include "print_array.h"

#define INCORRECT_ARG -3
#define VOID_ARRAY -4

int sort_key(FILE* output, const int *const array, const int size)
{
    int *new_array_begin, *new_array_end;
    
    if (key(array, array + size, &new_array_begin, &new_array_end) != SUCCESS)
    {
        free((int*)array);
        fclose(output);
        return VOID_ARRAY;
    }
    
    mysort(new_array_begin, new_array_end - new_array_begin, sizeof(array[0]), compare_inc);
    
    print_array(output, new_array_begin, new_array_end);
    free(new_array_begin);
    
    return SUCCESS;
}

int main(int argc, char **argv)
{
    if (argc != 3 && argc != 4)
    {
        fprintf(stderr, "Incorrect arguments!");
        return INCORRECT_ARG;
    }

    FILE* file = NULL;
    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));
        return errno;
    }

    int *array, size;

    int code;
    if ((code = input_array(file, &array, &size)) != SUCCESS)
    {
        fclose(file);
        return code;
    }

    if (fclose(file) != SUCCESS)
    {
        fprintf(stderr, "%s", strerror(errno));
        free(array);
        return errno;
    }

    FILE* output = NULL;
    output = fopen(argv[2], "w");

    if (output == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));
        free(array);
        return errno;
    }

    char *pstr = argv[3];

    if (argc == 4 && pstr[0] == 'f' && pstr[1] == 0)
    {
        if (sort_key(output, array, size) != SUCCESS)
            return VOID_ARRAY;
    }
    else
    {
        if (argc == 4)
        {
            fprintf(stderr, "Incorrect arguments!");
            free(array);
            fclose(output);
            return INCORRECT_ARG;
        }

        mysort(array, size, sizeof(array[0]), compare_inc);

        print_array(output, array, array + size);
    }
    
    free(array);
    
    if (fclose(output) != SUCCESS)
    {
        fprintf(stderr, "%s", strerror(errno));
        free(array);
        return errno;
    }

    return SUCCESS;
}
