#include <stdio.h>
#include "input_array.h"
#include "assert.h"

int test1(void)
{
    FILE* f = fopen("1.in", "r");
    int a[100], size = 0;

    if (assert(VOID_FILE, input_array(f, a, &size), "test1") != SUCCESS)
    {
        printf(WHITE "file: void file\n\n");
        fclose(f);

        return WRONG;
    }

    fclose(f);

    return SUCCESS;
}

int test2(void)
{
    FILE* f = fopen("2.in", "r");
    int a[100], size = 0;

    if (assert(INCORRECT_FILE, input_array(f, a, &size), "test2") != SUCCESS)
    {
        printf(WHITE "file: asd \n\n");
	fclose(f);

        return WRONG;
    }

    fclose(f);

    return SUCCESS;
}

int test3(void)
{
    FILE* f = fopen("3.in", "r");
    int a[100], size = 0;

    if (assert(SUCCESS, input_array(f, a, &size), "test3") != SUCCESS)
    {
        printf(WHITE "file: 1 2 3 4\n\n");
        fclose(f);

        return WRONG;
    }

    fclose(f);

    return SUCCESS;
}

void test_input_array(void)
{
    test1();
    test2();
    test3();

    print_errors();
}

int main(void)
{
    test_input_array();

    return 0;
}
