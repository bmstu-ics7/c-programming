#include <stdio.h>
#include <stdlib.h>

#ifndef KEY_H
#define KEY_H

#define SUCCESS 0
#define VOID_ARRAY -4
#define NULL_ARRAY -5

#define SIZE sizeof(int)

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif
