/* 
 * Даны основания и высота равнобедренной трапеции. Найти периметр трапеции.
*/

#include<stdio.h>
#include<math.h>

#define TWO 2

int main(void)
{
  float a, b, h;
  printf("Введите основания: ");
  //Проверка на ввод
  if (scanf("%f%f", &a, &b) != 2)
  {
    printf("Некорректный ввод!\n");
    return 0;
  }
  printf("Введите высоту: ");
  if (scanf("%f", &h) != 1)
  {
    printf("Некорректный ввод!\n");
    return 0;
  }

  if (a > 0 && b > 0 && h > 0)
  {
    float per;
    per = a + b + TWO * sqrt(h * h + fabsf(a - b) * fabsf(a - b));
    printf("Периметр: %8.3f\n", per);
  }
  else
  {
    printf("Некорректный ввод!\n");
  }
  return 0;
}
