#include "list.h"

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void *))
{
    node_t *temp = head;
    
    while (temp != NULL)
    {
        if (comparator(temp->data, data) == 0)
            break;

        temp = temp->next;
    }

    return temp;
}

void *pop_back(node_t **head)
{
    if (head == NULL)
        return NULL;

    if (*head == NULL)
        return NULL;

    node_t *temp = *head;
    node_t *new_last = NULL;

    while (temp->next != NULL)
    {
        new_last = temp;
        temp = temp->next;
    }

    if (new_last == NULL)
        *head = NULL;
    else
        new_last->next = NULL;

    void *data = temp->data;

    free(temp);

    return data;
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (head == NULL)
        return NULL;

    if (comparator == NULL)
        return NULL;

    int count_sorted = 1;
    int count_all = 0;

    for (node_t *temp = head; temp != NULL; temp = temp->next)
        count_all++;

    for (int i = 1; i < count_all; i++)
    {
        node_t *temp = head;
        node_t *prev_temp = NULL;

        for (int j = 1; j <= count_sorted; j++)
        {
            prev_temp = temp;
            temp = temp->next;
        }

        if (prev_temp)
            prev_temp->next = temp->next;

        sorted_insert(&head, temp, comparator);
        count_sorted++;
    }

    return head;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    if (comparator((*head)->data, element->data) >= 0)
    {
        element->next = *head;
        *head = element;
        return;
    }

    node_t *temp = *head;

    for (; temp->next != NULL; temp = temp->next)
        if (comparator(element->data, temp->next->data) <= 0)
        {
            element->next = temp->next;
            temp->next = element;
            return;
        }

    temp->next = element;
    element->next = NULL;
    return;
}

void free_list(node_t *head, void (*free_data)(void*))
{
    node_t *temp = head;
    
    while (temp != NULL)
    {
        node_t *el = temp;
        temp = temp->next;

        free_data(el->data);
        free(el);
    }
}

