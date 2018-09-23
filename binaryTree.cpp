#include <iostream>
using namespace std;

struct Leaf
{
	int data;
	Leaf *right;
	Leaf *left;
};

class BinaryTree
{

public:
	BinaryTree(int data);
	void push(int data);
	void print();
	void pop(int key);

private:
	Leaf * newLeaf(int data);
	Leaf *root;
	Leaf *findKey(int key);
	void printHelper(Leaf *leaf);
	void noChildren(Leaf *leaf);
	void oneChild(Leaf *leaf);
	void twoChildren(Leaf *leaf);

};

BinaryTree::BinaryTree(int data)
{
	root = newLeaf(data);
}

Leaf *BinaryTree::newLeaf(int data)
{
	Leaf *temp = new Leaf;
	temp->data = data;
	temp->right = temp->left = NULL;

	return temp;
}

void BinaryTree::push(int data)
{
	Leaf *temp = root;

	while (temp != NULL)
	{

		if (data > temp->data)
		{
			if (temp->right == NULL)
			{
				temp->right = newLeaf(data);
				break;
			}

			temp = temp->right;
		}

		if (data < temp->data)
		{
			if (temp->left == NULL)
			{
				temp->left = newLeaf(data);
				break;
			}

			temp = temp->left;
		}
	}
}

void BinaryTree::print()
{
	printHelper(root);
}

void BinaryTree::printHelper(Leaf *leaf)
{
	
	if (leaf == NULL)
	{
		return;
	}
	
		printHelper(leaf->left);

		cout << leaf->data << endl;

		printHelper(leaf->right);
	

}

void BinaryTree::pop(int key)
{
	
	Leaf *keyNode = root;
	//finds parent of selected key
	while (keyNode->data != key)
	{
		if (keyNode->left != NULL )
		{
			if (keyNode->left->data == key)
			{
				break;
			}
		}

		if (keyNode->right != NULL)
		{
			if (keyNode->right->data == key)
			{
				break;
			}
		}

		if (key > keyNode->data)
			keyNode = keyNode->right;

		if (key < keyNode->data)
			keyNode = keyNode->left;

	}

	//no children
	if (keyNode->right != NULL) {
		if (keyNode->right->left == NULL && keyNode->right->right == NULL && keyNode->right->data == key)
		{
			delete keyNode->right;
			keyNode->right = NULL;
			return;
		}
	}

	if (keyNode->left != NULL) {
		if (keyNode->left->left == NULL && keyNode->left->right == NULL && keyNode->left->data == key)
		{
			delete keyNode->left;
			keyNode->left = NULL;
			return;
		}
	}

	//no need to know who is the parent anymore, find node that holds the key
	if (keyNode->right != NULL && keyNode->right->data == key)
	{
		keyNode = keyNode->right;
	}

	if (keyNode->left != NULL && keyNode->left->data == key)
	{
		keyNode = keyNode->left;
	}


	//one child
	if (keyNode->left == NULL && keyNode->right != NULL)
	{
		*keyNode = *keyNode->right;
		return;
	}
	
	if (keyNode->left != NULL && keyNode->right == NULL)
	{
		*keyNode = *keyNode->left;
		return;
	}
	
	//two children

	//right sub-tree
	//if first element to the right has no children
	if (keyNode->right->left == NULL && keyNode->right->right == NULL)
	{
		Leaf *temp = keyNode->right;
		temp->left = keyNode->left;
		*keyNode = *temp;
		delete temp;
		return;
	}

	//if first element to the right has only one child to the right
	if (keyNode->right->right != NULL && keyNode->right->left == NULL)
	{
		Leaf *temp = keyNode->right;
		temp->left = keyNode->left;
		*keyNode = *temp;
		delete temp;
		return;
	}

	//if first element to the right has one child to the left
	if (keyNode->right->left != NULL)
	{
		Leaf *toTheLeft = keyNode->right->left;
		//if child to the left has no child to the right
		if (toTheLeft->right == NULL)
		{
			while (toTheLeft->left != NULL)
			{
				if (toTheLeft->left->left == NULL)
				{
					break;
				}
				toTheLeft = toTheLeft->left;
			}

			toTheLeft->left->left = keyNode->left;
			toTheLeft->left->right = keyNode->right;
			*keyNode = *toTheLeft->left;
			delete toTheLeft->left;
			toTheLeft->left = NULL;
			return;
		}

		//if child to the left has a child to the right, find the parent of the leaf element from subtree
		if (toTheLeft->right != NULL)
		{
			Leaf *toTheLeftRight = toTheLeft;
			
			if (toTheLeftRight->right->right != NULL)
			{
				toTheLeftRight = toTheLeftRight->right;
				//find leafs parent
				while (toTheLeftRight->right != NULL )
				{
					if (toTheLeftRight->right != NULL)
					{
						if (toTheLeftRight->right->right == NULL && toTheLeftRight->right->left == NULL) {
							break;
						}
					}

					if (toTheLeftRight->left != NULL)
					{
						if (toTheLeftRight->left->right == NULL && toTheLeftRight->left->left == NULL) {
							break;
						}
					}

					if (toTheLeftRight->right == NULL && toTheLeftRight->left != NULL)
						toTheLeftRight = toTheLeftRight->left;
				
					if (toTheLeftRight->right != NULL && toTheLeftRight->left == NULL)
						toTheLeftRight = toTheLeftRight->right;
				}
			}
			else
			{
				
			}

			
			//swap
			Leaf *leaf = new Leaf;
			if (toTheLeftRight->right != NULL)
			{
				leaf = toTheLeftRight->right;
				toTheLeftRight->right = NULL;
			}

			if (toTheLeftRight->left != NULL)
			{
				leaf = toTheLeftRight->left;
				toTheLeftRight->left = NULL;
			}

			leaf->right = keyNode->right;
			leaf->left = keyNode->left;
			*keyNode = *leaf;
			delete leaf;
			
		}
	}
	

}

Leaf *BinaryTree::findKey(int key)
{
	Leaf *temp = new Leaf;
	return temp;
}

int main()
{
	BinaryTree t(10);
	t.push(15);
	t.push(14);
	t.push(20);
	t.push(17);
	t.push(16);
	t.push(19);
	t.push(18);
	t.push(25);
	t.push(21);
	t.pop(15);
	t.print();
	system("pause");
}