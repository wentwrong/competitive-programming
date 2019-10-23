// http://acm.timus.ru/problem.aspx?num=1136
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

struct Node {
	uint16_t value;
	Node *left, *right;
};

Node* bst_root;

uint16_t n, a[3000];

Node* bst_new_node(uint16_t value) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->value = value;
	return new_node;
}

void bst_insert(uint16_t value) {
	Node *curr = bst_root, 
		 *prev_curr = NULL,
		 *new_node = bst_new_node(value);
	
	while(curr) {
		prev_curr = curr;
		if(value > curr->value)
			curr = curr->right;
		else
			curr = curr->left;
	}
	
	if(prev_curr) {
		if(value > prev_curr->value)
			prev_curr->right = new_node;
		else
			prev_curr->left = new_node;
	} else {
		bst_root = new_node;
	}
}

void bst_print(Node* curr) {
	if(curr) {
		bst_print(curr->right);
		bst_print(curr->left);
		printf("%hu\n", curr->value);
	}
}

int main()
{	
	scanf("%hu", &n);
	
	for(uint16_t i = 0; i < n; i++)
		scanf("%hu", &a[i]);
	
	while(n--)
		bst_insert(a[n]);
	
	bst_print(bst_root);
	
	return 0;
}

