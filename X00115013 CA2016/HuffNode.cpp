#include "HuffNode.h"
using namespace std;
HuffNode::HuffNode(int theAmount, Nodes* c0, Nodes* c1) :letterAmount(theAmount), rightPtr(c0), leftPtr(c1)
{

}