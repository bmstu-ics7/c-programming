#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "input_array.h"
#include "deg_mat.h"
#include "print_array.h"

#define SUCCESS 0
#define ARG_ERROR -1
#define INPUT_ERROR -2

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Incorrect arguments");
        return ARG_ERROR;
    }

    FILE* f = NULL;
    f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("%s", strerror(errno));
        return errno;
    }

    int size_a = 0, size_b = 0;
    int a[N], b[N];

    if (input_array(f, a, &size_a) != SUCCESS)
        return INPUT_ERROR;

    if (input_array(f, b, &size_b) != SUCCESS)
        return INPUT_ERROR;

    fclose(f);
    
    int size_c = 0;
    int c[N];

    deg_mat(a, size_a, b, size_b, c, &size_c);

    print_array(stdout, c, size_c);

    return SUCCESS;
}
