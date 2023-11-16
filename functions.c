#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty ByteCode file.
 */
void push(stack_t **stack, unsigned int line_number)
{
stack_t *new_node = malloc(sizeof(stack_t));
if (stack == NULL)
{
printf("%d\n", line_number);
exit(EXIT_FAILURE);
}

if (new_node == NULL)
{
fprintf(stderr, " Error: malloc failed\n");
free_stack(stack, line_number);
exit(EXIT_FAILURE);
}
new_node->n = variable.value;
new_node->prev = NULL;
new_node->next = *stack;
if (*stack != NULL)
{
new_node->next = NULL;
(*stack)->prev = new_node;
*stack = new_node;
}
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty ByteCode file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

if (stack == NULL)
{
fprintf(stderr, "L%d: invalid stack\n", line_number);
	exit(EXIT_FAILURE);
}
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
/**
 * free_stack - function that frees the whole program
 * @stack: pointer to the head
 * @line_number: data value
 * Return: nothing
 */
void free_stack(stack_t **stack, unsigned int line_number)
{
if (stack == NULL)
	return;
while (*stack != NULL)
{
pop(stack, line_number);
}
}

