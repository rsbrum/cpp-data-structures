#include <iostream>
using namespace std;

class LinkedList {
public:

	struct Node {
		int data;
		Node *next;
	};

	LinkedList(int data);
	void addItem(int data);
	void display();
	void displayHelper(Node *n);
	void pop();

private:
	Node *head;
	Node *tail;
};

LinkedList::LinkedList(int data)
{
	head = new Node;
	head->data = data;
	head->next = NULL;
	tail = head;
}

void LinkedList::addItem(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;

	tail->next = temp;
	tail = tail->next;
}

void LinkedList::pop()
{
	Node *temp = new Node;
	temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->next->next == NULL)
		{
			tail = temp;
			temp->next = NULL;
			break;
		}
	}
}

void LinkedList::display()
{
	displayHelper(head);
	cout << endl;
}

void LinkedList::displayHelper(Node *n)
{
	
	cout << n->data << " ";

	if (n->next == NULL)
		return;
	
	if(n != NULL)
		displayHelper(n->next);
}

int main()
{
	
	LinkedList l(1);

	l.addItem(2);
	l.addItem(3);
	l.addItem(4);
	l.display();
	l.pop();
	l.addItem(5);
	l.display();

	system("pause");
}