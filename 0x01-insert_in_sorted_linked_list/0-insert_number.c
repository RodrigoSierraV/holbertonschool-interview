#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *current;
    listint_t *new;

    current = *head;
    new = malloc(sizeof(listint_t));
    if (!new)
        return NULL;
    new->n = number;
    new->next = NULL;
    if (*head == NULL)
    {
        *head = new;
        return new;
    }
    while (current != NULL)
    {
        if (current->next && new->n < current->next->n)
        {
            new->next = current->next;
            current->next = new;
            break;
            printf("%i linked %i number\n", current->next->n, number);
        }
        if (current->next == NULL)
            current->next = new;
        current = current->next;
    }

    return new;
}

