#include "BST.h"

BST::BST()
{
	this->pRoot = nullptr;
}

BST::~BST()
{
	//destroyTree(this->pRoot);
	pRoot->~Node();
}

void BST::insert(const int newData)
{
	insert(this->pRoot, newData);
}

void BST::printToFile(ofstream& outputFile)
{
	printToFile(this->pRoot, outputFile);
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

void BST::printToFile(Node* pTree, ofstream& outputFile)
{
	if (pTree != nullptr && outputFile.is_open())
	{
		printToFile(pTree->getRight(), outputFile);
		outputFile << pTree->getData() << std::endl;
		printToFile(pTree->getLeft(), outputFile);
	}
}

void BST::populateFromFile(Node* pTree)
{
	inputFile.open("ranks.txt");
	int num = 0;
	string temp = "";

	if (inputFile.is_open());
	{
		while (!inputFile.eof())
		{
			getline(inputFile, temp);
			if (temp != "")
			{
				num = stoi(temp);
				insert(num);
			}
		}
	}

	inputFile.close();
}

void BST::destroyTree(Node* pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getLeft());
		destroyTree(pTree->getRight());
		delete pTree;
	}
}