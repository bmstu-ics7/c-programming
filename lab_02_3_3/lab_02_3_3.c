/*
 * Программа вычисляет ряд arctg и подсчитывает ошибку.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SUCCESS 0
#define INPUT_ERROR 1

double f(double x, double eps)
{
    double t1 = 0, t2 = eps, sum = 0;
    int a = 1, k = 1;
    while (fabs(t1 - t2) >= eps)
    {
        t2 = t1;
        t1 = x / a;
        sum += k * t1;
        x *= x * x;
        k *= -1;
        a += 2;
    }
    
    return sum;
}

int main(void)
{
    double x, eps;
    printf("x: ");
    if (scanf("%lf", &x) != 1)
    {
        printf("Некорректный ввод!\n");
        return INPUT_ERROR;
    }
    printf("eps: ");
    if (scanf("%lf", &eps) != 1)
    {
        printf("Некорректный ввод!\n");
        return INPUT_ERROR;
    }
    
    double sum = f(x, eps);
    double arc = atan(x);
    printf("Sum = %-8.5lf\nOtv = %-8.5lf\nAbsolute = %-8.5lf\nRelative = %-8.5lf\n",
           sum, arc, fabs(sum - arc), fabs((sum - arc) / arc));
    return SUCCESS;
}
