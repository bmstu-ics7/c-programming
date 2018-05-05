/*
 * Вставить в исходный массив после каждого элемента, кратного трем, 
 * очередное число Фибоначчи (первое число Фибоначчи равно 0, второе – 1).
*/
#include <stdio.h>
#include <math.h>

#define SUCCESS 0
#define VOID_SEQUENCE -1
#define NEGATIVE_ARG -2
#define POS_ERROR -3
#define MAX_FIB_ERROR -4

#define N 10
#define MAX_N 20

#define MAX_INT 2147483647

#define TRUE 1

#define FIRST_FIB 0
#define SECOND_FIB 1

#define MULTI 3

int input_array(int array[], int* count)
{
    int num;

    *count = 0;

    while(TRUE)
    {
        printf("Введите %d элемент: ", *count + 1);
        
        if (scanf("%d", &num) != 1)
            break;

        array[(*count)++] = num;

        if (*count == N)
            break;
    }

    if (*count == 0)
    {
        printf("Пустая последовательность!");
        return VOID_SEQUENCE;
    }

    return SUCCESS;
}

int print_array(const int array[], const int count)
{
    for (int i = 0; i < count; i++)
        printf("%d ", array[i]);

    printf("\n");

    return SUCCESS;
}

int fib(const int n)
{    
    int max_fib = (int)(log(MAX_INT * sqrt(5)) / log((1 + sqrt(5)) / 2));

    if (n > max_fib)
        return MAX_FIB_ERROR;

    if (n < 1)
        return NEGATIVE_ARG;

    if (n == 1)
        return FIRST_FIB;

    if (n == 2)
        return SECOND_FIB;

    int x1 = FIRST_FIB, x2 = SECOND_FIB;

    for (int i = 3; i <= n; i++)
    {
        int temp;
        temp = x2;
        x2 = x1 + x2;
        x1 = temp;
    }

    return x2;
}

int insert(int array[], int* const count, const int pos, const int num)
{
    if (pos > *count)
        return POS_ERROR;

    for (int i = *count; i > pos; i--)
    {
        int temp = array[i];
        array[i] = array[i - 1];
        array[i - 1] = array[i];
    }

    (*count)++;
    array[pos] = num;

    return SUCCESS;
}

int insert_fib(int array[], int* count)
{
    int num_fib = 1;

    for (int i = 0; i < *count; i++)
    {
        if (array[i] % MULTI == 0)
        {
            insert(array, count, ++i, fib(num_fib++));
        }
    }

    return SUCCESS;
}

int main()
{
    int array[MAX_N], count;

    if (input_array(array, &count) != SUCCESS)
        return VOID_SEQUENCE;

    insert_fib(array, &count);
    print_array(array, count);
    return SUCCESS;
}
