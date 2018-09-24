/*
 * Сортировка выбором
 *
 * Функция-фильтр:
 * В массиве остаются элементы, которые больше суммы элементов расположенных 
 * за ним. Последний элемент в отфильтрованный массив не попадает никогда, 
 * потому что его не с чем сравнивать.
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

int main(int argc, char **argv)
{
    if (argc != 2 && argc != 3) 
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
        return code;

    if (fclose(file) != SUCCESS)
    {
        fprintf(stderr, "%s", strerror(errno));
        return errno;
    }

    char *pstr = argv[2];
    if (argc == 3 && pstr[0] == 'f' && pstr[1] == 0)
    {
        int *new_array_begin, *new_array_end;

        if (key(array, array + size, &new_array_begin, &new_array_end) != SUCCESS)
            return VOID_ARRAY;

        mysort(new_array_begin, new_array_end - new_array_begin, sizeof(array[0]), compare_inc);

        print_array(stdout, new_array_begin, new_array_end);
        free(new_array_begin);
    }
    else
    {
        if (argc == 3)
        {
            fprintf(stderr, "Incorrect arguments!");
            return INCORRECT_ARG;
        }

        mysort(array, size, sizeof(array[0]), compare_inc);

        print_array(stdout, array, array + size);
    }

    free(array);

    return SUCCESS;
}
