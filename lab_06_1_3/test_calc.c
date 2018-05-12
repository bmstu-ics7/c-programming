#include <stdio.h>
#include "calc.h"

void test_calc(void)
{
    int err_cnt = 0;

    {
        int a[] = {1, 2, -1};
        if (calc(a, a + 2) != -2)
            err_cnt++;

        int b[] = {3, 5, -2, -4};
        if (calc(b, b + 3) != -22)
            err_cnt++;
    }

    printf("%d %s\n", err_cnt, err_cnt ? "FAILED" : "OK");
}

int main(void)
{
    test_calc();

    return 0;
}
