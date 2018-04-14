/*
 * По введенным прямой и точке программа определяет
 * нахождение точки относительно прямой
*/

#include<stdio.h>

#define SUCCESS 0
#define INPUT_ERROR 1

//Функция для нахождения положения точки
void where(int x1, int y1, int x2, int y2, int x, int y)
{
    float a, b;
    if (x1 != x2)
    {
        a = (y1 - y2) / (x1 - x2);
        b = y2 - a * x2;

        if (y > a * x + b)
            printf("Точка находится выше прямой\n");
        else if (y < a * x + b)
            printf("Точка находится ниже прямой\n");
        else
            printf("Точка находится на прямой\n");
    }
    else
    {
        if (x > x1)
            printf("Точка находится справа от прямой(прямая перпендикулярна OX)\n");
        else if (x < x1)
            printf("Точка находится слева от прямой(прямая перпендикулярна OX)\n");
        else
            printf("Точка находится на прямой\n");
    }
}

int main(void)
{
    int x1, x2, y1, y2, x, y;

    printf("Первая точка прямой: ");
    if (scanf("%d%d", &x1, &y1) != 2)
    {
        printf("Некорректный ввод!\n");
        return INPUT_ERROR;
    }

    printf("Вторая точка прямой: ");
    if (scanf("%d%d", &x2, &y2) != 2)
    {
        printf("Некорректный ввод!\n");
        return INPUT_ERROR;
    }

    if (x1 == x2 && y1 == y2)
    {
        printf("Введены две одинаковые точки\n");
        return INPUT_ERROR;
    }

    printf("Точка: ");    
    if (scanf("%d%d", &x, &y) != 2)
    {
        printf("Некорректный ввод!\n");
        return INPUT_ERROR;
    }

    where(x1, y1, x2, y2, x, y);
    return SUCCESS;
}
