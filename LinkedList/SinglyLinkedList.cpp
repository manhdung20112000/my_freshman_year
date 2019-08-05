#include <iostream>
using namespace std;

class Node {
public:
	int data;
	class Node* next;
	Node(int _data, Node* _next) {
		this->data = _data;
		this->next = _next;
	}
};

class SinglyLinkedList {
public:
	Node* head;
	Node* tail;
	SinglyLinkedList() {
		this->head = this->tail = nullptr;
	}
	int getLength();
	SinglyLinkedList& insertHead(int data);
	SinglyLinkedList& insertTail(int data);
	SinglyLinkedList& insertAt(int data, int position);
	SinglyLinkedList& deleteAt(int position);
	SinglyLinkedList& deleteAtHead();
	SinglyLinkedList& deleteAtTail();
	void print();
};

void SinglyLinkedList::print()
{
	cout << "head-->";
	for (Node* index = head; index != nullptr; index = index->next) {
		cout << index->data << "-->";
		if (index->next == nullptr) cout << "tail";
	}
}

int SinglyLinkedList::getLength()
{
	int length = 0;
	for (Node* p = head; p != nullptr; p = p->next) {
		++length;
	}
	return length;
}

SinglyLinkedList& SinglyLinkedList::insertHead(int data)
{
	bool isEmpty = head == nullptr;
	head = new Node(data, head);
	if (isEmpty) {
		tail = head;
		//cout << "tail is " << tail->data;
	}
	return *this;
}

SinglyLinkedList& SinglyLinkedList::insertTail(int data)
{
	Node* newNode = new Node(data, nullptr);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	return *this;
}

SinglyLinkedList& SinglyLinkedList::insertAt(int data, int position)
{
	Node* newNode = new Node(data, nullptr);
	Node* front = head;
	Node* back = head->next;
	for (int i = 0; i < position-1; i++) {
		if (front->next != nullptr and back->next != nullptr) {
			front = front->next;
			back = back->next;
		}
		else return *this;
	}
	front->next = newNode;
	newNode->next = back;
	return *this;
}

SinglyLinkedList& SinglyLinkedList::deleteAt(int position)
{
	Node* font = head;
	Node* back = head->next->next;
	for (int i = 0; i < position - 1; i++) {
		font = font->next;
		back = back->next;
	}
	font->next = back;
	return *this;
}

SinglyLinkedList& SinglyLinkedList::deleteAtHead()
{
	head = head->next;
	return *this;
}

SinglyLinkedList& SinglyLinkedList::deleteAtTail()
{
	int linkedListLength = getLength();
	Node* newTail = head;
	for (int i = 0; i < linkedListLength-2; i++) {
		newTail = newTail->next;
	}
	newTail->next = nullptr;
	return *this;
}


int main() {
	SinglyLinkedList list;
	for (int i = 0; i < 100; i++) {
		list.insertHead(i);
	}
	list.insertAt(10000, 3);
	list.deleteAt(3);
	list.deleteAtHead();
	list.deleteAtTail();
	list.print();
	return 0;
}
