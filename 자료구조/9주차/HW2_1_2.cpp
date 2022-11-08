//LinkedQueue.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_QUEUE_SIZE 3
typedef struct {
	char gender;
	char name[20];
}element; // 요소의 타입

typedef struct QueueNode { // 큐의 노드의 타입
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct { // 큐 ADT 구현
	QueueNode* front, * rear;
} LinkedQueueType;

// 초기화 함수
void init(LinkedQueueType* q)
{
	q->front = q->rear = NULL;
}
// 공백 상태 검출 함수
int is_empty(LinkedQueueType* q)
{
	return (q->front == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedQueueType* q) // 항상 거짓, 포화상태일때가 없다. 연결리스트로 구현하였으므로
{
	return 0;
}
// 삽입 함수
void enqueue(LinkedQueueType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		printf("메모리를 할당할 수 없습니다");
	else {
		temp-> data = item; // 데이터 저장
		temp->link = NULL; // 링크 필드를 NULL
		if (is_empty(q)) { // 큐가 공백이면
			q->front = temp;
			q->rear = temp;
		}
		else { // 큐가 공백이 아니면
			q->rear->link = temp; // 순서가 중요
			q->rear = temp;
		}
	}
}
// 삭제 함수
element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q)) // 공백상태
		printf("큐가 비어 있습니다");
	else {
		item = temp->data; // 데이터를 꺼낸다.
		q->front = q->front->link; // front 를 다음노드를 가리키도록 한다.
		if (q->front == NULL) // 공백 상태
			q->rear = NULL;
		free(temp); // 동적메모리 해제
		return item; // 데이터 반환
	}
}
void print_queue(LinkedQueueType* q)
{
	QueueNode* p;
	for (p = q->front; p != NULL; p = p->link)
		printf("%s ", p->data.name);
	printf("\n");
}
//개수 체크 함수 
int get_count(LinkedQueueType* q) {
	QueueNode* p; int count = 0;
	for (p = q->front; p != NULL; p = p->link)
		count++;
	
	return count;
}

// 연결된 큐 테스트 함수
void main()
{
	LinkedQueueType manQ;
	LinkedQueueType womanQ;

	element newPerson;

	init(&manQ);
	init(&womanQ);

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