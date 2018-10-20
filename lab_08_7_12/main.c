#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "file_matrix.h"
#include "work_memory.h"
#include "sum_matrix.h"
#include "deg_matrix.h"
#include "operation.h"

#define SUCCESS 0
#define ARG_ERROR -3
#define OPERATION_ERROR -4

/*
 * Выводит сообщение об ошибке и возвращает ее код
 *
 * @param error [in]
 *
 * @return возвращает введенный код ошибки
*/

int return_error(int error)
{
    switch (error)
    {
        case ALLOCATE_ERROR:
            fprintf(stderr, "Allocate failed!\n");
            return error;
        case INCORRECT_FILE:
            fprintf(stderr, "Incorrect file!\n");
            return error;   
        case ARG_ERROR:
            fprintf(stderr, "Arguments error!\n");
            return error;
        case OPERATION_ERROR:
            fprintf(stderr, "Impossible operation!\n");
            return error;
        default:
            fprintf(stderr, "%s", strerror(errno));
            return errno;
    }
}

/*
 * Выполняет одну из доступных операций
 *
 * @param res [out]
 * @param mat1 [in]
 * @param n1 [in]
 * @param m1 [in]
 *
 * @return возвращает SUCCESS в случае удачного выполнения и код ошибки
 * в остальных случаях
*/

int action(FILE* res, double **mat1, int n1, int m1, double **mat2, int n2, int m2, char *act)
{
    if (act[1] != '\0')
        return return_error(ARG_ERROR);
    
    double **res_mat = NULL;
    int n = 0, m = 0;

    switch (act[0])
    {
        case 'a':
            if (mat2)
            {
                res_mat = sum_matrix(mat1, n1, m1, mat2, n2, m2, &n, &m);
                break;
            }
            
            free_matrix(mat1);
            fclose(res);
            return return_error(ARG_ERROR);
        case 'm':
            if (mat2)
            {
                res_mat = deg_matrix(mat1, n1, m1, mat2, n2, m2, &n, &m);
                break;
            }
            
            free_matrix(mat1);
            fclose(res);
            return return_error(ARG_ERROR);
        case 'o':
            if (!mat2)
            {
                res_mat = operation(mat1, n1, m1, &n, &m);
                break;
            }
            
            free_matrix(mat1);
            free_matrix(mat2);
            fclose(res);
            return return_error(ARG_ERROR);
        case 'h':
            printf("./app.exe action file1 [file2] file_res\nactions:\n[a] - summ\n[m] - ");
            break;
        default:
            return return_error(ARG_ERROR);
    }
    
    if (res_mat == NULL)
    {
        free_matrix(mat1);

        if (mat2)
            free_matrix(mat2);
        
        fclose(res);
        return return_error(ALLOCATE_ERROR);
    }
    
    print_matrix(res, res_mat, n, m);
    
    free_matrix(mat1);

    if (mat2)
        free_matrix(mat2);

    free_matrix(res_mat);
    
    if (fclose(res) != SUCCESS)
        return return_error(errno);
    
    return SUCCESS;
}

int main(int argc, char **argv)
{
    int code;
    
    if (argc != 4 && argc != 5)
        return return_error(ARG_ERROR);
    
    FILE* f1 = NULL;
    FILE* f2 = NULL;
    FILE* res = NULL;
    
    f1 = fopen(argv[2], "r");
    
    if (f1 == NULL)
        return return_error(errno);
    
    double **mat1 = NULL;
    int n1, m1;
    
    double **mat2 = NULL;
    int n2, m2;
    
    code = input_matrix(f1, &mat1, &n1, &m1);
    
    if (code != SUCCESS)
    {
        fclose(f1);

        if (mat1)
            free_matrix(mat1);

        return return_error(code);
    }
    
    if (fclose(f1) != SUCCESS)
    {
        free_matrix(mat1);
        return return_error(errno);
    }
    
    if (argc == 5)
    {
        f2 = fopen(argv[3], "r");
        
        if (f2 == NULL)
        {
            free_matrix(mat1);
            return return_error(errno);
        }
        
        code = input_matrix(f2, &mat2, &n2, &m2);
        
        if (code != SUCCESS)
        {
            fclose(f2);

            free_matrix(mat1);

            if (mat2)
                free_matrix(mat2);

            return return_error(code);
        }
        
        if (fclose(f2) != SUCCESS)
        {
            free_matrix(mat1);
            free_matrix(mat2);
            return return_error(errno);
        }
        
        res = fopen(argv[4], "w");
    }
    else
        res = fopen(argv[3], "w");
    
    if (res == NULL)
    {
        free_matrix(mat1);

        if (mat2) 
            free_matrix(mat2);

        return return_error(errno);
    }

    return action(res, mat1, n1, m1, mat2, n2, m2, argv[1]);
}
