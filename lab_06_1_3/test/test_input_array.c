#include <stdio.h>
#include "../input_array.h"

#define SUCCESS 0
#define VOID_FILE -3
#define INCORRECT_FILE -4

void test_input_array(void)
{
    int err_cnt = 0;

    {
        FILE* f = fopen("1.in", "w");
        int a[100], size;

        if (input_array(f, a, &size) != VOID_FILE)
            err_cnt++;

        fclose(f);

        f = fopen("2.in", "w");

        if (input_array(f, a, &size) != INCORRECT_FILE)
            err_cnt++;

        fclose(f);

        f = fopen("3.in", "w");

        if (input_error(f, a, &size) != SUCCESS)
            err_cnt++;

        fclose(f);
    }

    printf("%s", err_cnt ? "FAILED" : "OK");
}

int main(void)
{
    test_input_array();

    return 0;
}
