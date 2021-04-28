#include "TestClass.h"

void TestClass::testBSTInsert(void)
{
	BST bst;
	int value;

	// Insert on empty
	value = 24;
	bst.insert(value);
	if (bst.checkForValue(value))
	{
		std::cout << "Test BST insert() on empty was Successful" << std::endl;
	}
	else
	{
		std::cout << "Test BST insert() on empty Failed" << std::endl;
	}

	// Insert on non-empty
	value = 14;
	bst.insert(value);
	if (bst.checkForValue(value))
	{
		std::cout << "Test BST insert() on non-empty was Successful" << std::endl;
	}
	else
	{
		std::cout << "Test BST insert() on non-empty Failed" << std::endl;
	}

}
void TestClass::testBSTGetLength(void)
{
	BST bst;

	if (bst.getLength() == 0)
	{
		std::cout << "Test BST getLength() on empty was Successful" << std::endl;
	}
	else
	{
		std::cout << "Test BST getLength() on empty Failed" << std::endl;
	}

	bst.insert(35);
	bst.setLength(1);
	if (bst.getLength() == 1)
	{
		std::cout << "Test BST getLength() on non-empty was Successful" << std::endl;
	}
	else
	{
		std::cout << "Test BST getLength() on non-empty Failed" << std::endl;
	}
}
void TestClass::testBSTSetLength(void)
{
	BST bst;
	int value = 4;

	bst.setLength(value);
	if (bst.getLength() == value)
	{
		std::cout << "Test BST setLength() was Successful" << std::endl;
	}
	else
	{
		std::cout << "Test BST setLength() Failed" << std::endl;
	}
}
void TestClass::testBSTPrintToFile(void)
{
	std::ofstream outfile;
	std::ifstream infile;
	outfile.open("test_file.txt", std::ios::out);

	BST bst;
	int value = 34;
	bst.insert(value);
	bst.insert(23);
	bst.insert(17);
	bst.printToFile(outfile);
	
	outfile.close();
	infile.open("test_file.txt", std::ios::in);
	std::string line;
	std::getline(infile, line);
	if (stoi(line) == value)
	{
		std::cout << "Test BST printToFile() was Successful" << std::endl;
	}
	else
	{
		std::cout << "Test BST printToFile() Failed" << std::endl;
	}
}
void TestClass::testBSTPopulateFromFile(void)
{
	std::ifstream infile;
	infile.open("ranks.txt", std::ios::in);
	std::string line;
	std::getline(infile, line);

	int value;
	try
	{
		value = stoi(line);
	}
	catch (std::invalid_argument)
	{
		std::cout << "Test BST populateFromFile() Inconclusive, no values in ranks.txt" << std::endl;
		return;
	}

	BST bst;
	bst.populateFromFile();

	if (bst.checkForValue(value))
	{
		std::cout << "Test BST populateFromFile() was Successful" << std::endl;
	}
	else
	{
		std::cout << "Test BST populateFromFile() Failed" << std::endl;
	}
}