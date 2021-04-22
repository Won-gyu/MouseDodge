#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class Node
{
public:
	Node(const int newData);

	int getData() const;
	Node* getLeft() const;
	Node* getRight() const;

	void setLeft(Node* newLeft);
	void setRight(Node* newRight);

private:
	int score;
	Node* pLeft;
	Node* pRight;
};