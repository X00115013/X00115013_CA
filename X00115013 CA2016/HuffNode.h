#pragma once
class HuffNode
{
	friend class BinaryTree;
	friend struct nodeCmp;
public:
	HuffNode(char theLetter, int letterAmount);
	HuffNode(int letterAmount, HuffNode* c0, HuffNode* c1);
	int letterAmount;
	char theLetter;
private:
	//char theLetter;
	HuffNode *leftPtr;
	//int letterAmount;
	HuffNode *rightPtr;
};