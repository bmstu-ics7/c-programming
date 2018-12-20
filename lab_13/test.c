#include "work_wlist.h"

int main(void)
{
    FILE *file = fopen("test.txt", "r");
    statistic *list = input_list(file);

    FILE *test_file = fopen("result_test.out", "w");
    summer_temp *test = summer_stat(list);

    print_list_summer(test, test_file);

    free_list_stat(list);
    free_list_summer(test);
    fclose(file);
    fclose(test_file);

    return 0;
}
