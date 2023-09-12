#pragma once
#include <iostream>
using namespace std;

template <class T> class MyTree {
public:
	class Node {
	public:
		int key;
		T value;
		Node* left = NULL;
		Node* right = NULL;
	};
	class Iterator {
	private:
		Node* root = NULL;
		Node* now = NULL;
		int stepNode = 0;
		int step(int s, Node* r);
		int size;
	public:
		bool status = true;
		Iterator(Node* r, int size);
		Iterator& operator++();
		Iterator operator++(int);
		Iterator& operator--();
		Iterator operator--(int);
		T operator*() const;
		bool operator==(Iterator other) const;
		bool operator!=(Iterator other) const;
		Iterator begin();
		Iterator end();
		int getSize();
	};
	class ReverseIterator {
	private:
		Node* root = NULL;
		Node* now = NULL;
		int stepNode = 0;
		int step(int s, Node* r);
		int size;
	public:
		bool status = true;
		ReverseIterator(Node* r, int size);
		ReverseIterator& operator++();
		ReverseIterator operator++(int);
		ReverseIterator& operator--();
		ReverseIterator operator--(int);
		T operator*() const;
		bool operator==(ReverseIterator other) const;
		bool operator!=(ReverseIterator other) const;
		ReverseIterator begin();
		ReverseIterator end();
		int getSize();
	};
	MyTree();
	MyTree(MyTree &mytree);
	~MyTree();
	int getSize() { return size; };
	int clearTree(Node* r);
	bool isEmpty();
	T getValueByKey(T h, int key, Node* r);
	int updateValueByKey(int key, T value, Node* r);
	void add(int key, T value, Node* r);
	Node *deleteNodeByKey(int key, Node *r);
	Node* del(Node* r, Node* r1);
	int printKeyList(Node* r);
	int printTree(Node* r, int level);
	Node *getRoot() { return root; };
	bool searchKey(int key, Node* r);
	int getHeight(int h, Node* r);
	int getLastIteration();
	void clearLastIteration();
	Iterator begin();
	Iterator end();
	ReverseIterator rbegin();
	ReverseIterator rend();
private:
	int copyTree(Node* r);
	int size;
	Node* root = NULL;
	int iterations;
};

template <class T> MyTree<T>::MyTree() {
	size = 0;
	iterations = 0;
}

template <class T> MyTree<T>::MyTree(MyTree &mytree) {
	if (!isEmpty()) {
		clearTree(root);
	}
	copyTree(mytree.getRoot());
}

template <class T> MyTree<T>::~MyTree() {
	clearTree(root);
}

template <class T> int MyTree<T>::clearTree(Node* r) {
	if (r == NULL) {
		return 0;
	}
	clearTree(r->left);
	clearTree(r->right);
	deleteNodeByKey(r->key, root);
	size = 0;
}

template <class T> bool MyTree<T>::isEmpty() {
	if (root == NULL) {
		return true;
	}
	else {
		return false;
	}
}

template <class T> T MyTree<T>::getValueByKey(T h, int key, Node* r) {
	if (r == NULL) {
		return 0;
	}
	h = getValueByKey(h, key, r->left);
	h = getValueByKey(h, key, r->right);
	if (r->key == key) {
		return r->value;
	}
	return h;
}

template <class T> int MyTree<T>::updateValueByKey(int key, T value, Node* r) { 
	if (r == NULL) {
		return 0;
	}
	updateValueByKey(key, value, r->left);
	updateValueByKey(key, value, r->right);
	if (r->key == key) {
		r->value = value;
	}
}

template <class T> void MyTree<T>::add(int key, T value, Node* r) {
		bool ins = false;
		iterations++;
		if (root == NULL) {
			root = new Node;
			root->key = key;
			root->value = value;
			ins = true;
			size++;
		}

		if (!ins) {
			if (key < r->key) {
				if (r->left == NULL) {
					r->left = new Node;
					r->left->key = key;
					r->left->value = value;
					ins = true;
					size++;
				}
				else {
					add(key, value, r->left);
				}
			}
			else {
				if (r->right == NULL) {
					r->right = new Node;
					r->right->key = key;
					r->right->value = value;
					ins = true;
					size++;
				}
				else {
					add(key, value, r->right);
				}
			}
		}
}

