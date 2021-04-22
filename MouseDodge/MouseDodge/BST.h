#pragma once

#include "Node.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class BST
{
public:
	BST();

	void insert(const int newData);
	//void inOrderTraversal();
	void printToFile();
	void populateFromFile();

private:
	Node* pRoot;
	ifstream inputFile;
	ofstream outputFile;
	void insert(Node* pTree, const int newData);
	//void inOrderTraversal(Node* pTree);
	void printToFile(Node* pTree);
	void populateFromFile(Node* pTree);
};

