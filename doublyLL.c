#include "monty.h"

/**
 *addEnode - add node at the end of doubly linked list
 *@head: head pointer
 *@n: data to add
 *Return: zero
 */
int addEnode(stack_t **stack, int n)
{
	stack_t *new_node = NULL;

	if (!stack)
		return (-1);

	new_node = malloc(sizeof(stack_t));/*malloc new node*/
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->next  = NULL;
		new_node->prev = NULL;
	}
	else 
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}

	return (0);
}

/**
 *deleteEnode - delete end node of a doubly linked list
 *@head: head pointer
 *Return: nothing
 */
void deleteEnode(stack_t **head)
{
	stack_t *del = NULL;

	del = *head;
	if ((*head)->next == NULL)
	{
		*head = NULL;
		free(del);
	}
	else
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(del);
	}
}

/**
 * free_dllist - frees a doubly linked list with only int data, no strings
 * @head: pointer to head of list
 */
void free_dllist(stack_t **stack)
{
	if (!stack)
		return;

	while (*stack && (*stack)->next)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
	}
	free(*stack);
}
