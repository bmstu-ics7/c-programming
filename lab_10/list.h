#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node 
{
    void *data;
    node_t *next;
};

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void *));

void*pop_back(node_t **head);

node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

#endif
