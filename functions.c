#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the top of the stack.
 * @value: Value to be pushed onto the stack.
 * @line_number: Line number in the Monty ByteCode file.
 */
void push(stack_t **stack, int value, unsigned int line_number)
{
stack_t *new_node = malloc(sizeof(stack_t));
printf("Pushing %d to the stack at line %d\n", value, line_number);

if (!new_node)
{
fprintf(stderr, "L%d: Error: malloc failed\n", line_number);
exit(EXIT_FAILURE);
}
new_node->n = value;
new_node->prev = NULL;
if (*stack == NULL)
{
new_node->next = NULL;
}
else
{
new_node->next = *stack;
(*stack)->prev = new_node;
}
*stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty ByteCode file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;
printf("Printing all values on the stack at line %d\n", line_number);
(void)line_number;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
void free_stack(stack_t *stack)
{
while (stack != NULL)
{
stack_t *temp = stack;
stack = stack->next;
free(temp);
}
}

