/*
 * Программа определяет сколько раз в последовательности
 * чисел меняется знак (нуль считается положительным числом).
*/
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define SUCCESS 0
#define INPUT_ERROR -1
#define CLOSE_ERROR -2

#define TRUE 1

// Функция для нахождения количества смены знаков
int process(FILE* file, int* count)
{
    int x1, x0;
    printf("Введите последовательность:\n");
    if (scanf("%d", &x1) != 1)
    {
        printf("Пустая последовательность!\n");
        return INPUT_ERROR;
    }

    while (TRUE)
    {
        x0 = x1;

        if (scanf("%d", &x1) != 1)
            break;

        if ((x0 < 0 && x1 >= 0) || (x0 >= 0 && x1 < 0))
            (*count)++;
    }

    fprintf(file, "%d\n", *count);
    return SUCCESS;
}

int main(void)
{
    int count = 0;
    FILE* file = NULL;
    file = fopen("out.txt", "w");

    if (file == NULL)
    {
        printf("%s", strerror(errno));
        return errno;
    }

    if (process(file, &count) == INPUT_ERROR)
        return INPUT_ERROR;

    if (fclose(file) == EOF)
        return CLOSE_ERROR;

    printf("%d\n", count);

    return SUCCESS;
}
