#include <stdio.h>

#include "my_snprintf.h"
#include "assert.h"

void test1(void)
{
    char *str = malloc(100);
    char *my_str = malloc(100);

    char a = '$';
    int b = 0;
    int c = 33;

    assert(snprintf(str, 100, "asd %c %o %o %x %x", a, b, c, b, c), my_snprintf(my_str, 100, "asd %c %o %o %x %x", a, b, c, b, c), "test1 return value");

    assert_string(str, my_str, "test1 string");

    free(str);
    free(my_str);
}

void test2(void)
{
    char *str = malloc(100);
    char *my_str = malloc(100);

    char a = '$';
    int b = 0;
    int c = 33;

    assert(snprintf(str, 0, "asd %c %o %o %x %x", a, b, c, b, c), my_snprintf(my_str, 0, "asd %c %o %o %x %x", a, b, c, b, c), "test2 return value");

    assert_string("", my_str, "test2 string");

    free(str);
    free(my_str);
}

void test3(void)
{
    char *str = malloc(100);
    char *my_str = malloc(100);

    short int b = 12;
    short int c = 33;

    assert(snprintf(str, 10, "%hx %ho", b, c), my_snprintf(my_str, 10, "%hx %ho", b, c), "test3 return value");

    assert_string(str, my_str, "test3 string");

    free(str);
    free(my_str);
}

void test4(void)
{
    char *str = malloc(100);
    char *my_str = malloc(100);

    char a = '$';
    int b = 1123;
    int c = 33;

    assert(snprintf(str, 100, "ad %c %o %o %x %x", a, b, c, b, c), my_snprintf(my_str, 100, "ad %c %o %o %x %x", a, b, c, b, c), "test4 return value");

    assert_string(str, my_str, "test4 string");

    free(str);
    free(my_str);
}

int test_snprintf(void)
{
    test1();
    test2();
    test3();
    test4();

    return print_errors("my_snprintf");
}

int main(void)
{
    if (test_snprintf() != SUCCESS)
        return WRONG;

    return SUCCESS;
}


