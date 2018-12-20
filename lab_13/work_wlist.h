#ifndef __WORK_WLIST_H
#define __WORK_WLIST_H

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define TRUE 1

typedef struct statistic statistic;
typedef struct list_head list_head;
typedef struct summer_temp summer_temp;

struct statistic
{
    list_head list;
    int year;
    int month;
    int day;
    int max_temp;
    int min_temp;
};

struct summer_temp
{
    list_head list;
    int year;
    double temp;
};

statistic *input_list(FILE *file);
summer_temp *summer_stat(statistic *list);
void print_list_stat(statistic *list, FILE *stream);
void print_list_summer(summer_temp *list, FILE *stream);
void free_list_stat(statistic *list);
void free_list_summer(summer_temp *list);


#endif
