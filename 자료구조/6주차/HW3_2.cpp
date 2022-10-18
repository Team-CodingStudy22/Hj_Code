#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_LIS_SIZE 100

typedef int element;
typedef struct listNode {
	element data;
	struct listNode *link;
}ListNode;

//item�� List�� �ִ��� Ȯ���ϴ� �Լ�
int is_in_list(ListNode* head, element item) {
	ListNode *p = head;

	while (p != NULL) {
		if (p->data == item)
			return true;
		p = p->link;
	}
	return false;
}

//List�� ���̸� ��ȯ�ϴ� �Լ�
int get_length(ListNode* head) {
	ListNode* p;
	p = head;
	int count = 0;

	while (p != NULL) {
		p = p->link;
		count++;
	}
	return count;
}

//List�� ������ ��ȯ�ϴ� �Լ�
int get_total(ListNode* head) {
	ListNode* p = head;
	
	int sum = 0;
	while (p != NULL) {
		sum += p->data;
		p = p->link;
	}
	return sum;
}

//pos��ġ�� �ִ� value�� ��ȯ�ϴ� �Լ� 
element get_entry(ListNode* head, int pos) {
	ListNode* p = head;

	for (int count = 0; count == pos; count++) {
		p = p->link;
	}
	return p->data;
}

//key���� ������ �ִ� node ���� 
ListNode* delete_by_key(ListNode* head, int key) {
	ListNode* p = head;
	ListNode* removed;

	while (p != NULL) {
		if (p->link->data == key) {
			removed = p->link;
			p->link = removed->link;
			free(removed);
			break;
		}
		p = p->link;
	}
	return head;
}

//pos��ġ�� value ���� �ִ� �Լ�
ListNode* insert_pos(ListNode* head, int pos, element value) {
	ListNode* pre = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;

	for (int i = 0; i < pos-2; i++)
		pre = pre->link;
	
	p->link = pre->link;
	pre->link = p;

	return head;
}

//pos��ġ�� node�� �����ϴ� �Լ� 
ListNode* delete_pos(ListNode* head, int pos) {
	ListNode* pre = head;
	ListNode* removed = (ListNode*)malloc(sizeof(ListNode));

	for (int i = 0; i < pos-2; i++)
		pre = pre->link;
	removed = pre->link;
	pre->link = pre->link->link;
	free(removed);
	return head;
}

//�� ó���� value ���� �ִ� �Լ� 
ListNode * insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert_last(ListNode * head, int value)
{
		ListNode* temp = head;
		ListNode* p = (ListNode*)malloc(sizeof(ListNode));
		p->data = value;
		p->link = NULL;

		if (head == NULL)
			head = p;
		else {
			while (temp->link != NULL)
				temp = temp->link;

			temp->link = p;
		}
		return head;
	
}
//pre �ڿ� value �ֱ� 
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p -> data = value;
	p -> link = pre -> link;
	pre -> link = p;
	return head;
}

//�� ó�� ���� ���� 
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

//���� �Լ�
void remove_node(ListNode* head, int x)
{
	ListNode* list = head;

	if (head == NULL)  return; 	// ������ ���� ����
	else if (head->data == x) 	// ã�� ���(���� ���)�� ù ����� ��� 
	{      // delete list; free(list);
		head = head->link;
		return;
	}
	else 			// ������ ���
	{
		while (list->link != NULL)
		{
			if (list->link->data == x)
			{
				list->link = list->link->link;
				//delete list; free(list->link);
				return;
			}
			list = list->link;
		}
	}
}

//list ��� �Լ� 
void print_list(ListNode* head){
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

//�� ����Ʈ�� ��ġ�� �Լ� 
ListNode* concat_list(ListNode* head1, ListNode* head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head2;
	else {
		ListNode* p;
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

//���� �����
ListNode* reverse(ListNode* head) {
	ListNode* p, * q, * r;

	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}


int main(void)
{
	ListNode* list1 = NULL, * list2 = NULL, * list3 = NULL;
	ListNode* head1 = NULL, * head2 = NULL, *head3 = NULL;
	//list1 = 30->20->10->�� �����. �̶� 10, 20, 30�� ������ ��带 �����Ѵ�.
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	
	// list1�� ���
	printf("list1 = "); print_list(list1);

	//list1�� �� �� ��带 �����Ѵ� ��, list1 = 20->10->NULL
	list1 = delete_first(list1);

	// list1�� ���
	printf("list1 = "); print_list(list1);

	//list2 = 11->22->33->44->�� �����. �̶� 11, 22, 33, 44�� ������ ��带 �����Ѵ�. // list2�� ���
	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);

	// list2�� ���
	printf("list2 = "); print_list(list2);

	// list2�� �� �� ��带 �����Ѵ�. ��, list2 = 11->22->33->
	remove_node(list2, 44);
	
	// list2�� ���
	printf("list2 = "); print_list(list2);

	//list2�� ������ list3�� ���� �ȴ�
	list3 = reverse(list2);

	//list3�� ����Ѵ�. 
	printf("list3 = "); print_list(list3);

	// list1 = 20->30->33->22->11->�� �����. ��, list1�� list3�� ���ļ� list1�� ����Ű�� �Ѵ�. 
	list1 = concat_list(list1, list3);

	//list1�� ����Ѵ�. 
	printf("list1 = "); print_list(list1);
	
	//(A) ����: ���⼭���ʹ� list1�� ����Ͽ� �Լ����� �׽�Ʈ���� 
	//list1�� 20�� ���� �ִ°�?
	if (is_in_list(list1, 20))
		printf("\nlist1�� 20�� �ִ�\n\n");
	else
		printf("\nlist1�� 20�� ����\n\n");

	//list1�� ��� ���� ��ȯ
	int length = get_length(list1);
	printf("list1�� ���̴� %d�̴�\n\n", length);

	//list�� ��� ������ ���� ���� ���� ��ȯ
	int sum = get_total(list1);
	printf("list1�� ������ %d�̴�\n\n", sum);

	//pos��ġ�� �ִ� ����� data ��ȯ
	int num = 1;
	int pos = get_entry(list1, num);
	printf("list�� %d��° ���� %d\n\n", num, pos);

	//key�� ���� ���� ��� �����ϱ� 
	int key = 22;
	delete_by_key(list1, key);
	printf("list1 = "); print_list(list1);

	//list1�� 3��°�� 50 �ֱ�
	insert_pos(list1, 3, 50);
	printf("\nlist1 = "); print_list(list1);

	//pos ��ġ�� ��带 ���� 
	delete_pos(list1, 3);
	printf("\nlist1 = "); print_list(list1);

}