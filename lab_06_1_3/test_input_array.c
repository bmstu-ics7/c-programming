#include <stdio.h>
#include "input_array.h"

#define SUCCESS 0
#define VOID_FILE -3
#define INCORRECT_FILE -4

#define WRONG -5

int test1(void)
{
    FILE* f = fopen("1.in", "r");
    int a[100], size = 0;

    if (input_array(f, a, &size) == VOID_FILE)
    {
        fclose(f);
        printf("File 1.in true return: VOID_FILE.\n");
        return SUCCESS;
    }
    else
    {
        fclose(f);
        printf("File 1.in wrong return. True return: VOID_FILE.");
        return WRONG;
    }
}

int test2(void)
{
    FILE* f = fopen("2.in", "r");
    int a[100], size = 0;

    if (input_array(f, a, &size) == INCORRECT_FILE)
    {
        fclose(f);
        printf("File 2.in true return: INCORRECT_FILE.\n");
        return SUCCESS;
    }
    else
    {
        fclose(f);
        printf("File 2.in wrong return. True return: INCORRECT_FILE.");
        return WRONG;
    }
}

int test3(void)
{
    FILE* f = fopen("3.in", "r");
    int a[100], size = 0;

    if (input_array(f, a, &size) == SUCCESS)
    {
        printf("File 3.in true return: SUCCESS.\n");
        return SUCCESS;
    }
    else
    {
        printf("File 3.in wrong return. True return: SUCCESS.");
        return WRONG;
    }
}

void test_input_array(void)
{
    int err_cnt = 0;

    if (test1() != SUCCESS)
        err_cnt++;

    if (test2() != SUCCESS)
        err_cnt++;

    if (test3() != SUCCESS)
        err_cnt++;

    printf("%d %s\n", err_cnt, err_cnt ? "FAILED" : "OK");
}

int main(void)
{
    test_input_array();

    return 0;
}
