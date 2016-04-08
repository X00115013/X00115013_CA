#pragma once
class HuffNode
{
	friend class HuffTree;
	friend struct nodeCmp;
public:
	HuffNode(char theLetter, int letterAmount);
	HuffNode(int letterAmount, HuffNode* c0, HuffNode* c1);
	int letterAmount;
	char theLetter;
private:
	HuffNode *leftPtr;
	HuffNode *rightPtr;
};