template <class T> typename MyTree<T>::Node* MyTree<T>::deleteNodeByKey(int key, Node *r) {
	Node* x;
	iterations++;
	if (r == root and r->left == NULL and r->right == NULL) {
		root = NULL;
	}
	if (r == NULL) {
		return r;
	}
	if (key < r->key) {
		r->left = deleteNodeByKey(key, r->left);
		return r;
	}
	if (key > r->key) {
		r->right = deleteNodeByKey(key, r->right);
		return r;
	}
	if (r->left == NULL and r->right == NULL) {
		delete[] r;
		size--;
		return NULL;
	}
	if (r->left == NULL) {
		x = r->right;
		delete[] r;
		size--;
		return x;
	}
	if (r->right == NULL) {
		x = r->left;
		delete[] r;
		size--;
		return x;
	}
	r->right = del(r->right, r);
	return r;
}

template <class T> typename MyTree<T>::Node* MyTree<T>::del(Node* r, Node* r1) {
	if (r->left != NULL) {
		r->left = del(r->left, r1);
		return r;
	}
	r1->key = r->key;
	r1->value = r->value;
	Node* x = r->right;
	delete[] r;
	return x;
}

template <class T> int MyTree<T>::printKeyList(Node* r) {
	if (r == NULL) {
		return 0;
	}
	printKeyList(r->left);
	printKeyList(r->right);
	cout << r->key << " ";
	if (r == root) {
		cout << endl;
	}
}

template <class T> int MyTree<T>::printTree(Node* r, int level) {
	if (r == NULL) {
		return 0;
	}
	printTree(r->right, level + 1);
	for (int i = 0; i < 3 * level; i++) {
		cout << " ";
	}
	cout << r->key;
	cout << endl;
	printTree(r->left, level + 1);
}

template <class T> int MyTree<T>::getHeight(int h, Node* r) {
	if (r == NULL) {
		return h;
	}
	h++;
	if (getHeight(h, r->right) > getHeight(h, r->left)) {
		return getHeight(h, r->right);
	}
	else {
		return getHeight(h, r->left);
	}
}

template <class T> int MyTree<T>::getLastIteration() {
	return iterations;
}

template <class T> void MyTree<T>::clearLastIteration() {
	iterations = 0;
}

template <class T> typename MyTree<T>::Iterator MyTree<T>::begin() {
	Iterator iter(root, size);
	return iter;
}

template <class T> typename MyTree<T>::Iterator MyTree<T>::end() {
	Iterator iter(root, size);
	iter = iter.end();
	return iter;
}


template <class T> typename MyTree<T>::ReverseIterator MyTree<T>::rbegin() {
	ReverseIterator iter(root, size);
	return iter;
}

template <class T> typename MyTree<T>::ReverseIterator MyTree<T>::rend() {
	ReverseIterator iter(root, size);
	iter = iter.end();
	return iter;
}

