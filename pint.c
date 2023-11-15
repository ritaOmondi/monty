#include "monty.h"
/**
 *pint - prints the value at the top of the stack
 *@head: head pointer
 *@line_number: node number
 *Return: nothing
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (!head || !*head)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
