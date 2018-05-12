#include <stdio.h>
#include "read_error.h"

int read_error(int err)
{
    switch(err)
    {
        case VOID_FILE:
            printf("Файл пустой!");
            return VOID_FILE;

        case INCORRECT_FILE:
            printf("Некорректный файл!");
            return INCORRECT_FILE;

        default:
            return SUCCESS;
    }
}

