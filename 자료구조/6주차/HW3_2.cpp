#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_LIS_SIZE 100

typedef int element;
typedef struct listNode {
	element data;
	struct listNode *link;
}ListNode;

//item이 List에 있는지 확인하는 함수
int is_in_list(ListNode* head, element item) {
	ListNode *p = head;

	while (p != NULL) {
		if (p->data == item)
			return true;
		p = p->link;
	}
	return false;
}

//List의 길이를 반환하는 함수
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

//List의 총합을 반환하는 함수
int get_total(ListNode* head) {
	ListNode* p = head;
	
	int sum = 0;
	while (p != NULL) {
		sum += p->data;
		p = p->link;
	}
	return sum;
}

//pos위치에 있는 value를 반환하는 함수 
element get_entry(ListNode* head, int pos) {
	ListNode* p = head;

	for (int count = 0; count == pos; count++) {
		p = p->link;
	}
	return p->data;
}

//key값을 가지고 있는 node 삭제 
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

//pos위치에 value 값을 넣는 함수
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

//pos위치의 node를 삭제하는 함수 
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

//맨 처음에 value 값을 넣는 함수 
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
//pre 뒤에 value 넣기 
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p -> data = value;
	p -> link = pre -> link;
	pre -> link = p;
	return head;
}

//맨 처음 값을 삭제 
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

//삭제 함수
void remove_node(ListNode* head, int x)
{
	ListNode* list = head;

	if (head == NULL)  return; 	// 삭제할 것이 없음
	else if (head->data == x) 	// 찾는 노드(삭제 노드)가 첫 노드인 경우 
	{      // delete list; free(list);
		head = head->link;
		return;
	}
	else 			// 나머지 경우
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

//list 출력 함수 
void print_list(ListNode* head){
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

//두 리스트를 합치는 함수 
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

//역순 만들기
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
	//list1 = 30->20->10->를 만든다. 이때 10, 20, 30의 순으로 노드를 삽입한다.
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	
	// list1을 출력
	printf("list1 = "); print_list(list1);

	//list1의 맨 앞 노드를 삭제한다 즉, list1 = 20->10->NULL
	list1 = delete_first(list1);

	// list1을 출력
	printf("list1 = "); print_list(list1);

	//list2 = 11->22->33->44->를 만든다. 이때 11, 22, 33, 44의 순으로 노드를 삽입한다. // list2를 출력
	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);

	// list2를 출력
	printf("list2 = "); print_list(list2);

	// list2의 맨 뒤 노드를 삭제한다. 즉, list2 = 11->22->33->
	remove_node(list2, 44);
	
	// list2를 출력
	printf("list2 = "); print_list(list2);

	//list2의 역행이 list3의 값이 된다
	list3 = reverse(list2);

	//list3를 출력한다. 
	printf("list3 = "); print_list(list3);

	// list1 = 20->30->33->22->11->를 만든다. 즉, list1과 list3를 합쳐서 list1이 가리키게 한다. 
	list1 = concat_list(list1, list3);

	//list1을 출력한다. 
	printf("list1 = "); print_list(list1);
	
	//(A) 주의: 여기서부터는 list1만 사용하여 함수들을 테스트하자 
	//list1에 20의 값이 있는가?
	if (is_in_list(list1, 20))
		printf("\nlist1에 20이 있다\n\n");
	else
		printf("\nlist1에 20이 없다\n\n");

	//list1의 노드 수를 반환
	int length = get_length(list1);
	printf("list1의 길이는 %d이다\n\n", length);

	//list의 모든 데이터 값을 더한 합을 반환
	int sum = get_total(list1);
	printf("list1의 총합은 %d이다\n\n", sum);

	//pos위치에 있는 노드의 data 반환
	int num = 1;
	int pos = get_entry(list1, num);
	printf("list의 %d번째 값은 %d\n\n", num, pos);

	//key의 값을 갖는 노드 삭제하기 
	int key = 22;
	delete_by_key(list1, key);
	printf("list1 = "); print_list(list1);

	//list1에 3번째에 50 넣기
	insert_pos(list1, 3, 50);
	printf("\nlist1 = "); print_list(list1);

	//pos 위치의 노드를 삭제 
	delete_pos(list1, 3);
	printf("\nlist1 = "); print_list(list1);

}