template <class T> int MyTree<T>::copyTree(typename MyTree<T>::Node *r) {
	if (r == NULL) {
		return 0;
	}
	add(r->key, r->value, root);
	copyTree(r->right);
	copyTree(r->left);

template <class T> bool MyTree<T>::searchKey(int key, Node* r) {
	iterations++;
	if (r == NULL) {
		return false;
	}

	if (r->key == key) {
		return true;
	}

	if (key < r->key) {
		return searchKey(key, r->left);
	}

	if (key > r->key) {
		return searchKey(key, r->right);
	}
}

template <class T> MyTree<T>::Iterator::Iterator(Node *r, int size) {
	this->root = r;
	this->size = size;
	stepNode++;
	step(stepNode, root);
};

template <class T> typename MyTree<T>::Iterator& MyTree<T>::Iterator::operator++() {
	if (status) {
		if (stepNode == size) {
			status = false;
		}
		if (stepNode < size) {
			stepNode++;
			step(stepNode, root);
		}
	}
	else {
		cout << "Iterator is not installed" << endl;
	}
	return *this;
}

template <class T> typename MyTree<T>::Iterator MyTree<T>::Iterator::operator++(int) {
	if (status) {
		if (stepNode == size) {
			status = false;
		}
		if (stepNode < size) {
			stepNode++;
			step(stepNode, root);
		}
	}
	else {
		cout << "Iterator is not installed" << endl;
	}
	return *this;
}

template <class T> typename MyTree<T>::Iterator& MyTree<T>::Iterator::operator--() {
	if (status) {
		if (stepNode > 1) {
			stepNode--;
			step(stepNode, root);
		}
	}
	else {
		cout << "Iterator is not installed" << endl;
	}
	return *this;
}

template <class T> typename MyTree<T>::Iterator MyTree<T>::Iterator::operator--(int) {
	if (status) {
		if (stepNode > 1) {
			stepNode--;
			step(stepNode, root);
		}
	}
	else {
		cout << "Iterator is not installed" << endl;
	}
	return *this;
}

template <class T> bool MyTree<T>::Iterator::operator==(MyTree<T>::Iterator other) const {
	return now->key == other.now->key;
}

template <class T> bool  MyTree<T>::Iterator::operator!=(MyTree<T>::Iterator other) const {
	return !(*this == other);
}

template <class T> T  MyTree<T>::Iterator::operator*() const {
	if (status) {
		return now->key;
	}
	else {
		cout << "Iterator is not installed" << endl;
		return NULL;
	}
}

template <class T>  typename MyTree<T>::Iterator  MyTree<T>::Iterator::begin() {
	status = true;
	stepNode = 1;
	step(stepNode, root);
	return *this;
}

template <class T> typename MyTree<T>::Iterator  MyTree<T>::Iterator::end() {
	status = true;
	stepNode = size;
	step(stepNode, root);
	return *this;
}

template <class T> int MyTree<T>::Iterator::step(int s, typename MyTree<T>::Node* r) {
	if (r == NULL) {
		return s;
	}
	s = step(s, r->left);
	s--;
	if (s == 0) {
		this->now = r;
	}
	s = step(s, r->right);
	return s;
}

template <class T> int MyTree<T>::Iterator::getSize() {
	return size;
}

template <class T>  MyTree<T>::ReverseIterator::ReverseIterator(Node* r, int size) {
	this->root = r;
	this->size = size;
	stepNode = size;
	step(stepNode, root);
};

template <class T> typename  MyTree<T>::ReverseIterator& MyTree<T>::ReverseIterator::operator++() {
	if (status) {
		if (stepNode == 1) {
			status = false;
		}
		if (stepNode > 1) {
			stepNode--;
			step(stepNode, root);
		}
	}
	else {
		cout << "Iterator is not installed" << endl;
	}
	return *this;
}

template <class T> typename  MyTree<T>::ReverseIterator  MyTree<T>::ReverseIterator::operator++(int) {
	if (status) {
		if (stepNode == 1) {
			status = false;
		}
		if (stepNode > 1) {
			stepNode--;
			step(stepNode, root);
		}
	}
	else {
		cout << "Iterator is not installed" << endl;
	}
	return *this;
}

template <class T> typename MyTree<T>::ReverseIterator& MyTree<T>::ReverseIterator::operator--() {
	if (status) {
		if (stepNode < size) {
			stepNode++;
			step(stepNode, root);
		}
	}
	else {
		cout << "Iterator is not installed" << endl;
	}
	return *this;
}

template <class T> typename MyTree<T>::ReverseIterator MyTree<T>::ReverseIterator::operator--(int) {
	if (status) {
		if (stepNode < size) {
			stepNode++;
			step(stepNode, root);
		}
	}
	else {
		cout << "Iterator is not installed" << endl;
	}
	return *this;
}

template <class T> bool MyTree<T>::ReverseIterator::operator==(MyTree<T>::ReverseIterator other) const {
	return now->key == other.now->key;
}

template <class T> bool MyTree<T>::ReverseIterator::operator!=(MyTree<T>::ReverseIterator other) const {
	return !(*this == other);
}

template <class T> T MyTree<T>::ReverseIterator::operator*() const {
	if (status) {
		return now->key;
	}
	else {
		cout << "Iterator is not installed" << endl;
		return NULL;
	}
}

template <class T> typename MyTree<T>::ReverseIterator MyTree<T>::ReverseIterator::begin() {
	status = true;
	stepNode = size;
	step(stepNode, root);
	return *this;
}

template <class T> typename MyTree<T>::ReverseIterator MyTree<T>::ReverseIterator::end() {
	status = true;
	stepNode = 1;
	step(stepNode, root);
	return *this;
}

template <class T> int MyTree<T>::ReverseIterator::step(int s, typename MyTree<T>::Node* r) {
	if (r == NULL) {
		return s;
	}
	s = step(s, r->left);
	s--;
	if (s == 0) {
		this->now = r;
	}
	s = step(s, r->right);
	return s;
}

template <class T> int MyTree<T>::ReverseIterator::getSize() {
	return size;
}
