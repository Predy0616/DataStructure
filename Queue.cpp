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
