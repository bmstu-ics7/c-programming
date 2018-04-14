/*
 * Нахождение НОД двух чисел
*/

#include<stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define INPUT_ERROR 1
#define MIN_NOD 1

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
    a = abs(a);
    b = abs(b);
    for (int i = min(a, b); i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
    return MIN_NOD;
}

int main(void)
{
    int a, b, answer;
    printf("Input a and b: ");
    if (scanf("%d%d", &a, &b) != 2)
    {
        printf("Incorrect input!\n");
        return INPUT_ERROR;
    }
    
    answer = NOD(a, b);
    printf("Nod: %d\n", answer);
    return SUCCESS;
}
