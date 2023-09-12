#pragma once
#include <iostream>
#include "MyTree.h"
using namespace std;

class Menu {
private:
public:
	void start();
	template <typename T> void create(MyTree<T>& myTree);
	template <typename T> void fillTree(MyTree<T>& myTree) {};
	template <typename T> void randomFillTree(MyTree<T>& myTree) {};
	template <typename T> void printTree(MyTree<T>& myTree) {};
	template <typename T> void printKeyList(MyTree<T>& myTree) {};
	template <typename T> void addByKey(MyTree<T>& myTree) {};
	template <typename T> void deleteNodeByKey(MyTree<T>& myTree) {};
	template <typename T> void updateValueByKey(MyTree<T>& myTree) {};
	template <typename T> void clearTree(MyTree<T>& myTree) {};
	template <typename T> void isTreeEmpty(MyTree<T>& myTree) {};
	template <typename T> void getValueByKey(MyTree<T>& myTree) {};
	template <typename T> void getBal(MyTree<T>& myTree) {};
	template <typename T> void getSize(MyTree<T>& myTree) {};
	template <typename T> void getMenuIterator(MyTree<T>& myTree) {};
	void menuIterator(typename MyTree<int>::Iterator& iterator);
	void menuReverseIterator(typename MyTree<int>::ReverseIterator& iterator);
	int getRandomNumber(int min, int max);
	int enterNumber(int min, int max);
	void testBigO(int n);
	void message(const char* mes);
	int searchBal(MyTree<int>& myTree, typename MyTree<int>::Node* r);
};

