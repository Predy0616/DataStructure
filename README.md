# **DataStructure**
### **자료구조 (알고리즘)**
- ### 자료 구조를 이해하고 IDE의 도움없이도 C언어로 구현할 수 있어야 함
- ### 포인터를 얼마나 잘 이용하여 효율적으로 구성하는가
- ### 자료구조를 사용한 알고리즘 문제 풀이 능력
> ### 자료구조와 함께 배우는 알고리즘 입문, 종만북, 백준, 프로그래머스, SWEA, 인프런
<br>

## **계획**
- ### 자료구조 이해 -> c언어로 구현 -> 관련 예제 실습 -> 관련 알고리즘 학습
- ### 시간 날때마다 백준 문제 풀이 -> 플래티넘 달성 후 코드포스 진행 

<br><br>
# **자료구조**
### [1. 큐](#큐-queue)
### [2. 스택](#스택-stack)
### 3. 그래프
### [4. 트리](#트리-tree)
### 5. 우선순위 큐
### 6. 힙

<br><br>
# **큐 (Queue)**
### 먼저 집어 넣은 데이터가 먼저 나오는 FIFO(First In First Out) 구조
### 배열X 연결리스트로 구현

### **C**
```c
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
```

### **C++**
```cpp
#include<iostream>

using namespace std;

template <typename T>
class Queue {
public:
	struct Node { T data; Node *next; };
	int cnt;
	Node *front;
	Node *rear;

	Queue() {
		front = rear = NULL;
		cnt = 0;
	}

	bool empty() {
		if (cnt == 0) return true;
		return false;
	}

	void push(T data) {
		Node *newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		if (this->empty()) {
			front = newNode;
		}
		else {
			rear->next = newNode;
		}
		rear = newNode;
		cnt++;
	}

	T first() {
		if (cnt > 0) {
			return front->data;
		}
		return NULL;
	}

	T pop() {
		if (cnt > 0) {
			Node *temp = front;
			front = front->next;
			free(temp);
			cnt--;
			return front->data;
		}
		return NULL;
	}

	int size() {
		return cnt;
	}
};

int main() {
	Queue<int> q;
	q.push(1);
	cout << q.empty() << endl;
	q.push(2);
	cout << q.size() << endl;
	cout << q.first() << endl;
	q.pop();
	cout << q.first() << endl;
	return 0;
}
```

<br><br>
# **스택 (Stack)**
### 나중에 집어 넣은 데이터가 먼저 나오는 LIFO(Last In First Out) 구조
### 배열X 연결리스트로 구현

### **C**
```c
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
```

### **C++**
```cpp
#include<iostream>
using namespace std;

template <typename T>
class Stack {
public:
	typedef struct Node { T data; Node* Before; };
	Node* cur;
	int cnt;

	Stack() {
		cur = NULL;
		cnt = 0;
	}

	bool isEmpty() {
		if (cnt == 0) return true;
		return false;
	}

	void push(T data) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		if (isEmpty()) {
			cur = newNode;
		}
		else {
			newNode->Before = cur;
		}
		cur = newNode;
		cnt++;
	}

	T top() {
		return cur->data;
	}

	void pop() {
		if (cnt > 0) {
			cur = cur->Before;
			cnt--;
		}
	}

	int size() {
		return cnt;
	}
};


int main() {
	Stack<int> s;
	s.push(3);
	s.push(5);
	s.push(7);
	cout << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
}
```

<br><br>
# **트리 (Tree)**
### 그래프의 일종으로, 한 노드에서 시작해서 다른 정점들을 순회하여 자기 자신에게 돌아오는 순환이 없는 연결 그래프
### 배열X 연결리스트로 구현

### **C**
```c
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data, depth;
	Node* left;
	Node* right;
} Node;

/*
Node* queue[100];
int rear=0, front=0;

void printTree(Node* N) {
	queue[rear++] = N;
	while (rear == front) {
		Node* now = queue[front++];
		if (now->left != NULL) {
			queue[rear++] = now->left;
			
		}
		if (now->right != NULL) {
			queue[rear++] = now->right;

		}

	}

	return;
}
*/

int main() {
	Node* root = (Node*)malloc(sizeof(Node));
	root->data = 1;
	root->left->data = 2;
	root->right->data = 3;
	root->left->left->data = 4;
	root->left->right->data = 5;
	root->right->left->data = 6;
	root->right->right->data = 7;

	return 0;
}

/*
typedef struct Tree {
	Node* root;
	Node* last;
	int size;

} Tree;

void init(Tree* t) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	t->root = newNode;
	t->root->left = NULL;
	t->root->right = NULL;
	t->last = t->root;
	t->size = 1;
}

void insert(Tree* t, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (t->last->data == NULL) {
		t->last->data = data;
		t->last->left = newNode;
	}
	else if (t->last->left->data == NULL) {
		t->last->left->data = data;
		t->last->right = newNode;
	}
	else if (t->last->right->data == NULL) {
		t->last->right->data = data;
		if(t.last)
	}

}
*/
```

