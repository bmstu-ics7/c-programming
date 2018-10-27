#include "my_strpbrk.h"

int len(char *string)
{
    int n = 0;
    while (string[n++] != '\0');
    return n - 1;
}

char *my_strpbrk(const char *string1, const char *string2)
{
    char *ptr = (char*)string1;

    while (*ptr != '\0')
    {
        for (int i = 0; i < len((char*)string2); i++)
            if (*ptr == string2[i])
                return ptr;

        ptr++;
    }

    return NULL;
}

