#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
// ������ ���� Ÿ�� ����
typedef int element;
typedef struct StackNode {
	element data;
	char name[100];
	struct StackNode* link;
} StackNode;
typedef struct {
	StackNode* top;
} LinkedStackType;
// �ʱ�ȭ �Լ�
void init(LinkedStackType* s)
{
	s->top = NULL;
}
// ���� ���� ���� �Լ�
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(LinkedStackType* s) // Stack �������� �ϳ��� ���ܵξ����� �׻� ������ ��ȯ. �� �� ������ ���� ����
{
	return 0;
}
// ���� �Լ�
void push(LinkedStackType* s, element item, const char *name)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "�޸� �Ҵ翡��\n");
		return;
	}
	else {
		temp->data = item;
		strcpy(temp->name, name);
		temp->link = s->top;
		s->top = temp;
	}
}

// ���� �Լ�
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}
// ��ũ �Լ�
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		return s->top->data;
	}
}
void print_stack(LinkedStackType* s)
{
	if (is_empty(s))
		printf("\n(empty)");

	else {
		for (StackNode* p = s->top; p != NULL; p = p->link) {
			if (p == s->top)
				printf("\n[%d, %s] <- top", p->data, p->name);
			else
				printf("\n[%d, %s]", p->data, p->name);
		}
	}
	printf("\n--");
}
// �� �Լ�
void main()
{
	LinkedStackType s;

	init(&s);
	print_stack(&s);
	push(&s, 10, "ten");
	push(&s, 20, "twenty"); print_stack(&s);
	push(&s, 30, "thirty"); print_stack(&s);
	push(&s, 40, "forty"); print_stack(&s);
	pop(&s); print_stack(&s);
	push(&s, 50, "fifty"); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	return;
}