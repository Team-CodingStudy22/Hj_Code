//LinkedQueue.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_QUEUE_SIZE 3
typedef struct {
	char gender;
	char name[20];
}element; // ����� Ÿ��

typedef struct QueueNode { // ť�� ����� Ÿ��
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct { // ť ADT ����
	QueueNode* front, * rear;
} LinkedQueueType;

// �ʱ�ȭ �Լ�
void init(LinkedQueueType* q)
{
	q->front = q->rear = NULL;
}
// ���� ���� ���� �Լ�
int is_empty(LinkedQueueType* q)
{
	return (q->front == NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(LinkedQueueType* q) // �׻� ����, ��ȭ�����϶��� ����. ���Ḯ��Ʈ�� �����Ͽ����Ƿ�
{
	return 0;
}
// ���� �Լ�
void enqueue(LinkedQueueType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		printf("�޸𸮸� �Ҵ��� �� �����ϴ�");
	else {
		temp-> data = item; // ������ ����
		temp->link = NULL; // ��ũ �ʵ带 NULL
		if (is_empty(q)) { // ť�� �����̸�
			q->front = temp;
			q->rear = temp;
		}
		else { // ť�� ������ �ƴϸ�
			q->rear->link = temp; // ������ �߿�
			q->rear = temp;
		}
	}
}
// ���� �Լ�
element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q)) // �������
		printf("ť�� ��� �ֽ��ϴ�");
	else {
		item = temp->data; // �����͸� ������.
		q->front = q->front->link; // front �� ������带 ����Ű���� �Ѵ�.
		if (q->front == NULL) // ���� ����
			q->rear = NULL;
		free(temp); // �����޸� ����
		return item; // ������ ��ȯ
	}
}
void print_queue(LinkedQueueType* q)
{
	QueueNode* p;
	for (p = q->front; p != NULL; p = p->link)
		printf("%s ", p->data.name);
	printf("\n");
}
//���� üũ �Լ� 
int get_count(LinkedQueueType* q) {
	QueueNode* p; int count = 0;
	for (p = q->front; p != NULL; p = p->link)
		count++;
	
	return count;
}

// ����� ť �׽�Ʈ �Լ�
void main()
{
	LinkedQueueType manQ;
	LinkedQueueType womanQ;

	element newPerson;

	init(&manQ);
	init(&womanQ);

	char answer;

	printf("���� �ּ� ���α׷��Դϴ�.\n");
	printf("i<nsert, ���Է�>, c<heck, ����� üũ>, q<uit>:");
	scanf(" %c", &answer);

	while (answer != 'q') {
		switch (answer) {
		case 'i':
			printf("�̸��� �Է� : ");
			scanf("%s", newPerson.name);

			printf("������ �Է�<m or f> : ");
			scanf(" %c", &newPerson.gender);

			if (newPerson.gender == 'm') {
				if (is_empty(&womanQ) && is_full(&manQ)) {
					printf("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� ���ȸ�� �̿�...\n\n");
				}
				else if (is_empty(&womanQ)) {
					printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n\n");
					enqueue(&manQ, newPerson);
				}
				else {
					element woman = dequeue(&womanQ);
					printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n\n", newPerson.name, woman.name);
				}
			}
			else {
				if (is_empty(&manQ) && is_full(&womanQ)) {
					printf("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� ���ȸ�� �̿�...\n\n");
				}
				else if (is_empty(&manQ)) {
					printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n\n");
					enqueue(&womanQ, newPerson);
				}
				else {
					element man = dequeue(&manQ);
					printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n\n", newPerson.name, man.name);
				}
			}
			break;

		case 'c':
			printf("���� ����� %d�� : ", get_count(&manQ));
			print_queue(&manQ);
			printf("���� ����� %d�� : ", get_count(&womanQ));
			print_queue(&womanQ);
			printf("\n");
			break;
		}

		printf("i<nsert, ���Է�>, c<heck, ����� üũ>, q<uit> : ");
		scanf(" %c", &answer);
	}

}