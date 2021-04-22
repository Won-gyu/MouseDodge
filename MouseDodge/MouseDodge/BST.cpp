#include "BST.h"

BST::BST()
{
	this->pRoot = nullptr;
}

void BST::insert(const int newData)
{
	insert(this->pRoot, newData);
}

void BST::inOrderTraversal()
{
	inOrderTraversal(this->pRoot);
}

void BST::printToFile()
{
	printToFile(this->pRoot);
}

void BST::insert(Node* pTree, const int newData)
{
	if (pTree == nullptr)
	{
		this->pRoot = new Node(newData);
	}

	else 
	{
		if (newData < pTree->getData())
		{
			if (pTree->getLeft() == nullptr)
			{
				pTree->setLeft(new Node(newData));
			}

			else
			{
				insert(pTree->getLeft(), newData);
			}
		}

		else if (pTree->getData() < newData)
		{
			if (pTree->getRight() == nullptr)
			{
				pTree->setRight(new Node(newData));
			}

			else
			{
				insert(pTree->getRight(), newData);
			}
		}

		else
		{
			std::cout << "duplicate: " << newData << std::endl;
		}
	}
}

void BST::inOrderTraversal(Node* pTree)
{
	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getLeft());
		std::cout << pTree->getData() << std::endl;
		inOrderTraversal(pTree->getRight());
	}
}

void BST::printToFile(Node* pTree)
{

}

void populateFromFile()
{

}