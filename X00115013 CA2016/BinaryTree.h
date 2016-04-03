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
	std::map<char, int> huffMap;
	std::string code;
	void getHuffmanEncode(HuffNode*, std::string);
	std::map<char, std::string> huffMapCapture;
	void displayHuffmanTable();
	void encode(std::string);
	std::string encodedData;
	std::string decodedData;
	void getOutMessage();
	void decode();
private:
	
	HuffNode *root;
	

};

