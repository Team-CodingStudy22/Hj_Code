#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3

typedef struct {
	char gender;
	char name[20];
} element;


typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

//���� �Լ�
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//�ʱ�ȭ �Լ�
void init(QueueType* q) {
	q->rear = 0;
	q->front = 0;
}

//��� �Լ�
void print_queue(QueueType* q) {
	for (int i = q->front+1; i <= q->rear; i++) 
			printf("%s ", q->data[i].name);
	printf("\n");
}

//��ȭ ���� üũ �Լ�
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//���� ���� üũ �Լ�
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

//�߰� �Լ�
void enqueue(QueueType* q, element item) {
	if (is_full(q)) 
		error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

//���� �Լ�
element dequeue(QueueType* q) {
	if (is_empty(q)) 
		error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

//���� üũ �Լ� 
int get_count(QueueType* q) {
	int num = (q->rear) % MAX_QUEUE_SIZE - (q->front) % MAX_QUEUE_SIZE;
	return num;
}

int main(void) {

	QueueType manQ;
	QueueType womanQ;
	element newPerson;

	init(&manQ);
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
