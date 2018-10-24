#include <stdio.h>
#include <stdlib.h>

#ifndef __MY_STRING_H
#define __MY_STRING_H

int len(char *string);

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

char* str_replace(const char *source, const char *serach, const char *replace);

#endif
