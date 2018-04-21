/*
 * Выбран тип int, Сортировка пузырьком по возрастанию
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define SUCCESS 0
#define ARG_ERROR -1
#define INPUT_ERROR -2
#define CLOSE_ERROR -3

#define COUNT_ARGS 2

#define TRUE 1

#define SIZE 4
#define COUNT 1

int get_number_by_pos(FILE* file, const int pos, int* num)
{
    fseek(file, pos * SIZE, SEEK_SET);
    fread(num, SIZE, COUNT, file);

    return SUCCESS;
}

int put_number_by_pos(FILE* file, const int pos, int* num)
{
    fseek(file, pos * SIZE, SEEK_SET);
    fwrite(num, SIZE, COUNT, file);

    return SUCCESS;
}

int sort_file(FILE* file)
{
    int num1, num2;
    int n;
    
    fseek(file, 0, SEEK_END);
    n = ftell(file) / SIZE;

    for (int i = 0; i < n ; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            get_number_by_pos(file, j, &num1);
            get_number_by_pos(file, j + 1, &num2);

            if (num1 > num2)
            {
                put_number_by_pos(file, j + 1, &num1);
                put_number_by_pos(file, j, &num2);
            }
        }

    return SUCCESS;
}

int generate_file(FILE* file, const int n)
{
    int num;

    for (int i = 0; i < n; i++)
    {
        num = rand() % 10 + 1;
        fwrite(&num, SIZE, COUNT, file);
    }

    return SUCCESS;
}

int print_file(FILE* file)
{
    int num;
    int n;
    
    fseek(file, 0, SEEK_END);
    n = ftell(file) / SIZE;

    for (int i = 0; i < n; i++)
    {
        get_number_by_pos(file, i, &num);
        printf("%d ", num);
    }
    printf("\n");

    return SUCCESS;
}

int main(int argc, char** argv)
{
    if (argc != COUNT_ARGS)
    {
        printf("Некорректные аргументы");
        return ARG_ERROR;
    }

    int n;
    if (scanf("%d", &n) != 1)
    {
        printf("Некорректный ввод!");
        return INPUT_ERROR;
    }

    FILE* file = NULL;
    file = fopen(argv[1], "w+b");

    if (file == NULL)
    {
        printf("%s", strerror(errno));
        return errno;
    }

    generate_file(file, n);
    printf("Сгенерированный файл: ");
    print_file(file);

    sort_file(file);
    printf("Отсортированный файл: ");
    print_file(file);

    if (fclose(file) == EOF)
        return CLOSE_ERROR;

    return SUCCESS;
}
