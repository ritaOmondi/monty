#define _GNU_SOURCE
#include "monty.h"

/**
 * main - Entry point to the program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char *buffer = NULL;
    char *str = NULL;
    size_t len = 0;
    unsigned int line_number = 1;
    stack_t *stack = NULL;
    FILE *file = NULL; 

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&buffer, &len, file) != -1)
    {
        if (*buffer != '\n')
        {
		str = strtok(buffer, "\n");
pass_token(str, &stack, line_number);
	}

        line_number++;
    }

    fclose(file);
    free(buffer);
    if (stack != NULL)
		free_stack(&stack, line_number);
    return 0;
}

