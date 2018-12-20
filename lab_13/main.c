#include <stdio.h>
#include <stdlib.h>

#include "work_wlist.h"

#define SUCCESS 0

void print_graph(char *str)
{
    FILE *file = fopen(str, "r");
    statistic *list = input_list(file);

    char *str_out = malloc(8);
    for (int i = 0; i < 3; i++)
        str_out[i] = str[i];

    str_out[3] = '.';
    str_out[4] = 'o';
    str_out[5] = 'u';
    str_out[6] = 't';
    str_out[7] = '\0';

    FILE *out = fopen(str_out, "w");
    summer_temp *res = summer_stat(list);
    print_list_summer(res, out);

    free_list_stat(list);
    free_list_summer(res);
    free(str_out);
    fclose(file);
    fclose(out);
}

int main(void)
{
    print_graph("EKB.csv");
    print_graph("SPB.csv");
    print_graph("STC.csv");

    return SUCCESS;
}
