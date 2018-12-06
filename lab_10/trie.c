#include "trie.h"

my_trie *trie_create()
{
    my_trie *trie = malloc(sizeof(my_trie));
    trie->data = NULL;
    trie->key = '\0';
    trie->is_real = FALSE;
    trie->leavs = NULL;

    return trie;
}

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
            insert(&(trie->leavs), node, trie->leavs);
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
            insert(&(trie->leavs), node, trie->leavs);
            trie = tmp;
        }
    }
}

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

