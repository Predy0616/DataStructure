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
