#include<stdio.h>
#include<stdlib.h>

typedef struct Node {		//노드 자신의 데이터와 다음 노드를 가리키는 포인터
	int data;
	Node* next;
}Node;

typedef struct Queue {
	Node* front;		//큐의 첫번째 노드를 가리키는 포인터
	Node* rear;		//큐의 마지막 노드를 가리키는 포인터
	int cnt;		//큐의 노드 개수
}Queue;

void init(Queue* q) {		//c++ 이라면 생성자에
	q->rear = q->front = NULL;
	q->cnt = 0;
}

bool isempty(Queue* q) {
	if (q->cnt == 0) return true;
	return false;
}

void enqueue(Queue* q, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));	//새로운 노드를 동적할당
	newNode->data = data;				//큐에 넣을 데이터를 동적할당한 노드에 넣음
	newNode->next = NULL;
	if (isempty(q)) {
		q->front = newNode;			//큐가 비어있다면 가장 앞 노드를 newNode로 지정
	}
	else {
		q->rear->next = newNode;		//이미 있다면 기존 큐의 마지막 노드의 다음 노드를 newNode로 지정
	}
	q->rear = newNode;				//마지막 노드를 newNode로 지정
	q->cnt++;
}

int front(Queue* q) {
	return q->front->data;
}

int pop(Queue* q) {
	q->front = q->front->next;
	q->cnt--;
	return q->front->data;
}

int size(Queue* q) {
	return q->cnt;
}

int main() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	init(q);
	enqueue(q, 1);
	enqueue(q, 3);
	printf("size%d\n", size(q));
	enqueue(q, 4);
	printf("front%d\n", front(q));
	pop(q);
	printf("size%d\n", size(q));
	printf("front%d\n", front(q));
	enqueue(q, 6);
	printf("front%d\n", front(q));
	pop(q);
	printf("size%d\n", size(q));
	printf("front%d\n", front(q));
	enqueue(q, 8);
	printf("front%d\n", front(q));
	pop(q);
	printf("size%d\n", size(q));
	printf("front%d\n", front(q));
	enqueue(q, 9);
	printf("front%d\n", front(q));
	pop(q);
	printf("size%d\n", size(q));
	printf("front%d\n", front(q));
}
