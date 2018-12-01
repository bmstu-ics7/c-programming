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
    int distribution[256] = { 0 };

    int len1 = len((char*)string1);
    int len2 = len((char*)string2);

    for (int i = 0; i < len2; i++)
        distribution[(int)string2[i]] = 1;

    for (int i = 0; i < len1; i++)
        if (distribution[(int)string1[i]])
            return (char*)string1 + i;

    return NULL;
}

