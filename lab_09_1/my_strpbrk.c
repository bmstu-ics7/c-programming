#include "my_strpbrk.h"

/*
 * Находит длину строки
 *
 * @param string [in]
 *
 * @return длина строки
 */

int len(char *string)
{
    int n = 0;
    while (string[n++] != '\0');
    return n - 1;
}

/*
 * Находит первое вхождение символов из string2 в string1
 *
 * @param string1 [in]
 * @param string2 [in]
 *
 * @return Указатель на первое вхождение или NULL в случае его отсутствия
 */

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