void Menu::start() {
	while (true) {
		bool exit = false;
		int action;
		cout << "Enter type data" << endl;
		cout << "1) int" << endl;
		cout << "2) exit" << endl;
		cout << "Enter action:" << endl;
		action = enterNumber(1, 2);
		MyTree<int> myTreeInt;
		cout << endl;

		switch (action) {
		case 1:
			create<int>(myTreeInt);
			break;
		case 2:
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		if (exit) {
			break;
		}
	}
}

template <typename T> void Menu::create(MyTree<T>& myTree) {
	MyTree<T> tree = myTree;
	int action;
	while (true) {
		bool exit = false;
		cout << "fill the tree:" << endl;
		cout << "1) random" << endl;
		cout << "2) add values" << endl;
		cout << "Enter action:" << endl;
		action = enterNumber(1, 2);
		cout << endl;

		switch (action) {
		case 1:
			randomFillTree(tree);
			exit = true;
			break;
		case 2:
			fillTree(tree);
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		if (exit) {
			break;
		}

		cout << endl;
	}

	while (true) {
		bool exit = false;
		int action;
		cout << "Menu:" << endl;
		cout << "1) print tree" << endl;
		cout << "2) print key list" << endl;
		cout << "3) add node" << endl;
		cout << "4) delete node by key" << endl;
		cout << "5) update value by key" << endl;
		cout << "6) get size" << endl;
		cout << "7) clear tree" << endl;
		cout << "8) tree is empty?" << endl;
		cout << "9) get value by key" << endl;
		cout << "10) get bal" << endl;
		cout << "11) menu iterator" << endl;
		cout << "12) exit" << endl;
		cout << "Enter action:" << endl;
		action = enterNumber(1, 12);
		cout << endl;

		switch (action) {
		case 1:
			printTree(tree);
			break;
		case 2:
			printKeyList(tree);
			break;
		case 3:
			addByKey(tree);
			break;
		case 4:
			deleteNodeByKey(tree);
			break;
		case 5:
			updateValueByKey(tree);
			break;
		case 6:
			getSize(tree);
			break;
		case 7:
			clearTree(tree);
			break;
		case 8:
			isTreeEmpty(tree);
			break;
		case 9:
			getValueByKey(tree);
			break;
		case 10:
			getBal(tree);
			break;
		case 11:
			getMenuIterator(tree);
			break;
		case 12:
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		cout << endl;

		if (exit) {
			break;
		}

		cout << endl;
	}
}

template <> void Menu::fillTree(MyTree<int>& myTree) {
	int size;
	while (true) {
		cout << "Enter size:" << endl;
		size = enterNumber(0, 2147483647);
		break;
	}
	int value;
	int key;
	for (int i = 0; i < size; i++) {
		while (true) {
			cout << "Enter key:" << endl;
			key = enterNumber(0, 2147483647);
			if (myTree.searchKey(key, myTree.getRoot())) {
				cout << "Error! This key exists" << endl;
			}
			else {
				break;
			}
		}
		cout << "Enter value:" << endl;
		value = enterNumber(0, 2147483647);
		myTree.add(key, value, myTree.getRoot());
	}
	message("Tree is filled");
	myTree.printTree(myTree.getRoot(), 1);
	cout << endl;
}

template <> void Menu::randomFillTree(MyTree<int>& myTree) {
	int size;
	while (true) {
		cout << "Enter size:" << endl;
		size = enterNumber(0, 2147483647);
		break;
	}
	for (int i = 0; i < size; i++) {
		int key;
		while (true) {
			key = getRandomNumber(1, size*5);
			if (!myTree.searchKey(key, myTree.getRoot())) {
				break;
			}
		}
		myTree.add(key, getRandomNumber(1, 100), myTree.getRoot());
	}
	message("Tree is filled");
	myTree.printTree(myTree.getRoot(), 1);
	cout << endl;
};

template <> void Menu::printTree(MyTree<int>& myTree) {
	if (!myTree.isEmpty()) {
		myTree.printTree(myTree.getRoot(), 1);
	}
	else {
		message("Tree is empty!");
	}
}

template <> void Menu::getSize(MyTree<int>& myTree) {
	cout << "Size: " << myTree.getSize() << endl;
}

template <> void Menu::printKeyList(MyTree<int>& myTree) {
	myTree.printKeyList(myTree.getRoot());
}

template <> void Menu::addByKey(MyTree<int>& myTree) {
	int key;
	int value;
	while (true) {
		cout << "Enter key:" << endl;
		key = enterNumber(0, 2147483647);
		if (myTree.searchKey(key, myTree.getRoot())) {
			cout << "Error! This key exists" << endl;
		}
		else {
			break;
		}
	}
	cout << "Enter value:" << endl;
	value = enterNumber(0, 2147483647);
	myTree.add(key, value, myTree.getRoot());
	message("Node added");
}

template <> void Menu::deleteNodeByKey(MyTree<int>& myTree) {
	if (!myTree.isEmpty()) {
		int key;
		while (true) {
			cout << "Enter key:" << endl;
			key = enterNumber(0, 2147483647);
			if (!myTree.searchKey(key, myTree.getRoot())) {
				cout << "Error! This key not exists" << endl;
			}
			else {
				break;
			}
		}
		myTree.deleteNodeByKey(key, myTree.getRoot());
		message("Node deleted");
	}
	else {
		message("Error! Tree is empty");
	}
}

template <> void Menu::updateValueByKey(MyTree<int>& myTree) {
	if (!myTree.isEmpty()) {
		int value;
		int key;
		while (true) {
			cout << "Enter key:" << endl;
			key = enterNumber(0, 2147483647);
			if (!myTree.searchKey(key, myTree.getRoot())) {
				cout << "Error! This key not exists" << endl;
			}
			else {
				break;
			}
		}
		cout << "Enter value:" << endl;
		value = enterNumber(-2147483647, 2147483647);
		myTree.updateValueByKey(key, value, myTree.getRoot());
		message("Node update");
	}
	else {
		message("Error! Tree is empty");
	}
}

template <> void Menu::clearTree(MyTree<int>& myTree) {
	myTree.clearTree(myTree.getRoot());
	message("Tree cleared");
}

template <> void Menu::isTreeEmpty(MyTree<int>& myTree) {
	if (myTree.isEmpty()) {
		cout << "Tree is empty" << endl;
	}
	else {
		cout << "Tree is not empty" << endl;
	}
}

template <> void Menu::getValueByKey(MyTree<int>& myTree) {
	if (!myTree.isEmpty()) {
		int key;
		while (true) {
			cout << "Enter key:" << endl;
			key = enterNumber(0, 2147483647);
			if (!myTree.searchKey(key, myTree.getRoot())) {
				cout << "Error! This key not exists" << endl;
			}
			else {
				break;
			}
		}
		cout << "Value: " << myTree.getValueByKey(0, key, myTree.getRoot()) << endl;
		cout << endl;
	}
	else {
		message("Error! Tree is empty");
	}
}

template <> void Menu::getBal(MyTree<int>& myTree) {
	if (!myTree.isEmpty()) {
		searchBal(myTree, myTree.getRoot());
	}
	else {
		message("Error! Tree is empty");
	}
}

template <> void Menu::getMenuIterator(MyTree<int>& myTree) {
	if (!myTree.isEmpty()) {
		while (true) {
			bool exit = false;
			MyTree<int>::Iterator iter = myTree.begin();
			MyTree<int>::ReverseIterator rIter = myTree.rbegin();
			int action;
			cout << "Enter iterator" << endl;
			cout << "1) Iterator" << endl;
			cout << "2) Reverse iterator" << endl;
			cout << "3) exit" << endl;
			cout << "Enter action: " << endl;
			action = enterNumber(1, 3);
			cout << endl;

			switch (action) {
			case 1:
				menuIterator(iter);
				break;
			case 2:
				menuReverseIterator(rIter);
				break;
			case 3:
				exit = true;
				break;
			default:
				std::cout << "error";
				break;
			}

			if (exit) {
				break;
			}

			cout << endl;
		}
	}
	else {
		message("Error! Tree is empty");
	}
}

void Menu::menuIterator(typename MyTree<int>::Iterator& iterator) {

	while (true) {
		bool exit = false;
		int action;
		cout << "Menu Iterator" << endl;
		cout << "1) print key" << endl;
		cout << "2) next" << endl;
		cout << "3) prev" << endl;
		cout << "4) print key list -->" << endl;
		cout << "5) print key list <--" << endl;
		cout << "6) begin" << endl;
		cout << "7) end" << endl;
		cout << "8) exit" << endl;
		cout << "Enter action: ";
		action = enterNumber(1, 8);
		cout << endl;

		switch (action) {
		case 1:
			cout << "Key: " << *iterator << endl;
			break;
		case 2:
			message("Next key selected");
			iterator++;
			break;
		case 3:
			message("Prev key selected");
			iterator--;
			break;
		case 4:
			iterator = iterator.begin();
			cout << "Key list: [ ";
			for (int i = 0; i < iterator.getSize(); i++) {
				cout << *iterator << " ";
				iterator++;
			}
			cout << "]" << endl;
			break;
		case 5:
			iterator = iterator.end();
			cout << "Key list: [ ";
			for (int i = 0; i < iterator.getSize(); i++) {
				cout << *iterator << " ";
				iterator--;
			}
			cout << "]" << endl;
			break;
		case 6:
			message("Iterator is installed to begin");
			iterator = iterator.begin();
			break;
		case 7:
			message("Iterator is installed to end");
			iterator = iterator.end();
			break;
		case 8:
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		if (exit) {
			break;
		}

		cout << endl;
	}
}

void Menu::menuReverseIterator(typename MyTree<int>::ReverseIterator& iterator) {

	while (true) {
		bool exit = false;
		int action;
		cout << "Menu Reverse iterator" << endl;
		cout << "1) print key" << endl;
		cout << "2) next" << endl;
		cout << "3) prev" << endl;
		cout << "4) print key list -->" << endl;
		cout << "5) print key list <--" << endl;
		cout << "6) begin" << endl;
		cout << "7) end" << endl;
		cout << "8) exit" << endl;
		cout << "Enter action: ";
		action = enterNumber(1, 8);
		cout << endl;

		switch (action) {
		case 1:
			cout << "Key: " << *iterator << endl;
			break;
		case 2:
			message("Next key selected");
			iterator++;
			break;
		case 3:
			message("Prev key selected");
			iterator--;
			break;
		case 4:
			iterator = iterator.begin();
			cout << "Key list: [ ";
			for (int i = 0; i < iterator.getSize(); i++) {
				cout << *iterator << " ";
				iterator++;
			}
			cout << "]" << endl;
			break;
		case 5:
			iterator = iterator.end();
			cout << "Key list: [ ";
			for (int i = 0; i < iterator.getSize(); i++) {
				cout << *iterator << " ";
				iterator--;
			}
			cout << "]" << endl;
			break;
		case 6:
			message("Reverse Iterator is installed to begin");
			iterator = iterator.begin();
			break;
		case 7:
			message("Reverse Iterator is installed to end");
			iterator = iterator.end();
			break;
		case 8:
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		if (exit) {
			break;
		}

		cout << endl;
	}
}

int Menu::getRandomNumber(int min, int max) {
	return min + rand() % (max - min + 1);
}

int Menu::enterNumber(int min, int max) {
	int number = min - 1;
	while (true) {
		cout << ">> ";
		cin >> number;
		if ((number >= min) && (number <= max) && (cin.peek() == '\n')) {
			break;
		}
		else {
			cout << "Incorrect value!" << endl;
			cin.clear();
			while (cin.get() != '\n') {}
		}
		cout << endl;
	}
	return number;
}

void Menu::testBigO(int n) {
	MyTree<int> tree;
	int* m = new int[n];
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		m[i] = rand();
		tree.add(m[i], 1, tree.getRoot());
	}
	cout << "items count before test:" << tree.getSize() << endl;
	double I = 0;
	double D = 0;
	double S = 0;
	for (int i = 0; i < n / 2; i++)
		if (i % 10 == 0)
		{
			tree.clearLastIteration();
			tree.deleteNodeByKey(rand(), tree.getRoot());
			D += tree.getLastIteration();

			tree.clearLastIteration();
			tree.add(m[rand() % n], 1, tree.getRoot());
			I += tree.getLastIteration();

			tree.clearLastIteration();
			try {
				tree.searchKey(rand(), tree.getRoot());
				S += tree.getLastIteration();
			}
			catch (exception) { S += tree.getLastIteration(); }
		}
		else
		{
			tree.clearLastIteration();
			int ind = rand() % n;
			tree.deleteNodeByKey(ind, tree.getRoot());
			D += tree.getLastIteration();

			tree.clearLastIteration();
			int key = rand();
			tree.add(key, 1, tree.getRoot());
			I += tree.getLastIteration();
			m[ind] = key;

			tree.clearLastIteration();
			try {
				tree.searchKey(m[rand() % n], tree.getRoot());
				S += tree.getLastIteration();
			}
			catch (exception) { S += tree.getLastIteration(); }
		}

	cout << "items count after test:" << tree.getSize() << endl;
	cout << "1.39*log2(n)=" << 1.39 * (log((double)n) / log(2.0)) << endl;
	cout << "Count insert: " << I / (n / 2) << endl;
	cout << "Count delete: " << D / (n / 2) << endl;
	cout << "Count search: " << S / (n / 2) << endl << endl;
	delete[] m;
}

void Menu::message(const char* mes) {
	cout << endl << "------- " << mes << " -------" << endl << endl;
}

int Menu::searchBal(MyTree<int>& myTree, typename MyTree<int>::Node* r) {
	if (r == NULL) {
		return 0;
	}
	int h1 = myTree.getHeight(0, r->left);
	int h2 = myTree.getHeight(0, r->right);
	cout << "Node key: " << r->key << " Bal: " << h2 - h1 << endl;
	searchBal(myTree, r->left);
	searchBal(myTree, r->right);
}