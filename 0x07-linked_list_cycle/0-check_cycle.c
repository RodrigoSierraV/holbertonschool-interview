#include "lists.h"

/**
 * check_cycle - hecks if a singly linked list has a cycle in it.
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *aux = list, *follow = list;

	if (list == NULL)
		return (0);
	if (!aux->next || !follow->next->next)
		return (0);
	aux = aux->next;
	follow = follow->next->next;
	while (aux != follow)
	{
		if (!aux->next || !follow->next->next)
			return (0);
		aux = aux->next;
		follow = follow->next->next;
	}
	return (1);
}
