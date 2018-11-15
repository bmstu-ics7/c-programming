#ifndef __MY_STRING_H
#define __MY_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define GETLINE_ERROR -1
#define LEN_ERROR -2

#define SIZE_BUF 128

int len(char *string);

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

char *str_replace(const char *source, const char *serach, const char *replace);

void free_string(char *str);

#endif
