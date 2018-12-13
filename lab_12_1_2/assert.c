#include "assert.h"

int err_cnt = 0;

int assert(const int expected, const int recieved, const char *const test_name)
{
    if (expected == recieved)
    {
        printf(GREEN "%s success\n\n", test_name);
        printf(WHITE "");
        return SUCCESS;
    }
    else
    {
        err_cnt++;

        printf(RED "%s failed:\n" 
                WHITE "expected: %d, recieved: %d\n", test_name, expected, recieved);
        
        printf(WHITE "");
        return WRONG;
    }
}

int assert_array(const int *const expected, const int *const recieved, const int size, const char *const test_name)
{
    int count_right = 0;

    for (int i = 0; i < size; i++)
        if (expected[i] == recieved[i])
            count_right++;

    if (count_right == size)
    {
        printf(GREEN "%s success\n\n", test_name);
        printf(WHITE "");
        return SUCCESS;
    }
    else
    {
        err_cnt++;

        printf(RED "%s failed:\n"        
                WHITE "expected: ", test_name);

        for (int i = 0; i < size; i++)
            printf("%d ", expected[i]);

        printf("\nrecieved: ");

        for (int i = 0; i < size; i++)
            printf("%d ", recieved[i]);

        printf(WHITE "\n\n");
                
        return WRONG;
    }
}

void print_errors()
{
    printf(WHITE "%d %s\n", err_cnt, err_cnt ? RED "FAILED" : GREEN "OK");
    printf(WHITE "\n");
}

