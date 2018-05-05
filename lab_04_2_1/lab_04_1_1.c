/*
 * Поместить в новый массив
 * элементы исходного массива, которые 
 * являются простыми числами
*/
#include <stdio.h>
#include <math.h>

#define SUCCESS 0
#define VOID_SEQUENCE -1

#define N 10
 
#define TRUE 1
#define FALSE 0

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

int print_array(const int array[], const int* const count)
{
    for (int i = 0; i < *count; i++)
        printf("%d ", array[i]);

    printf("\n");

    return SUCCESS;
}

int prime_number(const int num)
{
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return FALSE;

    return TRUE;
}

int prime_array(const int array[], const int* const count, int new_array[], int* new_count)
{
    *new_count = 0;

    for (int i = 0; i < *count; i++)
        if (prime_number(array[i]))
            new_array[(*new_count)++] = array[i];

    return SUCCESS;
}

int main(void)
{
    int array[N], count = 0;
    int new_array[N], new_count = 0;

    if (input_array(array, &count) != SUCCESS)
        return VOID_SEQUENCE;
    
    prime_array(array, &count, new_array, &new_count);

    if (new_count == 0)
        printf("Во введенной последовательности нет простых чисел!");
    else
        print_array(new_array, &new_count);
    
    return SUCCESS;
}
