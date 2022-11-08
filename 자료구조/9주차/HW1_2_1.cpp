#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
// ������ ���� Ÿ�� ����
typedef int element;
typedef struct StackNode {
	element data;
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
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "�޸� �Ҵ翡��\n");
		return;
	}
	else {
		temp->data = item;
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
				printf("\n%d <- top", p->data);
			else 
				printf("\n%d", p->data);
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
	push(&s, 10); print_stack(&s);
	push(&s, 20); print_stack(&s);
	push(&s, 30); print_stack(&s);
	push(&s, 40); print_stack(&s);
	pop(&s); print_stack(&s);
	push(&s, 50); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	return;
}