#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_strpbrk.h"
#include "tick.h"

int main(int argc, char **argv)
{
    FILE *file = fopen("graph.txt", "w");

    for (int i = 0; i <= atoi(argv[1]); i += atoi(argv[2]))
    {
        char *my_str = malloc(i);
        char *str = malloc(i);

        char *my_find = malloc(i);
        char *find = malloc(i);

        for (int j = 0; j < i; j++)
        {
            my_str[j] = 'a';
            str[j] = 'a';

            my_find[j] = 'c';
            find[j] = 'c';

            if (j == i - 1)
            {
                my_str[j] = 'b';
                str[j] = 'b';

                find[j] = 'b';
                my_find[j] = 'b';
            }
        }

        unsigned long long my_start = tick();
        my_strpbrk(my_str, my_find);
        unsigned long long my_finish = tick();

        unsigned long long start = tick();
        my_strpbrk(str, find);
        unsigned long long finish = tick();

        fprintf(file, "%d %llu %llu\n", i, my_finish - my_start, finish - start);

        free(my_str);
        free(str);

        free(my_find);
        free(find);
    }

    fclose(file);

    return 0;
}
