#pragma once
#include "Nodes.h"
class HuffNode: public Nodes
{
	friend class BinaryTree;
public:
	HuffNode(int letterAmount, Nodes* c0, Nodes* c1);
private:
	Nodes *leftPtr;
	int letterAmount;
	Nodes *rightPtr;
};