#include <iostream>
using namespace std;

class Queue {
public:
	struct Node {
		int data;
		Node *next;
		Node *prev;
	};

	Queue(int data);
	void push(int data);
	void pop();
	void display();
	bool isEmpty();

private:
	int cap;
	Node *head;
	Node *tail;
};

Queue::Queue(int data)
{
	head = new Node;
	cap = 0;
	head->data = data;
	head->next = head->prev = NULL;
	tail = head;
}

void Queue::push(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->next = NULL; 
	temp->prev = tail;
	tail->next = temp;
	tail = temp;
	cap++;
}

void Queue::pop()
{
	if (!isEmpty())
		head = head->next;
	else
		cout << "Queue is empty!" << endl;
}

void Queue::display()
{
	Node *temp = new Node;
	temp = head;

	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	delete temp;
}

bool Queue::isEmpty()
{
	return head == NULL;
}

int main() 
{
	Queue q(1);
	q.push(2);
	q.pop();
	q.pop();
	q.pop();
	q.display();
	system("pause");
}