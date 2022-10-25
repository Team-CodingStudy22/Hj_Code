#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void print_list(ListNode* head) {
	ListNode* p;

	if (head == NULL)
		return;

	p = head->link;

	while (p != head) {
		printf("%d->", p->data);
		p = p->link;
	}

	printf("%d->", p->data);
	printf("\n");
}

//처음에 node를 새로 삽입한다
ListNode* insert_first(ListNode* head, element data) {

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}

	return head;
}

//맨 마지막에 값을 삽입한다 
ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL) {
		head = node;
		node->link = head;
	}
		
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	
	return head;
}

//첫번째 값을 삭제한다 
ListNode* delete_first(ListNode* head) {
	ListNode* temp;

	if (head == NULL) {
		printf("리스트가 비어 삭제를 못 함\n");
		return NULL;
	}
	else if (head == head->link) {
		temp = head;
		head = NULL;
	}
	else {
		temp = head->link;
		head->link= temp->link;
	}
	free(temp);
	return head;
}


ListNode* delete_last(ListNode* head) {
	ListNode* removed = head;
	ListNode* p = head->link;

	if (head == NULL) {
		printf("리스트가 비어 삭제를 못 함\n");
		return NULL;
	}
	else if (head == head->link) {
		removed = head;
		head = NULL;
		free(removed);
	}
	else {
		while (p->link != head)
			p = p->link;
		p->link = head->link;
		head = p;
		free(removed);
	}
	
	return head;
}


int search(ListNode* head, element data) {
	ListNode* p = head;
	int count = 0;
	if (head == NULL) return NULL;

	do {
		if (p->data == data)
			return count;
		count++;
		p = p->link;
	} while (p != head);
	return NULL;
}

element get_size(ListNode* head) {

	ListNode* p;
	int count = 0;

	//연결리스트가 비어있어도 1이 return 될 수 있음 

	if (head == NULL) return 0;

	p = head->link;
	do {
		count++;
		p = p->link;
	} while (p != head->link);

	free(p);
	return count;

}

int main(void) {
	ListNode* head = NULL;
	 
	head = insert_last(head, 20);
	print_list(head);

	head = insert_last(head, 30);
	print_list(head);
	head = insert_last(head, 40);
	print_list(head);
	head = insert_first(head, 10);
	print_list(head);

	head = delete_first(head);
	print_list(head);

	head = delete_last(head);
	print_list(head);

	int num = 20;
	printf("\n%d은 %d번째에 있습니다\n", num, search(head, 20));

	printf("해당 리스트의 크기는 %d입니다", get_size(head));

	return 0;
}