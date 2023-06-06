#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	Node* Before;
}Node;

typedef struct Stack {
	Node* cur;
	int cnt;
}Stack;

void init(Stack* s) {
	s->cur = NULL;
	s->cnt = 0;
}

bool isEmpty(Stack* s) {
	if (s->cnt == 0) return true;
	return false;
}

void push(Stack* s, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (isEmpty(s)) {
		s->cur = newNode;
	}
	else {
		newNode->Before = s->cur;
	}
	s->cur = newNode;
	s->cnt++;
}

int top(Stack* s) {
	return s->cur->data;
}

void pop(Stack* s) {
	if (s->cnt > 0) {
		printf("%d\n", s->cur->data);
		s->cur = s->cur->Before;
		s->cnt--;
	}
}

int size(Stack* s) {
	return s->cnt;
}

int main() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	init(s);
	push(s, 5);
	push(s, 7);
	push(s, 9);
	printf("%d\n", top(s));
	pop(s);
	printf("%d\n", size(s));
	printf("%d\n", top(s));
	pop(s);
	printf("%d\n", top(s));
	pop(s);
	printf("%d\n", size(s));
	pop(s);
}
