#include <stdio.h>
#include <stdlib.h>

#include "assert.h"
#include "my_strpbrk.h"

void test1(void)
{
    char *a = "qwerty";
    char *b = "1hr";

    char *answ = my_strpbrk(a, b);
    char *right = "rty";

    assert_string(right, answ, "test1");
}

void test2(void)
{
    char *a = "qwerty";
    char *b = "re";

    char *answ = my_strpbrk(a, b);
    char *right = "erty";

    assert_string(right, answ, "test2");
}

void test3(void)
{
    char *a = "kek";
    char *b = "ek";

    char *answ = my_strpbrk(a, b);
    char *right = "kek";

    assert_string(right, answ, "test3");
}

void test4(void)
{
    char *a = "kek";
    char *b = "jl";

    char *answ = my_strpbrk(a, b);
    char *right = NULL;

    assert_string(right, answ, "test3");
}


void test(void)
{
    test1();
    test2();
    test3();
    test4();

    print_errors("test strpbrk");
}

int main(void)
{
    test();

    return 0;
}
