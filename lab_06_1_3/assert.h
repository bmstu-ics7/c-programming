#include <stdio.h>

#ifndef ASSERT_H
#define ASSERT_H

#define SUCCESS 0
#define WRONG -1

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define WHITE   "\x1b[0m"

extern int err_cnt;

int assert(int expected, int recieved, char* test_name);

void print_errors();

#endif 
