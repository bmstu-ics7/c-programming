#include "mysort.h"
#include "assert.h"

void test1(void)
{
    int a[] = {9, 8, 7, 6, 5, 4, 3 ,2 , 1, 0};
    int right[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    mysort(a, 10, sizeof(a[0]), compare_inc);

    assert_array(a, right, 10, "test1");
}

void test2(void)
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int right[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    mysort(a, 10, sizeof(a[0]), compare_dec);

    assert_array(a, right, 10, "test2");
}

void test3(void)
{
    int a[] = {5, 2, 3, 7, 4, 1, 6, 9, 8, 0};
    int right[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    mysort(a, 10, sizeof(a[0]), compare_inc);

    assert_array(a, right, 10, "test3");
}

void test_mysort(void)
{
    test1();
    test2();
    test3();

    print_errors();
}

int main(void)
{
    test_mysort(); 

    return 0;
}
