#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "weather.h"

#define SUCCESS 0
#define ARG_ERR -1

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "%s\n", "Icorrect arguments!");
        return ARG_ERR;
    }

    if (argv[1][0] != '-' || argv[1][1] != 'i')
    {
        fprintf(stderr, "%s\n", "Icorrect arguments!");
        return ARG_ERR;
    }

    FILE *file = NULL;
    file = fopen(argv[2], "r");

    if (file == NULL)
    {
        fprintf(stderr, "%s\n", strerror(errno));
        return errno;
    }

    weather_data *list = input_list(file);
    diff *res = find(list);
    print_list_res(res);

    fclose(file);
    free_data(list);
    free_diff(res);
    return SUCCESS;
}
