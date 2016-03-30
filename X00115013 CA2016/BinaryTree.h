#pragma once
#include "HuffNode.h"
#include <queue>
#include <map>
#include <string>
class BinaryTree
{
public:
	BinaryTree();
	HuffNode newAdd(int, HuffNode *&n);
	void getMessage();
	void compressCode();
	void getFrequency();
private:

	Nodes *root;

};

