#include "monty.h"
/**
 * main - Entry point to the program
 *@argc: argument count
 *@argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char opcode[256];
	int value;
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	FILE *file = fopen(argv[1], "r");
if (argc != 2)
{
fprintf(stderr, "USAGE: %s file\n", argv[0]);
return (EXIT_FAILURE);
}
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}
while (fscanf(file, "%s %d", opcode, &value) == 2)
{
printf("Process line %d: opcode=%s, value=%d\n", line_number, opcode, value);
if (strcmp(opcode, "push") == 0)
{
push(&stack, value, line_number);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(&stack, line_number);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
free_stack(stack);
fclose(file);
return (EXIT_FAILURE);
}
line_number++;
}
fclose(file);
free_stack(stack);
return (0);
}
