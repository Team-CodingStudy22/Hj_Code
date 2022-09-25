#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 3
#define MAX_STRING 100

typedef struct {
	int num;
	char num_words[MAX_STRING];
} element;
element stack[MAX_STACK_SIZE];
int top = -1;

void init_stack()
{
	top = -1;
}

int is_empty()
{
	return (top == -1);
}

int is_full()
{
	return top == (MAX_STACK_SIZE - 1);
}

void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else 
		stack[++top] = item;
}


void stack_print()
{
	if (is_empty())
		printf("<empty>\n");
	else
		for (int i = top; i >= 0; i--)
			if (i ==top)
				printf("[%d, %s] <- top\n", stack[i].num, stack[i].num_words);
			else
				printf("[%d, %s]\n", stack[i].num, stack[i].num_words);
}

element pop()
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top--];
}

element peek()
{
	if (is_empty())
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top];
}

int main(void)
{

	init_stack();

	element a1 = { 10, "ten" };
	element a2 = { 20, "twenty" };
	element a3 = { 30, "thirty" };
	element a4 = { 40, "forty" };
	element a5 = { 50, "fifty" };

	stack_print();
	printf("--\n");
	push(a1);
	stack_print();
	printf("--\n");
	push(a2);
	stack_print();
	printf("--\n");
	push(a3);
	stack_print();
	printf("--\n");
	push(a4);
	stack_print();
	printf("--\n");
	pop();
	stack_print();
	printf("--\n");
	push(a5);
	stack_print();
	printf("--\n");
	pop();
	stack_print();
	printf("--\n");
	pop();
	stack_print();
	printf("--\n");
	pop();
	stack_print();
	printf("--\n");
}