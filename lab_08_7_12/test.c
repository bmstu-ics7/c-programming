#include <stdio.h>
#include <stdlib.h>

#include "assert.h"

double **allocate_matrix(int n, int m)
{
    double **pointers, *data;
    
    pointers = malloc(n * sizeof(pointers[0]));
    
    if (pointers == NULL)
        return NULL;
    
    data = malloc(n * m * sizeof(data[0]));
    
    if (data == NULL)
    {
        free(pointers);

        return NULL;
    }
    
    for (int i = 0; i < n; i++)
        pointers[i] = data + i * m;
        
    return pointers;
}

void free_matrix(double **matrix)
{
    free(matrix[0]);
    
    free(matrix);
}

double **sum_matrix(double **mat1, const int n1, const int m1, double **mat2, const int n2, const int m2, int *n, int *m)
{
    if (n1 != n2 || m1 != m2)
        return NULL;
    
    double **mat = allocate_matrix(n1, m1);
    
    if (mat == NULL)
        return NULL;
    
    *n = n1;
    *m = m1;
    
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++)
            mat[i][j] = mat1[i][j] + mat2[i][j];
            
    return mat;
}

double **deg_matrix(double **mat1, const int n1, const int m1, double **mat2, const int n2, const int m2, int *n, int *m)
{
    if (m1 != n2)
        return NULL;
    
    double **mat = allocate_matrix(n1, m2);
    
    if (mat == NULL)
        return NULL;
    
    *n = n1;
    *m = m2;
    
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m2; j++)
        {
            mat[i][j] = 0;
            
            for (int k = 0; k < m1; k++)
                mat[i][j] += mat1[i][k] * mat2[k][j];
        }
    
    return mat;
}

double **operation(double **matrix, int n, int m, int *nr, int *mr)
{
    if (n != m)
        return NULL;
    
    int size = n;
    double **ed = allocate_matrix(size, size);


    if (ed == NULL)
        return NULL;
    
    *nr = size;
    *mr = size;
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            ed[i][j] = i == j ? 1 : 0;
            
    for (int row = 0; row < size; row++)
    {
        if (fabs(matrix[row][row]) < 1e-8)
        {
            int change = 0;
            
            for (int i = row + 1; i < size; i++)
            {
                if (fabs(matrix[i][row]) > 1e-8)
                {
                    for (int j = 0; j < size; j++)
                    {
                        double temp;
                        
                        temp = matrix[row][j];
                        matrix[row][j] = matrix[i][j];
                        matrix[i][j] = temp;
                        
                        temp = ed[row][j];
                        ed[row][j] = ed[i][j];
                        ed[i][j] = temp;
                    }
                    
                    change = 1;
                    break;
                }
            }
            
            if (!change)
            {
                free_matrix(ed);
                return NULL;
            }
        }
        
        double v = matrix[row][row];
        
        for (int j = 0; j < size; j++)
        {
            matrix[row][j] /= v;
            ed[row][j] /= v;
        }
        
        for (int i = row + 1; i < size; i++)
        {
            double v = matrix[i][row];
            
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] -= v * matrix[row][j];
                ed[i][j] -= v * ed[row][j];
            }
        }
    }
    
    for (int row = size - 1; row > 0; row--)
    {
        for (int i = row - 1; i >= 0; i--)
        {
            double v = matrix[i][row];
            
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] -= v * matrix[row][j];
                ed[i][j] -= v * ed[row][j];
            }
        }
    }
    
    return ed;
}

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

void test4_sum(void)
{
    double **a = allocate_matrix(2, 2);
    double a_arr[] = { 6, 6, 6, 4 };
    generate_matrix(a, 2, 2, a_arr);

    double **b = allocate_matrix(3, 3);
    double b_arr[] = { 1, 1, 1, 3, 3, 3, 5, 5, 5 };
    generate_matrix(b, 3, 3, b_arr);

    int n, m;
    double **answ = sum_matrix(a, 2, 2, b, 3, 3, &n, &m);

    assert_matrix(NULL, answ, n, m, "test sum #4");

    free_matrix(a);
    free_matrix(b);
}

void test_sum(void)
{
    test1_sum();
    test2_sum();
    test3_sum();
    test4_sum();

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

void test4_deg(void)
{
    double **a = allocate_matrix(3, 3);
    double a_arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    generate_matrix(a, 2, 2, a_arr);

    double **b = allocate_matrix(2, 2);
    double b_arr[] = { 4, 3, 2, 1 };
    generate_matrix(b, 2, 2, b_arr);

    int n, m;
    double **answ = deg_matrix(a, 3, 3, b, 2, 2, &n, &m);

    assert_matrix(NULL, answ, n, m, "test deg #4");

    free_matrix(a);
    free_matrix(b);
}

void test_deg(void)
{
    test1_deg();
    test2_deg();
    test3_deg();
    test4_deg();

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

void test4_operation(void)
{
    double **a = allocate_matrix(2, 3);
    double a_arr[] = { 5, 2, 8, 4 , 3, 4 };
    generate_matrix(a, 2, 3, a_arr);

    int n, m;
    double **answ = operation(a, 2, 3, &n, &m);

    assert_matrix(NULL, answ, 1, 1, "test operation #4");

    free_matrix(a);
}

void test5_operation(void)
{
    double **right;
    right = allocate_matrix(3, 3);
    double r_arr[] = { -0.5, -0.3333333333333333, 0.3333333333333, 1, -2, 1, -0.5, 2, -1 };
    generate_matrix(right, 3, 3, r_arr);

    double **a = allocate_matrix(3, 3);
    double a_arr[] = { 0, 2, 2, 3, 4, 5, 6, 7, 8 };
    generate_matrix(a, 3, 3, a_arr);

    int n, m;
    double **answ = operation(a, 3, 3, &n, &m);

    assert_matrix(right, answ, n, m, "test operation #5");

    free_matrix(answ);
    free_matrix(right);
    free_matrix(a);
}

void test6_operation(void)
{
    double **a = allocate_matrix(3, 3);
    double a_arr[] = { 0, 2, 3, 0, 4, 6, 0, 9, 0 };
    generate_matrix(a, 3, 3, a_arr);

    int n, m;
    double **answ = operation(a, 3, 3, &n, &m);

    assert_matrix(NULL, answ, n, m, "test operation #6");

    free_matrix(a);
}

void test_operation(void)
{
    test1_operation();
    test2_operation();
    test3_operation();
    test4_operation();
    test5_operation();
    test6_operation();

    print_errors("test_operation");
}

int main(void)
{
    test_sum();
    test_deg();
    test_operation();

    //allocate_matrix(-1, -1);
    //allocate_matrix(1, -1);

    return SUCCESS;
}
