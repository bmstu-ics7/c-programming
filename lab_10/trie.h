#ifndef __TRIE_H
#define __TRIE_H

#include "list.h"

#define TRUE 1
#define FALSE 0

#define GREEN   "\x1b[32m"
#define WHITE   "\x1b[0m"

#define SIZE 128
#define BIG_SIZE 1000

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

void trie_search_keys(FILE *stream, my_trie *trie, char *str);

void trie_print(my_trie *trie);

void trie_print_compress(my_trie *trie);

void trie_free(my_trie *trie, void (*free_data)(void*));

#endif
