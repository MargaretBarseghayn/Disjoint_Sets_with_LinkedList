// pr-1.cpp : Defines the entry point for the console application.

#include <iostream>
using namespace std;

class Node;
//set node

class Node1 {
public:
	Node* head_;
	int		size_;
	Node* tail_;
	Node1(Node* head, int size, Node* tail) :
		head_(head), size_(size), tail_(tail) {}
};
//regular node
class Node {
public:
	Node1* toInit_;
	int		element_;
	Node* next_;
	Node(Node1* toInit, int element, Node* next) :
		toInit_(toInit), element_(element), next_(next) {}
};

void make_set(Node* x)
{
	Node1* set = new Node1(x, 1, x);
	x->toInit_ = set;
	x->next_ = NULL;
}

Node* find_set(Node* x)
{
	return x->toInit_->head_;
}

void un_sets(Node* x, Node* y)
{
	if (x->toInit_->size_ < y->toInit_->size_)
		swap(x, y);

	x->toInit_->tail_->next_ = y->toInit_->head_;
	x->toInit_->size_ += y->toInit_->size_;
	x->toInit_->tail_ = y->toInit_->tail_;
	y = y->toInit_->head_;
	y->toInit_->head_ = y->toInit_->tail_ = 0;
	while (y) {
		y->toInit_ = x->toInit_;
		y = y->next_;
	}
}

void print(Node** x, int number)
{
	for (int i = 1; i <= number; i++)
	{
		cout << "leader(x[" << i << "]) = ";
		cout << "x[" << (x[i]->toInit_->head_->element_) << ']' << endl;
	}
	cout << endl;
}

