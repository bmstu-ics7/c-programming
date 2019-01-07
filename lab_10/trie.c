#include "trie.h"
#include <unistd.h>

/*
 * Создает префоксное дерево
 *
 * @return пустое префиксное дерево
 */

my_trie *trie_create()
{
    my_trie *trie = malloc(sizeof(my_trie));
    trie->data = NULL;
    trie->key = '\0';
    trie->is_real = FALSE;
    trie->leavs = NULL;

    return trie;
}

/*
 * Берет значение из префиксного дерева по ключу
 *
 * @param trie [in]
 * @param str_key [in]
 */

void *trie_get(my_trie *trie, char *str_key)
{
    for (int i = 0; ; i++)
    {
        if (str_key[i] == '\0')
        {
            if (trie->is_real)
                return trie->data;
            else
                return NULL;
        }

        node_t *temp;
        if (trie != NULL)
            temp = trie->leavs;
        else
            return NULL;

        for (;temp != NULL; temp = temp->next)
        {
            my_trie *root = temp->data;

            if (root->key == str_key[i])
            {
                trie = root;
                break;
            }
        }

        if (temp == NULL)
            return NULL;
    }
}

/*
 * Функция компарации для сортировки списка узлов по алфавиту
 *
 * @param data1 [in]
 * @param data2 [in]
 *
 * @return возвращает разницу между кодами символов
 */

int comparator(const void *data1, const void *data2)
{
    return ((my_trie*)data1)->key - ((my_trie*)data2)->key;
}

/*
 * Устанавливает значение ключу (в случае нового создает ключ)
 *
 * @param trie [out]
 * @param str_key [in]
 * @param data [in]
 */

void trie_set(my_trie *trie, char *str_key, void *data)
{
    for (int i = 0; ; i++)
    {
        if (str_key[i] == '\0')
        {
            trie->data = data;
            trie->is_real = TRUE;
            return;
        }

        node_t *temp = NULL;
        if (trie != NULL)
            temp = trie->leavs;
        else
        {
            my_trie *tmp = malloc(sizeof(my_trie));
            tmp->is_real = FALSE;
            tmp->key = str_key[i];
            tmp->data = NULL;
            tmp->leavs = NULL;
            node_t *node = malloc(sizeof(node_t));
            node->data = tmp;
            sorted_insert(&(trie->leavs), node, comparator);
            trie = tmp;
        }

        for (;temp != NULL; temp = temp->next)
        {
            my_trie *root = temp->data;

            if (root->key == str_key[i])
            {
                trie = root;
                break;
            }
        }

        if (temp == NULL)
        {
            my_trie *tmp = malloc(sizeof(my_trie));
            tmp->is_real = FALSE;
            tmp->key = str_key[i];
            tmp->data = NULL;
            tmp->leavs = NULL;
            node_t *node = malloc(sizeof(node_t));
            node->data = tmp;
            sorted_insert(&(trie->leavs), node, comparator);
            trie = tmp;
        }
    }
}

/*
 * Удаляет значение из ключа и делает ключ неактивным
 *
 * @param trie [out]
 * @param str_key [in]
 */

void trie_remove(my_trie *trie, char *str_key)
{
    for (int i = 0; ; i++)
    {
        if (str_key[i] == '\0')
        {
            if (trie->is_real)
            {
                trie->is_real = FALSE;
                return;
            }
            else
                return;
        }

        node_t *temp;
        if (trie != NULL)
            temp = trie->leavs;
        else
            return;

        for (;temp != NULL; temp = temp->next)
        {
            my_trie *root = temp->data;

            if (root->key == str_key[i])
            {
                trie = root;
                break;
            }
        }

        if (temp == NULL)
            return;
    }
}

void trie_search_keys_recursive(my_trie *trie, char *str, int index, char *now, int found, int len, FILE *stream);

/*
 * Ищет и выводит все ключи с данной подстрокой, вызывая рекурсивный алгоритм поиска
 *
 * @param trie [in]
 * @param str [in]
 */

void trie_search_keys(FILE *stream, my_trie *trie, char *str)
{
    char now[SIZE];
    trie_search_keys_recursive(trie, str, 0, now, 0, 0, stream);
}

/*
 * Рекурсивный алгоритм поиска
 *
 * @param trie [in]
 * @param str [in]
 * @param index [in]
 * @param now [in]
 * @param found [in]
 * @param len [in]
 */

