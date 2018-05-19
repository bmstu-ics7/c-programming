#include "assert.h"

int err_cnt = 0;

int assert(int expected, int recieved, char* test_name)
{
    if (expected == recieved)
    {
        printf(GREEN "%s success\n\n", test_name);
        return SUCCESS;
    }
    else
    {
        err_cnt++;

        printf(RED "%s failed:\n" 
                WHITE "expected: %d, recieved: %d\n", 
                test_name, expected, recieved);
        return WRONG;
    }
}

void print_errors()
{
    printf(WHITE "%d %s\n", err_cnt, err_cnt ? RED "FAILED" : GREEN "OK");
}
