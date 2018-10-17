#include <stdio.h>

#include "work_memory.h"
#include "assert.h"
#include "sum_matrix.h"
#include "deg_matrix.h"
#include "operation.h"
/*
void generate_matrix(double **matrix, int n, int m, double *el)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = el[i * n + j];
}

void test1_sum(void)
{
    double **right;
    right = allocate_matrix(3, 3);
    double r_arr[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    generate_matrix(right, 3, 3, r_arr);

    double **a = allocate_matrix(3, 3);
    double a_arr[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    generate_matrix(a, 3, 3, a_arr);

    double **b = allocate_matrix(3, 3);
    generate_matrix(b, 3, 3, a_arr);

    int n, m;
    double **answ = sum_matrix(a, 3, 3, b, 3, 3, &n, &m);

    assert_matrix(right, answ, n, m, "test sum #1");

    free_matrix(answ);
    free_matrix(right);
    free_matrix(a);
    free_matrix(b);
}

void test2_sum(void)
{
    double **right;
    right = allocate_matrix(3, 3);
    double r_arr[] = { 9, 9, 9, 9, 9, 9, 9, 9 ,9 };
    generate_matrix(right, 3, 3, r_arr);

    double **a = allocate_matrix(3, 3);
    double a_arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    generate_matrix(a, 3, 3, a_arr);

    double **b = allocate_matrix(3, 3);
    double b_arr[] = { 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    generate_matrix(b, 3, 3, b_arr);

    int n, m;
    double **answ = sum_matrix(a, 3, 3, b, 3, 3, &n, &m);

    assert_matrix(right, answ, n, m, "test sum #2");

    free_matrix(answ);
    free_matrix(right);
    free_matrix(a);
    free_matrix(b);
}

void test3_sum(void)
{
    double **right;
    right = allocate_matrix(3, 3);
    double r_arr[] = { 7, 7, 7, 7, 7, 7, 7, 7, 7 };
    generate_matrix(right, 3, 3, r_arr);

    double **a = allocate_matrix(3, 3);
    double a_arr[] = { 6, 6, 6, 4, 4, 4, 2, 2, 2 };
    generate_matrix(a, 3, 3, a_arr);

    double **b = allocate_matrix(3, 3);
    double b_arr[] = { 1, 1, 1, 3, 3, 3, 5, 5, 5 };
    generate_matrix(b, 3, 3, b_arr);

    int n, m;
    double **answ = sum_matrix(a, 3, 3, b, 3, 3, &n, &m);

    assert_matrix(right, answ, n, m, "test sum #3");

    free_matrix(answ);
    free_matrix(right);
    free_matrix(a);
    free_matrix(b);
}

void test_sum(void)
{
    test1_sum();
    test2_sum();
    test3_sum();

    print_errors("test_sum");
}

void test1_deg(void)
{
    double **right;
    right = allocate_matrix(2, 2);
    double r_arr[] = { 7, 10, 15, 22 };
    generate_matrix(right, 2, 2, r_arr);

    double **a = allocate_matrix(2, 2);
    double a_arr[] = { 1, 2, 3, 4 };
    generate_matrix(a, 2, 2, a_arr);

    double **b = allocate_matrix(2, 2);
    generate_matrix(b, 2, 2, a_arr);

    int n, m;
    double **answ = deg_matrix(a, 2, 2, b, 2, 2, &n, &m);

    assert_matrix(right, answ, n, m, "test deg #1");

    free_matrix(answ);
    free_matrix(right);
    free_matrix(a);
    free_matrix(b);
}

void test2_deg(void)
{
    double **right;
    right = allocate_matrix(2, 2);
    double r_arr[] = { 50, 50, 50, 50 };
    generate_matrix(right, 2, 2, r_arr);

    double **a = allocate_matrix(2, 2);
    double a_arr[] = { 5, 5, 5, 5 };
    generate_matrix(a, 2, 2, a_arr);

    double **b = allocate_matrix(2, 2);
    double b_arr[] = { 5, 5, 5, 5 };
    generate_matrix(b, 2, 2, b_arr);

    int n, m;
    double **answ = deg_matrix(a, 2, 2, b, 2, 2, &n, &m);

    assert_matrix(right, answ, n, m, "test deg #2");

    free_matrix(answ);
    free_matrix(right);
    free_matrix(a);
    free_matrix(b);
}

void test3_deg(void)
{
    double **right;
    right = allocate_matrix(2, 2);
    double r_arr[] = { 8, 5, 20, 13 };
    generate_matrix(right, 2, 2, r_arr);

    double **a = allocate_matrix(2, 2);
    double a_arr[] = { 1, 2, 3, 4 };
    generate_matrix(a, 2, 2, a_arr);

    double **b = allocate_matrix(2, 2);
    double b_arr[] = { 4, 3, 2, 1 };
    generate_matrix(b, 2, 2, b_arr);

    int n, m;
    double **answ = deg_matrix(a, 2, 2, b, 2, 2, &n, &m);

    assert_matrix(right, answ, n, m, "test deg #3");

    free_matrix(answ);
    free_matrix(right);
    free_matrix(a);
    free_matrix(b);
}

void test_deg(void)
{
    test1_deg();
    test2_deg();
    test3_deg();

    print_errors("test_deg");
}

void test1_operation(void)
{
    double **right;
    right = allocate_matrix(2, 2);
    double r_arr[] = { -2, 1, 1.5, -0.5 };
    generate_matrix(right, 2, 2, r_arr);

    double **a = allocate_matrix(2, 2);
    double a_arr[] = { 1, 2, 3, 4 };
    generate_matrix(a, 2, 2, a_arr);

    int n, m;
    double **answ = operation(a, 2, 2, &n, &m);

    assert_matrix(right, answ, n, m, "test operation #1");

    free_matrix(answ);
    free_matrix(right);
    free_matrix(a);
}

void test2_operation(void)
{
    double **right;
    right = allocate_matrix(2, 2);
    double r_arr[] = { -0.875, 0.375, 0.625, -0.125 };
    generate_matrix(right, 2, 2, r_arr);

    double **a = allocate_matrix(2, 2);
    double a_arr[] = { 1, 3, 5, 7 };
    generate_matrix(a, 2, 2, a_arr);

    int n, m;
    double **answ = operation(a, 2, 2, &n, &m);

    assert_matrix(right, answ, n, m, "test operation #2");

    free_matrix(answ);
    free_matrix(right);
    free_matrix(a);
}

void test3_operation(void)
{
    double **right;
    right = allocate_matrix(2, 2);
    double r_arr[] = { 1, -0.5, -2, 1.25 };
    generate_matrix(right, 2, 2, r_arr);

    double **a = allocate_matrix(2, 2);
    double a_arr[] = { 5, 2, 8, 4 };
    generate_matrix(a, 2, 2, a_arr);

    int n, m;
    double **answ = operation(a, 2, 2, &n, &m);

    assert_matrix(right, answ, n, m, "test operation #3");

    free_matrix(answ);
    free_matrix(right);
    free_matrix(a);
}

void test_operation(void)
{
    test1_operation();
    test2_operation();
    test3_operation();

    print_errors("test_operation");
}
*/
int main(void)
{
    //test_sum();
    //test_deg();
    //test_operation();
    /*
    test1_sum();
    test2_sum();
    test3_sum();
    print_errors("test_sum");

    test1_deg();
    test2_deg();
    test3_deg();
    print_errors("test_deg");

    test1_operation();
    test2_operation();
    test3_operation();
    print_errors("test_operation");
*/
    printf("kek\n");
    return SUCCESS;
}
