#include <stdio.h>
#include <sys/types.h>

#ifndef MYSORT_H
#define MYSORT_H

int compare_inc(const void *p, const void *q);

int compare_dec(const void *p, const void *q);

void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));

#endif
