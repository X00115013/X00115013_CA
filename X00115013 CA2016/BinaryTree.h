#pragma once
#include "HuffNode.h"
#include <queue>
#include <map>
#include <string>
class BinaryTree
{
public:
	BinaryTree();
	void getMessage();
	void getFrequency();
	int letterCount = 0;
	vector<bool> HuffCode;
	map<char, int> huffMap;

private:
	void BinaryTree::getHuffmanEncoding(HuffNode* root, string code);
	HuffNode *root;
	

};

