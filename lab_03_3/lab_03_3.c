/*
 * Выбран тип int, Сортировка пузырьком по возрастанию
*/
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define ARG_ERROR -1
#define INPUT_ERROR -2

#define COUNT_ARGS 2

#define ZERO 0
#define ONE 1

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

int sort_file(FILE* file, const int n)
{
    int num1, num2;

    for (int i = ZERO; i < n; i++)
        for (int j = ZERO; j < n - i - ONE; j++)
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

    for (int i = ZERO; i < n; i++)
    {
        num = rand() % 10 + 1;
        fwrite(&num, SIZE, COUNT, file);
    }

    return SUCCESS;
}

int print_file(FILE* file, const int n)
{
    int num;

    for (int i = ZERO; i < n; i++)
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

    generate_file(file, n);
    printf("Сгенерированный файл: ");
    print_file(file, n);

    sort_file(file, n);
    printf("Отсортированный файл: ");
    print_file(file, n);

    fclose(file);

    return SUCCESS;
}
