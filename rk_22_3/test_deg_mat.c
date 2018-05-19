#include <stdio.h>
#include "deg_mat.h"

#define SUCCESS 0
#define WRONG -1

int test1(void)
{
    int a[] = {1, 1, 1, 1};
    int b[] = {2, 2, 2, 2};
    int k[] = {4, 4, 4, 4};
    int c[100], size = 0;

    deg_mat(a, 4, b, 4, c, &size);

    printf("test1\n");

    for (int i = 0; i < 4; i++)
    {
        printf("%d %d\n", k[i], c[i]);

        if (c[i] != k[i])
        {
            printf("test1 failed\n\n");
            return WRONG;
        }
    }

    printf("\n");
    return SUCCESS;
}

int test2(void)
{
    int a[] = {1, 0, 0, 1};
    int b[] = {0, 0, 0, 0};
    int k[] = {0, 0, 0, 0};
    int c[100], size = 0;

    deg_mat(a, 4, b, 4, c, &size);

    printf("test1\n");

    for (int i = 0; i < 4; i++)
    {
        printf("%d %d\n", k[i], c[i]);

        if (c[i] != k[i])
        {
            printf("test1 failed\n\n");
            return WRONG;
        }
    }

    printf("\n");
    return SUCCESS;
}

void test_deg_mat(void)
{
    int err_cnt = 0;

    if (test1() != SUCCESS)
        err_cnt++;

    if (test2() != SUCCESS)
        err_cnt++;

    printf("%d %s", err_cnt, err_cnt ? "FAILED" : "OK");
}

int main(void)
{
    test_deg_mat();

    return 0;
}
