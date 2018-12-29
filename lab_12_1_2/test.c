#include "lab_07.h"
#include "assert.h"

void test_key1(void)
{
    int a[] = { 1, 2, 3, 4, 5 };
    int *b = malloc(10 * SIZE);
    int *b_end;
    int right[] = { 1, 2, 3, 4, 5 };
    
    key(a, a + 5, b, b_end);
    
    assert_array(right, b, 5, "test1");
    
    free(b);
}

void test_key2(void)
{
    int a[] = { 1, 2, 3, -4, 5 };
    int *b = malloc(10 * SIZE);
    int *b_end;
    int right[] = { 1, 2, 3 };
    
    key(a, a + 5, b, b_end);
    
    assert_array(right, b, 3, "test2");
    
    free(b);
}

void test_key3(void)
{
    int a[] = { 1, -2, 3, 4 };
    int *b = malloc(10 * SIZE);
    int *b_end;
    int right[] = { 1 };
    
    key(a, a + 5, b, b_end);
    
    assert_array(right, b, 1, "test3");
    
    free(b);
}

void test_key(void)
{
    printf("Test key.c\n");
    test_key1();
    test_key2();
    test_key3();
    
    print_errors();
}

void test_mysort1(void)
{
    int a[] = { 9, 8, 7, 6, 5, 4, 3 ,2 , 1, 0 };
    int right[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    mysort(a, 10, sizeof(a[0]), compare_inc);
    
    assert_array(a, right, 10, "test1");
}

void test_mysort2(void)
{
    int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int right[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    
    mysort(a, 10, sizeof(a[0]), compare_dec);
    
    assert_array(a, right, 10, "test2");
}

void test_mysort3(void)
{
    int a[] = { 5, 2, 3, 7, 4, 1, 6, 9, 8, 0 };
    int right[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    mysort(a, 10, sizeof(a[0]), compare_inc);
    
    assert_array(a, right, 10, "test3");
}

void test_mysort(void)
{
    printf("Test mysort.c\n");
    test_mysort1();
    test_mysort2();
    test_mysort3();
    
    print_errors();
    printf("\n");
}

int main(void)
{
    test_key();
    test_mysort();

    return 0;
}
