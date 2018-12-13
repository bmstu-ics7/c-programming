#ifndef __LAB_07_H
#define __LAB_07_H

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

#define SUCCESS 0
#define VOID_FILE -1
#define INCORRECT_FILE -2
#define VOID_ARRAY -4
#define NULL_ARRAY -5

#define SIZE sizeof(int)

int input_array(FILE* file, int **array, int *n);

int key(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst);

int compare_inc(const void *p, const void *q);

int compare_dec(const void *p, const void *q);

void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));

void print_array(FILE* file, const int *const pa, const int *const pb);

#endif
