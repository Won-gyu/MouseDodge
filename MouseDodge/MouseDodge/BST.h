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
	~BST();

	void insert(const int newData);
	void printToFile(ofstream& outputFile);
	void populateFromFile();
	int getLength() const;
	void setLength(int newLength);

private:
	Node* pRoot;
	ifstream inputFile;
	int length;
	void insert(Node* pTree, const int newData);
	void printToFile(Node* pTree, ofstream& outputFile);
	void populateFromFile(Node* pTree);
	void destroyTree(Node* pTree);
};

