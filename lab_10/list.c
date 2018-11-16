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

    if (head->next == NULL)
        return head;

    node_t *sorted = NULL;

    for (node_t *temp = head; temp != NULL;)
    {
        node_t *element = temp;
        temp = temp->next;
        sorted_insert(&sorted, element, comparator);
    }

    return sorted;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    if (head == NULL || element == NULL || comparator == NULL)
        return;

    if (*head == NULL)
    {
        *head = element;
        element->next = NULL;
        return;
    }

    if (comparator((*head)->data, element->data) > 0)
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

