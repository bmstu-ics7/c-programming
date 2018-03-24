// Даны основания и высота равнобедренной трапеции. Найти периметр трапеции.

#include<stdio.h>
#include<math.h>

#define TWO 2

int main(void)
{
  float a, b, h;

  printf("Введите длины оснований через пробел: ");
  scanf("%f %f", &a, &b);

  printf("Введите высоту: ");
  scanf("%f", &h);

  if (a > 0 && b > 0 && h > 0)
  {
    float p;
    p = a + b + TWO * sqrt(h * h + fabsf(a - b) * fabsf(a - b));
    printf("Периметр: %f\n", p);
  }
  else
  {
    printf("Некорректный ввод!\n");
  }
  return 0;
}
