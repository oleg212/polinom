#include <stdio.h>
#include <iostream>

using namespace std;

struct Node {
	Node* l, * r;
	int val;
	Node(int _val = 0, Node* _l = nullptr, Node* _r = nullptr):val(_val), l(l), r(r) {};
};
void print(Node* curr) {
	if (curr == nullptr) return;
	cout << curr->val;
	print(curr->l);
	print(curr->r);
}



int main() {






	return 0;
}