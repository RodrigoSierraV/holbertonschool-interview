#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

listint_t *findloop(listint_t *head, listint_t *current, listint_t *fast);
/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer to the given listint.
 * Return:  The address of the node where
 * the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *current = (listint_t *)head, *fast = (listint_t *)head;

	return (findloop((listint_t *)head, current, fast));
}

/**
 * findloop - finds a loop in a linked list.
 * @head: pointer to the given listint.
 * @current: pointer to the given listint.
 * @fast: pointer to the given listint.
 *
 * Return: The address of the node where
 * the loop starts, or NULL if there is no loop.
 */
listint_t *findloop(listint_t *head, listint_t *current, listint_t *fast)
{
	while (current && fast && fast->next)
	{
		current = current->next;
		fast = fast->next->next;
		if (current == fast)
		{
			if (current != head)
			{
				head = head->next;
				current = head;
				fast = head;
				findloop(head, current, fast);
			}
			else
			{
				return (head);
			}
		}
	}
	return (fast);
}
