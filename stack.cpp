#include <iostream>
using namespace std;

class Stack
{

public:
	Stack(int size);
	bool isEmpty() const;
	bool isFull() const;
	int peek() const;
	void push(const int item);
	void pop();
	void display();

private:
	int maxSize;
	int counter;
	int *stack;
};


Stack::Stack(int size)
{
	maxSize = size;
	stack = new int[maxSize];
	counter = 0;
}

void Stack::push(int item)
{
	if (!isFull())
	{
		stack[counter] = item;
		counter++;
	}
}

void Stack::pop()
{
	if(!isEmpty())
		counter--;
}

int Stack::peek() const
{
	return stack[counter -1];
}

bool Stack::isEmpty() const
{
	return counter == 0;
}

bool Stack::isFull() const
{
	return counter == maxSize;
}

void Stack::display()
{
	for (int x = 0; x < counter; x++)
	{
		cout << stack[x] << " ";
	}
	cout << endl;

}

int main()
{
	Stack s(5);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.pop();
	s.display();
	system("pause");
}