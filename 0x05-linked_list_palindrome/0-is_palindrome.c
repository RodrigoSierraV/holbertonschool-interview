#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head, *front, *rear;
	int len = 0, half = 0, i = 0, j;

	if (current == NULL)
		return (1);
	while (current)
	{
		current = current->next;
		len++;
	}
	half = len / 2;
	while (i != half)
	{
		front = rear = *head;
		for (j = 0; j < i; j++)
			front = front->next;
		for (j = 0; j < len - (i + 1); j++)
			rear = rear->next;
		if (front->n != rear->n)
			return (0);
		i++;
	}
	return (1);
}
