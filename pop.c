#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: bytecode line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		variable.value = (*stack)->n;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