void trie_search_keys_recursive(my_trie *trie, char *str, int index, char now[SIZE], int found, int len, FILE *stream)
{
    if (trie == NULL)
        return;

    if (!found && str[index] == trie->key)
        index++;
    else
        index = 0;

    if (str[index] == '\0')
        found = TRUE;

    if (trie->key != '\0')
        now[len++] = trie->key;

    now[len] = '\0';

    if (found && trie->is_real)
        fprintf(stream, "%s\n", now);

    for (node_t *temp = trie->leavs; temp != NULL; temp = temp->next)
        trie_search_keys_recursive((my_trie*)temp->data, str, index, now, found, len, stream);
}

void trie_print_recursive(my_trie *trie, int level, int end, int probels[SIZE]);
void trie_print_recursive_compress(my_trie *trie, int level, int end, int probels[SIZE], char out[BIG_SIZE][BIG_SIZE], int *io, int jo);

/*
 * Выводит дерево ключей в консоль
 *
 * @param trie[in]
 */

void trie_print(my_trie *trie)
{
    int probels[SIZE];
    trie_print_recursive(trie, 0, 0, probels);
}

/*
 * Выводит дерево ключей в консоль сжатым по вертикале образом
 *
 * @param trie[in]
 */

void trie_print_compress(my_trie *trie)
{
    int probels[SIZE];
    char out[BIG_SIZE][BIG_SIZE] = { { '\0' } };
    int io = 0;
    trie_print_recursive_compress(trie, 0, 0, probels, out, &io, 0);

    int move[BIG_SIZE][BIG_SIZE] = { { 0 } };

    int was = TRUE;
    while (was)
    {
        for (int i = 0; i < BIG_SIZE; i++)
            for (int j = 0; j < BIG_SIZE; j++)
                move[i][j] = 0;

        was = FALSE;

        for (int i = 1; out[i][0] != '\0'; i++)
        {
            for (int j = 0; out[i][j] != '\0'; j++)
            {
                if (out[i][j] == ' ')
                    continue;

                if (out[i - 1][j] == ' ' || out [i - 1][j] == '\0' || (out[i - 1][j] == '|' && (out[i - 1][j + 2] == ' ' || out[i - 1][j + 2] == '\0')))
                {
                    if (j > 0)
                    {
                        if (move[i][j - 1] != 0 || out[i][j - 1] == ' ')
                        {
                            move[i][j] = 1;
                        }
                    }
                    else
                    {
                        move[i][j] = 1;
                    }
                }

                if (move[i][j] == 1)
                {
                    move[i + 1][j] = 1;
                }
            }
        }

        for (int i = BIG_SIZE - 2; i >= 0; i--)
            for (int j = BIG_SIZE - 2; j >= 0; j--)
                if (move[i][j])
                {
                    if (move[i + 1][j] == 0 && out[i + 1][j] != ' ' && out[i + 1][j] != '\0')
                    {
                        move[i][j] = 0;
                    }

                    if (move[i][j + 1] == 0 && out[i][j + 1] != ' ' && out[i][j + 1] != '\0')
                    {
                        move[i][j] = 0;
                    }
                }

        int flag = FALSE;
        for (int i = 0; out[i][0] != '\0'; i++)
        {
            for (int j = 0; out[i][j] != '\0'; j++)
                if (out[i][j] != ' ' && out[i][j] != '\0' && move[i][j])
                {
                    flag = TRUE;
                    break;
                }

            if (flag)
                break;
        }

        if (!flag)
        {
            break;
        }

        for (int i = 0; out[i][0] != '\0'; i++)
            for (int j = 0; out[i][j] != '\0'; j++)
            {
                out[ i - move[i][j] ][j] = out[i][j];

                if (move[i][j])
                    was = TRUE;
            }

        for (int i = 0; out[i][0] != '\0'; i++)
            for (int j = 0; out[i][j] != '\0'; j++)
            {
                if (out[i][j] == '-' && out[i + 1][j] == '-')
                {
                    out[i + 1][j + 0] = ' ';
                    out[i + 1][j + 1] = ' ';
                    out[i + 1][j + 2] = ' ';
                }

                if (out[i][j] == '>' && out[i + 1][j] == '>' && out[i][j + 1] == out[i + 1][j + 1])
                {
                    out[i + 1][j + 0] = ' ';
                    out[i + 1][j + 1] = ' ';
                }
            }

        for (int i = 0; out[i][0] != '\0'; i++)
        {
            int j = 0;
            int count = 0;

            for (; out[i][j] != '\0'; j++)
            {
                if (out[i][j] == ' ')
                    count++;
            }

            if (count == j)
            {
                out[i][0] = '\0';
                break;
            }
        }
    }

    for (int i = 0; out[i][0] != '\0'; i++)
    {
        for (int j = 0; out[i][j] != '\0'; j++)
        {
            if (out[i][j] == '-')
                printf("└");
            else if (out[i][j] == '|')
                printf("│");
            else if (out[i][j] == '+')
                printf("├");
            else if (out[i][j] == '>')
                printf("▶");
            else
                printf("%c", out[i][j]);
        }
        printf("\n");
    }
}

