#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - adds a new node in a sorted list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
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
    if (new->n < current->n)
    {
        new->next = current;
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
        }
        if (current->next == NULL)
            current->next = new;
        current = current->next;
    }

    return new;
}
