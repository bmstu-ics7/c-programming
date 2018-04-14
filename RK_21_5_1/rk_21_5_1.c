/* Задача 1. Вариант 5.
 * Дано натуральное число. 
 * Установить, является ли последовательность его цифр при просмотре
 * их слева направо упорядоченной по возрастанию. 
*/
#include <stdio.h>

#define N 10
#define SUCCESS 0
#define INPUT_ERROR -1
#define TEN 10

int main(void)
{
  	int num;
	printf("Введите число: ");
	if (scanf("%d", &num) != 1)
  	{
    		printf("Некорректный ввод!");
    		return INPUT_ERROR;
  	}
  
  	int arr[N];
	int n = 0;
  	while (num)
  	{
		arr[n] = num % TEN;
		num /= TEN;
		n++;
  	}
	
	int flag = 1;
	for (int i = 0; i < n - 1; i++)
		if (arr[i] <= arr[i + 1])
		{
			flag = 0;
			break;
		}

	printf("%d", flag);
  	return SUCCESS;
}
