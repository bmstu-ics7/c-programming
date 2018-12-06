#ifndef __TRIE_H
#define __TRIE_H

#include "list.h"

#define TRUE 1
#define FALSE 0

typedef struct my_trie my_trie;

struct my_trie
{
    void *data;     // Данные в узле
    char key;       // Метка
    int is_real;    // Является ли узел реально существующим либо промежуточным
    node_t *leavs;  // Список узлов
};

my_trie *trie_create();

void *trie_get(my_trie *trie, char *str_key);

void trie_set(my_trie *trie, char *str_key, void *data);

void trie_remove(my_trie *trie, char *str_key);

#endif
