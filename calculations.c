#include "monty.h"

/**
 * add - function to add top two elements on stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int summation;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			 line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
	}

	summation = variable.value;
	pop(stack, line_number);
	summation += variable.value;
	pop(stack, line_number);
	variable.value = summation;
	push(stack, line_number);
}

/**
 * sub - subtracts top two elements on stack
 * @stack: stack pointer
 * @line_number: line number
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int minus;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
	}

	minus = variable.value;
	pop(stack, line_number);
	minus = variable.value - minus;
	pop(stack, line_number);
	variable.value = minus;
	push(stack, line_number);
}

/**
 * division - divides second top element of stack by top of stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void division(stack_t **stack, unsigned int line_number)
{
	int divide;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
			line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
	}
	if (variable.value == 0)
	{
		write(STDERR_FILENO, "L%d: division by zero\n",
			line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
	}

	divide = variable.value;
	pop(stack, line_number);
	divide = variable.value / divide;
	pop(stack, line_number);
	variable.value = divide;
	push(stack, line_number);
}

/**
 * multiplication - multiplies second top element of stack with top element
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void multiplication(stack_t **stack, unsigned int line_number)
{
	int multiply;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
			line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
	}

	multiply = variable.value;
	pop(stack, line_number);
	multiply = variable.value * multiply;
	pop(stack, line_number);
	variable.value = multiply;
	push(stack, line_number);
}

/**
 * modulus - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void modulus(stack_t **stack, unsigned int line_number)
{
	int remainder;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
	}
	if (variable.value == 0)
	{
		printf("L%d: division by zero\n", line_number);
		free_stack(stack, line_number);
		exit(EXIT_FAILURE);
	}

	remainder = variable.value;
	pop(stack, line_number);
	remainder = variable.value % remainder;
	pop(stack, line_number);
	variable.value = remainder;
	push(stack, line_number);
}
