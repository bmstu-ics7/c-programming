/*
 * Ввод - 2
 * Хранение - 4
 * Задание - 2
 * Вывод - 1
 */

#include <stdio.h>
#include <errno.h>

#include "file.h"
#include "work.h"

#define SUCCESS 0
#define ARG_ERROR -2

int main(int argc, char **argv)
{
    if (argc != 2)
        return ARG_ERROR;

    FILE *file = fopen(argv[1], "r");

    int **matrix, n, m;
/*
    if (input_matrix(&matrix, &n, &m, file) != SUCCESS)
    {
        free_matrix(matrix, n);
        return INPUT_ERROR;
    }
*/
    fclose(file);

    file = fopen("result.out", "w");

    work(matrix, n, m, file);

    fclose(file);
    
    free_matrix(matrix, n);

    return SUCCESS;
}
