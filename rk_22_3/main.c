#include <stdio.h>

#include "input_array.h"
#include "deg_mat.h"
#include "print_array.h"

int main(int argc, char** argv)
{
    FILE* f = fopen(argv[1], "r");

    int size_a = 0, size_b = 0;
    int a[N], b[N];

    input_array(f, a, &size_a);
    input_array(f, b, &size_b);

    fclose(f);
    
    int size_c = 0;
    int c[N];

    deg_mat(a, size_a, b, size_b, c, &size_c);

    print_array(stdout, c, size_c);

    return SUCCESS;
}
