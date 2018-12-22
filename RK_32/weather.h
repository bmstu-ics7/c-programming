#ifndef __WEATHER_H
#define __WEATHER_H

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define TRUE 1

#define MIN_TEMP -1000
#define MAX_TEMP 1000

typedef struct weather_data weather_data;
typedef struct list_head list_head;
typedef struct diff diff;

struct weather_data
{
    list_head list;

    int year;
    int month;
    int day;
    int day_temp;
    int night_temp;
};

struct diff
{
    list_head list;

    int year;
    int data;
};

weather_data *input_list(FILE *file);
void print_list(weather_data *list);
diff *find(weather_data *list);
void print_list_res(diff *list);
void free_data(weather_data *list);
void free_diff(diff *list);

#endif
