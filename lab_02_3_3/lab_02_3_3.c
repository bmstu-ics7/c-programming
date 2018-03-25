/*
Программа вычисляет ряд arctg и подсчитывает ошибку.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
    scanf("%lf", &x);
    printf("eps: ");
    scanf("%lf", &eps);

    double sum = f(x, eps);

    double arc = atan(x);
    printf("Sum = %-8.5lf\nOtv = %-8.5lf\nAbsolute = %-8.5lf\nRelative = %-8.5lf\n",
           sum, arc, fabs(sum - arc), fabs((sum - arc) / arc));
    return 0;
}
