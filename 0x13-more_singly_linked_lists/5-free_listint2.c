#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @head: a pointer to the pointer to the first node in the list
 */
void free_listint2(listint_t **head)
{
	listint_t *current, *next;

	if (head == NULL)
		return;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}
