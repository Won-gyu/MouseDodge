#include "Node.h"

Node::Node(const int newData)
{
	this->score = newData;
	this->pLeft = nullptr;
	this->pRight = nullptr;
}

Node::~Node()
{
	//delete pLeft;
	//delete pRight;
}

int Node::getData() const
{
	return this->score;
}

Node* Node::getLeft() const
{
	return this->pLeft;
}

Node* Node::getRight() const
{
	return this->pRight;
}

void Node::setLeft(Node* newLeft)
{
	this->pLeft = newLeft;
}

void Node::setRight(Node* newRight)
{
	this->pRight = newRight;
}