#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

/**
 * struct bus_s - all variables
 * @arg: a value
 * @file: the pointer
 * @content: the line content
 * @lifi: if flag change
 * Description: it carries values in program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

/**
 * struct stack_s - is a doubly linked list 
 * @n: integer
 * @prev: previous element
 * @next: next element
 *
 * Description: doubly linked list
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

void f_swap(stack_t **head, unsigned int counter);
void f_push(stack_t **head, unsigned int number);
ssize_t getstdin(char **lineptr, int file);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
char  *clean_line(char *content);
void f_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void f_pop(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);
void f_add(stack_t **head, unsigned int counter);
void f_pall(stack_t **head, unsigned int number);
void f_nop(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void addqueue(stack_t **head, int n);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);
/**
 * struct instruction_s - the opcode and all functional instructions
 * @opcode: the opcode of the instruction
 * @f: opcode handler 
 *
 * Description: the opcode and all functions
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
#endif
