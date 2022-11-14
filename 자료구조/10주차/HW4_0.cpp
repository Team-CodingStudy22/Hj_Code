#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

//스택을 위한 타입 정의 
typedef TreeNode* element;

typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

//초기화 함수
void init(LinkedStackType* s)
{
	s->top = NULL;
}

//공백 상태 검출 함수
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}

//포화 상태 검출 함수
int is_full(LinkedStackType* s)
{
	return 0;
}

//삽입 함수
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

void print_stack(LinkedStackType* s)
{
	for (StackNode* p = s->top; p != NULL; p = p->link)
		printf("%d ->", p->data);
	printf("NULL \n");
}

element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode *temp = s->top;
		element data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

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

void inorder_iter(TreeNode* root)
{

	LinkedStackType temp;
	//여기에 연결된 스택을 이용한 반복적 순회 관련 코드 추가 
	while (1) {
		for (; root; root = root->left)
			push(&temp, root);
		root = pop(&temp);
		if (!root) break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}

//		  15
//	   4		 20
//    1	      16  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;

int main(void)
{
	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");

	return 0;
}


