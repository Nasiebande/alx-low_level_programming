#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data in a listint_t list
 * @head: pointer to the head of the list
 *
 * Return: sum of all data in the list
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *curr = head;

	while (curr)
	{
		sum += curr->n;
		curr = curr->next;
	}

	return (sum);
}
