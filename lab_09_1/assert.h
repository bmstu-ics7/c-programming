#include <stdio.h>
#include <math.h>

#ifndef ASSERT_H
#define ASSERT_H

#define SUCCESS 0
#define WRONG -1

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define WHITE   "\x1b[0m"

int assert(const int expected, const int recieved, const char *const test_name);

int assert_array(const int *const expected, const int *const recieved, const int size, const char *const test_name);

int assert_matrix(double **expected, double **recieved, const int n, const int m, const char *const test_name);

int assert_string(char const *const expected, char const *const recieved, const char *const test_name);

void print_errors(const char *const test_name);

#endif

