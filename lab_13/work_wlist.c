#include "work_wlist.h"

/*
 * Считывает из файла данные и записывает в список statistic
 *
 * @param file [in]
 *
 * @return считанный список
 */

statistic *input_list(FILE *file)
{
    statistic *data = malloc(sizeof(statistic));
    INIT_LIST_HEAD(&data->list);

    while (TRUE)
    {
        statistic *temp = malloc(sizeof(statistic));

        fscanf(file, "%d %d %d %d %d", &temp->year, &temp->month, &temp->day, &temp->max_temp, &temp->min_temp);

        if (feof(file))
            break;

        list_add(&temp->list, &data->list);
    }

    return data;
}

/*
 * Считает среднюю температуру летом у каждого кода
 *
 * @param list [in]
 *
 * @return список собранной статистики
 */

summer_temp *summer_stat(statistic *list)
{
    summer_temp *data = malloc(sizeof(summer_temp));
    INIT_LIST_HEAD(&data->list);

    list_head *iterator = NULL;
    statistic *temp = NULL;
    summer_temp *el = NULL;

    int last_year = 0;
    double average = 0;
    int count = 0;

    list_for_each_prev(iterator, &list->list)
    {
        temp = list_entry(iterator, statistic, list);
        if (temp->month == 6 && last_year != temp->year)
        {
            last_year = temp->year;
            average = 0;
            count = 0;
        }

        if (temp->month >= 6 && temp->month <= 8)
        {
            average += (double)(temp->min_temp + temp->max_temp) / 2;
            count++;
        }

        if (temp->month > 8 && count != 0)
        {
            el = malloc(sizeof(summer_temp));
            el->year = temp->year;
            el->temp = average / count;

            list_add(&el->list, &data->list);

            count = 0;
            average = 0;
        }
    }

    return data;
}

/*
 * Выводит список статистики
 *
 * @param list [in]
 * @param stream [in]
 */

void print_list_stat(statistic *list, FILE *stream)
{
    statistic *temp = NULL;
    list_head *iterator = NULL;

    list_for_each_prev(iterator, &list->list)
    {
        temp = list_entry(iterator, statistic, list);
        fprintf(stream, "%d %d %d %d %d\n", temp->year, temp->month, temp->day, temp->max_temp, temp->min_temp);
    }
}

/*
 * Выводит список средней температуры летом за год
 *
 * @param list [in]
 * @param stream [in]
 */

void print_list_summer(summer_temp *list, FILE *stream)
{
    summer_temp *temp = NULL;
    list_head *iterator = NULL;

    list_for_each_prev(iterator, &list->list)
    {
        temp = list_entry(iterator, summer_temp, list);
        fprintf(stream, "%d %f\n", temp->year, temp->temp);
    }
}

/*
 * Очищает лист статистики
 *
 * @param list [in]
 */

void free_list_stat(statistic *list)
{
    statistic *temp = NULL;
    list_head *iterator = NULL, *next = NULL;

    list_for_each_safe(iterator, next, &list->list)
    {
        temp = list_entry(iterator, statistic, list);
        list_del(iterator);
        free (temp);
    }
}

/*
 * Очищает лист летней температуры
 *
 * @param list [in]
 */

void free_list_summer(summer_temp *list)
{
    summer_temp *temp = NULL;
    list_head *iterator = NULL, *next = NULL;

    list_for_each_safe(iterator, next, &list->list)
    {
        temp = list_entry(iterator, summer_temp, list);
        list_del(iterator);
        free (temp);
    }
}

