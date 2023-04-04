#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: a pointer to the pointer to the first node in the list
 *
 * Return: the data inside the deleted node,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int data = 0;

	if (head == NULL || *head == NULL)
		return (0);

	temp = (*head)->next;
	data = (*head)->n;
	free(*head);
	*head = temp;

	return (data);
}
