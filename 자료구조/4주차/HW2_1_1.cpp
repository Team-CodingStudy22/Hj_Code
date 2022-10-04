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

//오류 함수
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화 함수
void init(QueueType* q) {
	q->rear = 0;
	q->front = 0;
}

//출력 함수
void print_queue(QueueType* q) {
	for (int i = q->front+1; i <= q->rear; i++) 
			printf("%s ", q->data[i].name);
	printf("\n");
}

//포화 상태 체크 함수
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//공백 상태 체크 함수
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

//추가 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q)) 
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

//삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q)) 
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

//개수 체크 함수 
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

	printf("미팅 주선 프로그램입니다.\n");
	printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit>:");
	scanf(" %c", &answer);

	while (answer != 'q') {
		switch (answer) {
			case 'i':
				printf("이름을 입력 : ");
				scanf("%s", newPerson.name);

				printf("성별을 입력<m or f> : ");
				scanf(" %c", &newPerson.gender);

				if (newPerson.gender == 'm') {
					if (is_empty(&womanQ) && is_full(&manQ)) {
						printf("아직 대상자가 없습니다. 대기자가 꽉찼으니 담기회를 이용...\n\n");
					}
					else if (is_empty(&womanQ)) {
						printf("아직 대상자가 없습니다. 기다려주십시요.\n\n");
						enqueue(&manQ, newPerson);
					}
					else {
						element woman = dequeue(&womanQ);
						printf("커플이 탄생했습니다! %s과 %s\n\n", newPerson.name, woman.name);
					}
				}
				else {
					if (is_empty(&manQ) && is_full(&womanQ)) {
						printf("아직 대상자가 없습니다. 대기자가 꽉찼으니 담기회를 이용...\n\n");
					}
					else if (is_empty(&manQ)) {
						printf("아직 대상자가 없습니다. 기다려주십시요.\n\n");
						enqueue(&womanQ, newPerson);
					}
					else {
						element man = dequeue(&manQ);
						printf("커플이 탄생했습니다! %s과 %s\n\n", newPerson.name, man.name);
					}
				}
				break;

			case 'c':
				printf("남성 대기자 %d명 : ", get_count(&manQ));
				print_queue(&manQ);
				printf("여성 대기자 %d명 : ", get_count(&womanQ));
				print_queue(&womanQ);
				printf("\n");
				break;
		}

		printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit> : ");
		scanf(" %c", &answer);
	}

}
