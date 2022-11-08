#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
// 스택을 위한 타입 정의
typedef int element;
typedef struct StackNode {
	element data;
	char name[100];
	struct StackNode* link;
} StackNode;
typedef struct {
	StackNode* top;
} LinkedStackType;
// 초기화 함수
void init(LinkedStackType* s)
{
	s->top = NULL;
}
// 공백 상태 검출 함수
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedStackType* s) // Stack 연산중의 하나라 남겨두었지만 항상 거짓을 반환. 즉 꽉 차있을 때는 없음
{
	return 0;
}
// 삽입 함수
void push(LinkedStackType* s, element item, const char *name)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->data = item;
		strcpy(temp->name, name);
		temp->link = s->top;
		s->top = temp;
	}
}

// 삭제 함수
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
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
// 피크 함수
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
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
// 주 함수
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