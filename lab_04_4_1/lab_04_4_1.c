/*
 * Сортировка вставками.
*/
#include <stdio.h>

#define SUCCESS 0
#define VOID_SEQUENCE -1

#define TRUE 1

#define N 10

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

int sort(int array[], const int count)
{
    int now;

    for (int i = 1; i < count; i++) 
    { 
        now = array[i];
        
        for (int j = i - 1; j >= -1; j--)
            if (now < array[j] && j >= 0)
            {
                array[j + 1] = array[j];
            }
            else
            {
                array[j + 1] = now;
                break;
            }
    }

    return SUCCESS;
}

int main(void)
{
    int array[N], count = 0;

    if (input_array(array, &count) != SUCCESS)
        return VOID_SEQUENCE;

    sort(array, count);
    print_array(array, count);
    return SUCCESS;
}
