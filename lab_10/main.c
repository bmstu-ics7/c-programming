#include <stdio.h>

#include "trie.h"

#define SUCCESS 0

int main(void)
{
    my_trie *trie = trie_create();
    int a = 12, b = 10;   
    trie_set(trie, "kek", &a);
    trie_set(trie, "kak", &b);
    printf("%d\n", *(int*)trie_get(trie, "kek"));
    trie_remove(trie, "kek");
    printf("%d\n", trie_get(trie, "kek") == NULL ? -1 : *(int*)trie_get(trie, "kek"));
    return SUCCESS;
}