/*
 * Рекурсивный алгоритм вывода
 *
 * @param trie [in]
 * @param level [in]
 * @param end [in]
 * @param probels [in]
 */

void trie_print_recursive(my_trie *trie, int level, int end, int probels[SIZE])
{
    if (trie == NULL)
        return;

    for (int i = 0; i < level - 1; i++)
    {
        if (probels[i])
            printf("  ");
        else
            printf("│ ");
    }

    if (trie->key == '\0')
        printf("head\n");
    else if (trie->is_real)
    {
        if (end)
            printf("└▶" GREEN "%c\n", trie->key);
        else
            printf("├▶" GREEN "%c\n", trie->key);
    }
    else
    {
        if (end)
            printf(WHITE "└▶%c\n", trie->key);
        else
            printf(WHITE "├▶%c\n", trie->key);
    }

    printf(WHITE "");

    for (node_t *temp = trie->leavs; temp != NULL; temp = temp->next)
    {
        if (temp->next != NULL)
        {
            probels[level] = 0;
            trie_print_recursive((my_trie*)temp->data, level + 1, FALSE, probels);
        }
        else
        {
            probels[level] = 1;
            trie_print_recursive((my_trie*)temp->data, level + 1, TRUE, probels);
        }
    }
}

/*
 * Очищает дерево
 *
 * @param trie [in]
 * @param free_data [in]
 */

void trie_free(my_trie *trie, void (*free_data)(void*))
{
    if (trie == NULL)
        return;

    for (node_t *temp = trie->leavs; temp != NULL; temp = temp->next)
        trie_free((my_trie*)temp->data, free_data);

    free_data(trie->data);
    free(trie);
}

/*
 * Рекурсивный алгоритм вывода в массив строк
 *
 * @param trie [in]
 * @param level [in]
 * @param end [in]
 * @param probels [in]
 * @param out [out]
 * @param io [in]
 * @param jo [in]
 */

void trie_print_recursive_compress(my_trie *trie, int level, int end, int probels[SIZE], char out[BIG_SIZE][BIG_SIZE], int *io, int jo)
{
    if (trie == NULL)
        return;

    for (int i = 0; i < level - 1; i++)
    {
        if (probels[i])
        {
            out[*io][jo++] = ' ';
            out[*io][jo++] = ' ';
        }
        else
        {
            out[*io][jo++] = '|';
            out[*io][jo++] = ' ';
        }
    }

    if (trie->key == '\0')
    {
        out[*io][jo++] = 'h';
        out[*io][jo++] = 'e';
        out[*io][jo++] = 'a';
        out[*io][jo++] = 'd';
    }
    else
    {
        if (end)
        {
            out[*io][jo++] = '-';
            out[*io][jo++] = '>';
        }
        else
        {
            out[*io][jo++] = '+';
            out[*io][jo++] = '>';
        }

        out[*io][jo++] = trie->key;
    }

    for (node_t *temp = trie->leavs; temp != NULL; temp = temp->next)
    {
        if (temp->next != NULL)
        {
            probels[level] = 0;
            (*io)++;
            trie_print_recursive_compress((my_trie*)temp->data, level + 1, FALSE, probels, out, io, 0);
        }
        else
        {
            probels[level] = 1;
            (*io)++;
            trie_print_recursive_compress((my_trie*)temp->data, level + 1, TRUE, probels, out, io, 0);
        }
    }
}
