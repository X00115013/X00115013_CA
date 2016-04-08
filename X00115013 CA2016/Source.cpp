#include <iostream>
#include <string>
#include "Hufftree.h"
using namespace std;


int main() {

	HuffTree b1;
	b1.buildHuffTree();
	b1.displayHuffmanTable();
	b1.encode(b1.getMessage());
	b1.getOutMessage();
	b1.decode();
	system("pause");
	return 0;
}

