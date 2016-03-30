#pragma once
#include "Nodes.h"
class FreqNode: public Nodes
{
public:
	FreqNode(char theLetter, int letterAmount);
private:
	char theLetter;
	int letterAmount;
};
