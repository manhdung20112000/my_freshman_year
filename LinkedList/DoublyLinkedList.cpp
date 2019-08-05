#include <iostream>

using namespace std;

class Node {
public: 
	int data;
	class Node* prev;
	class Node* next;
	Node(int _data, Node* _prev, Node* _next) {
		this->data = _data;
		this->prev = _prev;
		this->next = _next;
	}
};

class DoublyLinkedList {
public:
	Node* head;
	Node* tail;
	DoublyLinkedList() {
		this->head = this->tail = nullptr;
	}
	DoublyLinkedList& insertHead(int data);
	DoublyLinkedList& insertTail(int data);
	DoublyLinkedList& insertAt(int data, int position);
	DoublyLinkedList& deleteAt(int position);
	void print();
	void reversePrint();
};

DoublyLinkedList& DoublyLinkedList::insertHead(int data)
{
	bool isEmpty = head == nullptr;
	if (isEmpty) {
		head = new Node(data, nullptr, head);
		tail = head;
	}
	else {
		Node* newHead = new Node(data, nullptr, head);
		head->prev = newHead;
		head = newHead;
	}
	return *this;
}

DoublyLinkedList& DoublyLinkedList::insertTail(int data)
{
	Node* newTail = new Node(data, tail, nullptr);
	if (head == nullptr) {
		head = newTail;
		tail = head;
		return *this;
	}
	else {
		tail->next = newTail;
		//newTail->prev = tail;
		tail = newTail;
	}
	return *this;
}

DoublyLinkedList& DoublyLinkedList::insertAt(int data, int position)
{
	Node* newNode = new Node(data, nullptr, nullptr);
	Node* front = head;
	Node* back = head->next;
	for (int i = 0; i < position - 1; i++) {
		front = front->next;
		back = back->next;
	}
	front->next = newNode;
	back->prev = newNode;
	newNode->prev = front;
	newNode->next = back;
	return *this;
}

DoublyLinkedList& DoublyLinkedList::deleteAt(int position)
{ 
	Node* front = head;
	Node* back = head->next->next;
	for (int i = 0; i < position - 1; i++) {
		front = front->next;
		back = back->next;
	}
	front->next = back;
	back->prev = front;
	return *this;
	return *this;
}

void DoublyLinkedList::print()
{
	cout << "head-->";
	for (Node* index = head; index != nullptr; index = index->next) {
		cout << index->data << "-->";
		if (index->next == nullptr) cout << "tail";
	}
}

void DoublyLinkedList::reversePrint()
{
	cout << "tail<--";
	for (Node* pointer = tail; pointer != nullptr; pointer = pointer->prev) {
		cout << pointer->data << "<--";
		if (pointer->prev == nullptr) cout << "head";
	}
}

int main() {
	DoublyLinkedList list;
	for (int i = 0; i < 10; i++) {
		list.insertHead(i);
	}
	for (int i = 0; i < 10; i++) {
		list.insertTail(i);
	}
	list.insertAt(1000, 3);
	list.deleteAt(5);
	list.print();
	cout << endl << endl;
	list.reversePrint();
	return 0;
}


