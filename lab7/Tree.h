#pragma once

template <typename T>
class Node {
public:
	int value;
	Node* next;

	Node() {
		value = 0;
		next = nullptr;
	}

	Node(int value, Node* next): value(value), next(next) {}

	~Node() {
		delete this;
	}
};
template <typename T>
class TreeNode {
public:
	TreeNode<T>** children;
	T value;
	int numberOfChildren = 0;
	TreeNode() {
	}
};

template <typename T>
class Tree
{
	TreeNode<T>* root;
	int internalValue = 1;
public:

	void add_node(Node<T>* parentNode) {
		if (parentNode == nullptr) {
			TreeNode<T>* newNode = new TreeNode<T>();
			newNode->current = new Node<T>(internalValue++, nullptr);

			if (root != nullptr) {
				newNode->children[0] = root->current;
				newNode->numberOfChildren = 1;
			}

			root = newNode;
		}
	}
};

