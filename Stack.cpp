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
