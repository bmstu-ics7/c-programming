#ifndef __MY_SNPRINTF_H
#define __MY_SNPRINTF_H

#include <stdio.h>
#include <sys/types.h>
#include <stdarg.h>
#include <stdlib.h>

#define SIZE 20

#define ERROR -1

int my_snprintf(char *restrict str, size_t size, const char *restrict format, ...);

#endif

