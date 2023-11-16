#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdarg.h>

/** global variables **/
/**
* struct value - holds value in global scope
* @value: actual value
*
* Description: to allow me to access this value globally
*/
typedef struct value
{
	int value;
} value_s;
extern value_s variable;
value_s variable;

/**structures **/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**** prototypes **/
void push(stack_t **stack,  unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack, unsigned int line_number);
void operations(stack_t **stack, unsigned int line_number, char *token);
void pass_token(char *input, stack_t **stack, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
int confirm_dgts(char *token);
void nop(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void modulus(stack_t **stack, unsigned int line_number);
void multiplication(stack_t **stack, unsigned int line_number);
void division(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void free_dllist(stack_t **stack);
void deleteEnode(stack_t **head);
int addEnode(stack_t **stack, int n);
void rotr(stack_t **head, unsigned int line_number);
void rotl(stack_t **head, unsigned int line_number);
void pstr(stack_t **head, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);
#endif
