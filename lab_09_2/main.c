#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "my_string.h"

#define SUCCESS 0
#define ARG_ERROR -2

#define COUNT_ARG 5

FILE *file_in = NULL;
FILE *file_out = NULL;
FILE *file_search = NULL;
FILE *file_replace = NULL;

char *source = NULL;
char *search = NULL;
char *replace = NULL;
char *result = NULL;

int all_fopen(char **argv)
{
    file_in = NULL;
    file_out = NULL;
    file_search = NULL;
    file_replace = NULL;

    file_in = fopen(argv[1], "r");
    file_out = fopen(argv[2], "w");
    file_search = fopen(argv[3], "r");
    file_replace = fopen(argv[4], "r");

    if (file_in == NULL || file_out == NULL || file_search == NULL || file_replace == NULL)
        return errno;

    return SUCCESS;
}

int all_fclose(void)
{
    fclose(file_in);
    fclose(file_out);
    fclose(file_search);
    fclose(file_replace);

    if (errno != SUCCESS)
        return errno;

    return SUCCESS;
}

void all_free(void)
{
    free_string(source);
    free_string(search);
    free_string(replace);
    free_string(result);
}

int return_error(int error)
{
    all_fclose();
    all_free();

    switch (error)
    {
        case SUCCESS:
            return SUCCESS;
        case ARG_ERROR:
            fprintf(stderr, "%s\n", "Incorrect arguments");
            return ARG_ERROR;
        case GETLINE_ERROR:
            fprintf(stderr, "%s\n", "Getline error");
        default:
            fprintf(stderr, "%s\n", strerror(errno));
            return errno;
    }
}

int replace_in_file(void)
{
    size_t n = 0;

    if (my_getline(&search, &n, file_search) == GETLINE_ERROR)
        return GETLINE_ERROR;

    if (my_getline(&replace, &n, file_replace) == GETLINE_ERROR)
        return GETLINE_ERROR;

    while (my_getline(&source, &n, file_in) != GETLINE_ERROR)
    {
        result = str_replace(source, search, replace);
        fprintf(file_out, "%s\n", result);
    }

    return SUCCESS;
}

int main(int argc, char **argv)
{
    if (argc != COUNT_ARG)
        return return_error(ARG_ERROR);

    int code_error = SUCCESS;

    if ((code_error = all_fopen(argv)) != SUCCESS)
        return return_error(code_error);

    if ((code_error = replace_in_file()) != SUCCESS)
        return return_error(code_error);

    return return_error(SUCCESS);
}

