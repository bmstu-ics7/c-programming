#include "assert.h"

int assert(int expected, int recieved, char* test_name)
{
    if (expected == recieved)
    {
        printf(GREEN "%s success\n\n", test_name);
        return SUCCESS;
    }
    else
    {
        printf(RED "%s failed:\n" 
                WHITE "expected: %d, recieved: %d\n", 
                test_name, expected, recieved);
        return WRONG;
    }
}
