#include <stdio.h>
#include "input_array.h"

#define SUCCESS 0
#define VOID_FILE -3
#define INCORRECT_FILE -4

//int input_array(FILE* file, int* array, int* size);

void test_input_array(void)
{
    int err_cnt = 0;

    {
        FILE* f = fopen("1.in", "r");
        int a[100], size;

        if (input_array(f, a, &size) != VOID_FILE)
            err_cnt++;

        fclose(f);

        f = fopen("2.in", "r");
        int b[100];
        size = 0;

        if (input_array(f, b, &size) != INCORRECT_FILE)
            err_cnt++;

        fclose(f);

        f = fopen("3.in", "r");
        int c[100];
        size = 0;

        if (input_array(f, c, &size) != SUCCESS)
            err_cnt++;

        fclose(f);
    }

    printf("%d %s", err_cnt, err_cnt ? "FAILED" : "OK");
}

int main(void)
{
    test_input_array();

    return 0;
}
