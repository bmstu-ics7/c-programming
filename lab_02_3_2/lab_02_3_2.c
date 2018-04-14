/*
 * По введенным прямой и точке программа определяет
 * нахождение точки относительно прямой
*/

#include<stdio.h>

#define SUCCESS 0
#define INPUT_ERROR -1

#define UP 1
#define DOWN 2
#define ON 3
#define LEFT 4
#define RIGHT 5

//Функция для нахождения положения точки
int where(int x1, int y1, int x2, int y2, int x, int y)
{
    float a, b;
    if (x1 != x2)
    {
        a = (y1 - y2) / (x1 - x2);
        b = y2 - a * x2;

        if (y > a * x + b)
            return UP;
        else if (y < a * x + b)
            return DOWN;
        else
            return ON;
    }
    else
    {
        if (x > x1)
            return RIGHT;
        else if (x < x1)
            return LEFT;
        else
            return ON;
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

    switch (where(x1, y1, x2, y2, x, y))
    {
        case UP: 
          printf("Точка находится выше прямой!");
          break;
        case DOWN:
          printf("Точка находится ниже прямой!");
          break;
        case RIGHT:
          printf("Точка находится справа от прямой!");
          break;
        case LEFT:
          printf("Точка находится слева от прямой!");
          break;
        case ON:
          printf("Точка находится на прямой!");
          break;
    }
    return SUCCESS;
}
