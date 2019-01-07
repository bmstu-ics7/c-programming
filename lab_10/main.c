#include <stdio.h>

#include "trie.h"

#define SUCCESS 0

void free_data(void *data)
{
    return;
}

int main(void)
{
    my_trie *trie = trie_create();
    int a = 12, b = 10;

    trie_set(trie, "aaa", &a);
    trie_set(trie, "kek", &a);
    trie_set(trie, "kak", &b);
    trie_set(trie, "keka", &a);
    trie_set(trie, "keko", &a);
    trie_set(trie, "kakak", &a);
    trie_set(trie, "keklol", &a);
    trie_set(trie, "lol", &b);
    trie_set(trie, "lolel", &a);
    trie_set(trie, "lolf", &a);
    trie_set(trie, "lolea", &a);
    trie_set(trie, "lod", &a);
    trie_set(trie, "fed", &a);
    trie_set(trie, "food", &a);
    trie_set(trie, "fedya", &a);

    printf("%d\n", *(int*)trie_get(trie, "kek"));
    trie_remove(trie, "kek");

    printf("%d\n", trie_get(trie, "kek") == NULL ? -1 : *(int*)trie_get(trie, "kek"));

    printf("\n");
    trie_search_keys(stdout, trie, "k");

    printf("\n");
    trie_search_keys(stdout, trie, "o");

    printf("\n");
    trie_print(trie);

    printf("\n");
    trie_print_compress(trie);

    trie_free(trie, free_data);
    return SUCCESS;
}
