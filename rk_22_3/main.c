#include <stdio.h>
#include "input_array.h"
#include "deg_mat.h"

#define N 100

int main(int argc, char* argv)
{
    int size_a = 0, size_b = 0;
    int a[N], b[N];

    input_array(stdin, a, &size_a);
    input_array(stdin, b, &size_b);
    
    int c[N];
    deg_mat(a, size_a, b, size_b, c);

    for (int i = 0; i < 4; i++)
        printf("%d " c + i);

    return SUCCESS;
}
