#include <iostream>
#include <string>
#include "Binarytree.h"
using namespace std;


int main() {

	BinaryTree b1;
	b1.getMessage();
	b1.getFrequency();
	b1.displayHuffmanTable();
	b1.encode(b1.getMessage());
	b1.getOutMessage();
	system("pause");
	return 0;
}

