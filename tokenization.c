#include "monty.h"

/**
* tokenizer - tokenizes string
* @input: string to be tokenized
* @stack: pointer to pointer to stack
* @line_number: the number of the line where command is
*
* Return: nothing
*/
void pass_token(char *input, stack_t **stack, unsigned int line_number)
{
	char *token = NULL, *tokens = NULL;

	token = strtok(input, " ");
	if (!token || *token == '\n' || *token == '#' || *token == ' ')
		return;
	if (strcmp(token, "push") == 0)
	{
		tokens = token;
		token = strtok(NULL, " ");
		if (confirm_dgts(token) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack, line_number);
			exit(EXIT_FAILURE);
		}
		variable.value = atoi(token);
		operations(stack, line_number, tokens);
	}
	else
		operations(stack, line_number, token);
}
