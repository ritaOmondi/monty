#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack: node to be swapped
 * @line_number: node number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
	{
		vprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
