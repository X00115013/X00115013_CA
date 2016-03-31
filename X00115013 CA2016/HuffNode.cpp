#include "HuffNode.h"
using namespace std;

HuffNode::HuffNode(char letter, int theAmount) :theLetter(letter), letterAmount(theAmount) {};

HuffNode::HuffNode(int theAmount, HuffNode* c0, HuffNode* c1) :letterAmount(theAmount), rightPtr(c0), leftPtr(c1) {};