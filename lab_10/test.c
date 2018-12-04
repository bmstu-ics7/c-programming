#include "list.h"

int comparator(const void *data1, const void *data2)
{
    return *(int*)data1 - *(int*)data2;
}

void free_data(void *data)
{
    return;
}

int main(void)
{
    int arr[] = { 1, 3 ,5, 1, 3, 4, 2, 0, 3, 2, 3 };

    node_t *head = malloc(sizeof(node_t));

    node_t *temp = head;

    for (int i = 0; i < 10; i++)
    {
        temp->data = arr + i;

        if (i != 9)
        {
            temp->next = malloc(sizeof(node_t));
            temp = temp->next;
        }
    }

    temp->next = NULL;

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", *(int*)temp->data);
        temp = temp->next;
    }
    printf("\n");

    head = sort(head, comparator);

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", *(int*)temp->data);
        temp = temp->next;
    }
    printf("\n");

    remove_duplicates(&head, comparator);

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", *(int*)temp->data);
        temp = temp->next;
    }
    printf("\n");

    int a = 3, b = 10, c = 90;

    node_t *elem_a, *elem_b, *elem_c;
    elem_a = malloc(sizeof(node_t));
    elem_b = malloc(sizeof(node_t));
    elem_c = malloc(sizeof(node_t));
    elem_a->data = &a;
    elem_b->data = &b;
    elem_c->data = &c;

    insert(&head, elem_a, head->next->next);
    insert(&head, elem_b, NULL);
    insert(&head, elem_c, head);

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", *(int*)temp->data);
        temp = temp->next;
    }
    printf("\n");

    free_list(head, free_data);
}
