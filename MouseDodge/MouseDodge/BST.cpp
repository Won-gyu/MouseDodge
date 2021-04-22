#include "BST.h"

BST::BST()
{
	this->pRoot = nullptr;
}

void BST::insert(const int newData)
{
	insert(this->pRoot, newData);
}

void BST::printToFile()
{
	printToFile(this->pRoot);
}

void BST::populateFromFile()
{
	populateFromFile(this->pRoot);
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

void BST::printToFile(Node* pTree)
{
	outputFile.open("ranks.txt");

	if (pTree != nullptr)
	{
		printToFile(pTree->getLeft());
		outputFile << pTree->getData() << std::endl;
		printToFile(pTree->getRight());
	}

	outputFile.close();
}

void BST::populateFromFile(Node* pTree)
{
	inputFile.open("ranks.txt");
	int num;
	string temp;

	while (!inputFile.eof())
	{
		getline(inputFile, temp);
		num = stoi(temp);
		insert(num);
	}

	inputFile.close();
}