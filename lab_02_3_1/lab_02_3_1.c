/*
Нахождение НОД двух чисел
*/

#include<stdio.h>

// Функция нахождения минимума
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

//Функция нахождения НОД
int NOD(int a, int b)
{
    for (int i = min(a, b); i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
    return 1;
}

int main(void)
{
    int a, b, answer;
    printf("Input a and b: ");
    if (scanf("%d%d", &a, &b) != 2)
    {
        printf("Incorrect input!\n");
        return 0;
    }
    answer = NOD(a, b);
    printf("Nod: %d\n", answer);
    return 0;
}
