#pragma once
#include "HuffNode.h"
#include <queue>
#include <map>
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	std::string getMessage();
	void getFrequency();
	int letterCount = 0;
	//vector<bool> HuffCode;
	std::map<char, int> huffMap;
	std::string code;
	void getHuffmanEncode(HuffNode*, std::string);
	std::map<char, std::string> huffMapCapture;
	void displayHuffmanTable();
	void encode(std::string);
	std::string encodedData;
	void getOutMessage();
private:
	
	HuffNode *root;
	

};

