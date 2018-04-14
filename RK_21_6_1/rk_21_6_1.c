/* Задача 1. Вариант 5.
 * Дано натуральное число. 
 * Установить, является ли последовательность его цифр при просмотре
 * их слева направо упорядоченной по возрастанию. 
*/
#include <stdlib.h>

#define N 10
#define SUCCESS 0
#define INPUT_ERROR -1

int main(void)
{
  int num;
  if (scanf("%d", &num) != 1)
  {
    printf("Некорректный ввод!");
    return INPUT_ERROR;
  }
  
  int arr[N];
  while (num)
  {

  }
  return SUCCESS;
}
