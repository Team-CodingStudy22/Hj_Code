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

//ó���� node�� ���� �����Ѵ�
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

//�� �������� ���� �����Ѵ� 
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

//ù��° ���� �����Ѵ� 
ListNode* delete_first(ListNode* head) {
	ListNode* temp;

	if (head == NULL) {
		printf("����Ʈ�� ��� ������ �� ��\n");
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
		printf("����Ʈ�� ��� ������ �� ��\n");
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

	//���Ḯ��Ʈ�� ����־ 1�� return �� �� ���� 

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
	printf("\n%d�� %d��°�� �ֽ��ϴ�\n", num, search(head, 20));

	printf("�ش� ����Ʈ�� ũ��� %d�Դϴ�", get_size(head));

	return 0;
}