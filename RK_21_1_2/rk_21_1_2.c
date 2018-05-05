/* 
 * Задание 2. Вариант 1.
 * Дана последовательность, заканчивающаяся 0.
 * Определить числа, являющиеся числами Фибоначчи.
 * Вывести максимальное.
*/
#include <stdio.h>

#define N 5000
#define SUCCESS 0
#define INPUT_ERROR -1

int fib(int a)
{
    int x1 = 1, x2 = 1;

    while (x1 < a)
    {
	int temp = x1;
	x1 = x1 + x2;
	x2 = temp;
    }

    return a == x1;
}

int main(void)
{
    int a = 1;
    int arr[N];
    int n = 0;
    printf("Введите последовательность, заканчивающююся 0: ");

    while (1)
    {
	if (scanf("%d", &a) != 1)
	{
            printf("Некорректный ввод!");
	    return INPUT_ERROR;
	}
	if (a == 0)
	    break;
	    arr[n] = a;
	    n++;
    }

    int num_fib[N];
    int n_fib = 0;

    for (int i =0; i < n; i++)
        if (fib(arr[i]))
        {
            num_fib[n_fib] = arr[i];
            n_fib++;
        }
	
    int max_fib = 0;
    for (int i = 0; i < n_fib; i++)
    {
	if (max_fib < num_fib[i])
	max_fib = num_fib[i];
    }

    printf("\n");

    for (int i = 0; i < n_fib; i++)
    	printf("%d ", num_fib[i]);

    printf("\n%d", max_fib);

    return SUCCESS;
}
