#include <stdio.h>
#include "calc.h"

#define SUCCESS 0
#define WRONG -1

int test1(void)
{
    int a[] = {1, 2, -1};
    int k = calc(a, a + 2);

    if (k == -2)
    {
        printf("Test {1, 2, -1} true answer: -2\n");
        return SUCCESS;
    }
    else
    {
        printf("Test {1, 2, -1} wrong answer: %d. True: -2\n", k);
        return WRONG;
    }
}

int test2(void)
{
    int a[] = {3, 5, -2, -4};
    int k = calc(a, a + 3);

    if (k == -22)
    {
        printf("Test {3, 5, -2, -4} true answer: -22\n");
        return SUCCESS;
    }
    else
    {
        printf("Test {3, 5, -2, -4} wrong answer: %d. True: -22\n", k);
        return WRONG;
    }
}

void test_calc(void)
{
    int err_cnt = 0;

    if (test1() != SUCCESS)
        err_cnt++;

    if (test2() != SUCCESS)
        err_cnt++;

    printf("%d %s\n", err_cnt, err_cnt ? "FAILED" : "OK");
}

int main(void)
{
    test_calc();

    return 0;
}
