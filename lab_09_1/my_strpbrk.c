#include "my_strpbrk.h"

char *my_strpbrk(const char *string1, const char *string2)
{
    char *ptr = (char*)string1;
    int i = 0;

    while (*ptr != '\0')
    {
        if (*ptr == string2[i])
        {
            i++;

            if (string2[i] == '\0')
                return ptr - i + 1;
        }
        else
            i = 0;

        ptr++;
    }

    return NULL;
}

