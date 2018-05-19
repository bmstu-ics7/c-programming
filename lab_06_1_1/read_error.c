#include <stdio.h>

#define SUCCESS 0
#define VOID_FILE -3
#define INCORRECT_FILE -4


int read_error(err)
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

