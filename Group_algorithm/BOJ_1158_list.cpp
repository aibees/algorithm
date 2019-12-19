#include <iostream>

using namespace std;

class node {
public :
	int num;
	node* head;
	node* tail;	
};

class linkedList {
public :
	node* head;
	node* end;
	node* cursor;
	int size;

	linkedList() {
		this->head = new node();
		this->head->num = -1;
		this->head->head = NULL;
		this->head->tail = NULL;
		
		this->end = new node();
		this->end->num = -1;
		this->end->head = NULL;
		this->end->tail = NULL;
		
		this->cursor = this->head;
		size = 0;
	}
	
	int getSize() {
		return size;
	}
	
	void addToEnd(int num) {
		// list size increase
		this->size++;
		
		// create new node
		node* tmp = new node();
		tmp->num = num;
		
		// link with head / end
		if(this->size == 1) {
			this->head->tail = tmp;
			tmp->head = this->head;
			
			tmp->tail = this->end;
			this->end->head = tmp;
			return;	
		}
		else if(this->size > 1) {
			node* before = this->end->head;
			
			before->tail = tmp;
			tmp->head = before;
			
			tmp->tail = this->end;
			this->end->head = tmp;
			return;
		}
	}
	
	void addToHead(int num) {
		// list size increase
		this->size++;
		
		// create new node
		node* tmp = new node();
		tmp->num = num;
		
		// link with head / end
		if(this->size == 1) {
			this->head->tail = tmp;
			tmp->head = this->head;
			
			tmp->tail = this->end;
			this->end->head = tmp;
			return;	
		}
		else if(this->size > 1) {
			node* after = this->head->tail;
			
			after->head = tmp;
			tmp->tail = after;
			
			tmp->head = this->head;
			this->head->tail = tmp;
			return;
		}
	}
	
	int popHead() {
		this->size--;
		// extract first node
		node* first = this->head->tail;
		int ret = first->num;
		
		// eliminate from list
		node* firstNext = first->tail;
		delete first;
		
		this->head->tail = firstNext;
		firstNext->head = this->head;
		return ret;
	}
	
	int popEnd() {
		this->size--;
		// extract first node
		node* back = this->end->head;
		int ret = back->num;
		
		// eliminate from list
		node* backBefore = back->head;
		delete back;
		
		this->end->head = backBefore;
		backBefore->tail = this->end;
		return ret;
	}
	
	void printAll() {
		int idx = 0;
		this->cursor = this->head->tail;
		cout << '<';
		while(this->cursor->num != -1) {
			cout << this->cursor->num;
			if(idx < this->size - 1) {
				cout << ", ";
				idx++;
			}
			this->cursor = this->cursor->tail;
		}
		cout << ">\n";
	}
};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	linkedList* li = new linkedList();
	linkedList* answer = new linkedList();
	
	for(int i = 1; i <= n; i++) {
		li->addToEnd(i);
	}
	
	while(li->getSize() > 0) {
		int target = -1;
		for(int t = 0; t < k-1; t++) {
			target = li->popHead();
			li->addToEnd(target);
		}
		target = li->popHead();
		
		answer->addToEnd(target);
	}
	answer->printAll();
	return 0;
}
