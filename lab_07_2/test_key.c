#include "key.h"
#include "assert.h"

void test1(void)
{
    int a[] = {1, 2, 3, 4, 5};
    int *b, *b_end;
    int right[] = {1, 2, 3, 4, 5};

    key(a, a + 5, &b, &b_end);

    assert_array(right, b, 5, "test1");
}

void test2(void)
{
    int a[] = {1, 2, 3, -4, 5};
    int *b, *b_end;
    int right[] = {1, 2, 3};

    key(a, a + 5, &b, &b_end);

    assert_array(right, b, 3, "test2");
}

void test3(void)
{
    int a[] = {1, -2, 3, 4};
    int *b, *b_end;
    int right[] = {1};

    key(a, a + 5, &b, &b_end);

    assert_array(right, b, 1, "test3");
}

void test_key(void)
{
    test1();
    test2();
    test3();

    print_errors();
}

int main(void)
{
    test_key();

    return 0;
}
