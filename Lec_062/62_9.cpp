// Reverse Level Order Traversal using stack and queue

// This approach is adopted from following link
// http://tech-queries.blogspot.in/2008/12/level-order-tree-traversal-in-reverse.html

#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

void reverseLevelOrder(node* root) {
	stack <node *> S;
	queue <node *> Q;
	Q.push(root);

	// Do something like normal level order traversal order. Following are the
	// differences with normal level order traversal
	// 1) Instead of printing a node, we push the node to stack
	// 2) Right subtree is visited before left subtree
	while (Q.empty() == false) {
		root = Q.front();
		Q.pop();
		S.push(root);

		if (root->right)
			Q.push(root->right);  // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
		
		if (root->left)
			Q.push(root->left);
	}

	// Now pop all items from stack one by one and print them
	while (S.empty() == false) {
		root = S.top();
		cout << root->data << " ";
		S.pop();
	}
}


node* newNode(int data) {
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return (temp);
}


int main() {
	struct node *root = newNode(1);
	root->left	 = newNode(2);
	root->right	 = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	cout << "Level Order traversal of binary tree is \n";
	reverseLevelOrder(root);

	return 0;
}



// Output :-

// Level Order traversal of binary tree is 
// 4 5 6 7 2 3 1 