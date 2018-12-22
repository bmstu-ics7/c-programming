#include "weather.h"

weather_data *input_list(FILE *file)
{
    weather_data *data = malloc(sizeof(weather_data));
    INIT_LIST_HEAD(&data->list);

    while (TRUE)
    {
        weather_data *temp = malloc(sizeof(weather_data));

        fscanf(file, "%d %d %d %d %d", &temp->year, &temp->month, &temp->day, &temp->day_temp, &temp->night_temp);

        if (feof(file))
        {
            free(temp);
            break;
        }

        list_add_tail(&temp->list, &data->list);
    }

    return data;
}

void print_list(weather_data *list)
{
    weather_data *temp = NULL;
    list_head *it = NULL;

    list_for_each(it, &list->list)
    {
        temp = list_entry(it, weather_data, list);
        printf("%d %d %d %d %d\n", temp->year, temp->month, temp->day, temp->day_temp, temp->night_temp);
    }
}

diff *find(weather_data *list)
{
    diff *res = malloc(sizeof(diff));
    INIT_LIST_HEAD(&res->list);

    weather_data *temp = NULL;
    list_head *it = NULL;

    int hight = MIN_TEMP;
    int low = MAX_TEMP;
    int now_year = 0;

    list_for_each(it, &list->list)
    {
        temp = list_entry(it, weather_data, list);

        if (temp->year != now_year)
        {
            if (now_year != 0)
            {
                diff *el = malloc(sizeof(diff));
                el->year = now_year;
                el->data = hight - low;

                list_add_tail(&el->list, &res->list);
            }

            hight = MIN_TEMP;
            low = MAX_TEMP;
            now_year = temp->year;
        }

        if (hight < temp->day_temp)
            hight = temp->day_temp;

        if (low > temp->night_temp)
            low = temp->night_temp;
    }

    return res;
}

void print_list_res(diff *list)
{
    diff *temp = NULL;
    list_head *it = NULL;

    list_for_each(it, &list->list)
    {
        temp = list_entry(it, diff, list);
        printf("%d %d\n", temp->year, temp->data);
    }
}

void free_data(weather_data *list)
{
    weather_data *temp = NULL;
    list_head *it = NULL, *next = NULL;

    list_for_each_safe(it, next, &list->list)
    {
        temp = list_entry(it, weather_data, list);
        list_del(it);
        free (temp);
    }
}

void free_diff(diff *list)
{
    diff *temp = NULL;
    list_head *it = NULL, *next = NULL;

    list_for_each_safe(it, next, &list->list)
    {
        temp = list_entry(it, diff, list);
        list_del(it);
        free (temp);
    }
}

