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

void insert(node_t **head, node_t *elem, node_t *before)
{
    if (head == NULL || elem == NULL)
        return;

    node_t *temp = *head;
    node_t *prev = *head;

    while (temp != NULL)
    {
        if (temp == before)
        {
            prev->next = elem;
            elem->next = before;
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    if (*head == NULL)
        if (before == NULL)
        {
            *head = elem;
            elem->next = before;
            return;
        }
        else
            return;

    if (before == NULL)
    {
        prev->next = elem;
        elem->next = before;
    }
}

void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*))
{
    if (head == NULL || comparator == NULL || *head == NULL)
        return;

    node_t *temp = (*head)->next;
    node_t *prev = *head;

    for (; temp != NULL; temp = temp->next)
    {
        if (comparator(temp->data, prev->data) == 0)
        {
            prev->next = temp->next;
            free(temp);
            temp = prev;
        }
        else
        {
            prev = temp;
        }
    }
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

