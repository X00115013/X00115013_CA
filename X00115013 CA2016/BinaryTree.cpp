#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;

struct NodeCmp
{
	
	bool operator()(const HuffNode* lhs, const HuffNode* rhs) const { return (*lhs).letterAmount > rhs->letterAmount; }
};


BinaryTree::BinaryTree() : root(NULL)
{

}

// get message from in file
void BinaryTree::getMessage() {
	string messageIn = " ";
	ifstream originalMessage("TextIn.txt");
	while (getline(originalMessage, messageIn)) {
		cout << "Original Message " << endl << "-----------------------" << endl << messageIn << endl << endl;
	}
	originalMessage.close();
}

// get letter frequency
void BinaryTree::getFrequency() {
	priority_queue<HuffNode*, std::vector<HuffNode*>, NodeCmp> fq;
	string messageIn;
	ifstream originalMessage("TextIn.txt");
	while (getline(originalMessage, messageIn)) {
		//messageIn += messageIn;
	}
	originalMessage.close();
	cout << "Original Message " << endl << "-----------------------" << endl << messageIn << endl << endl;
	
	for (unsigned int i = 0; i < messageIn.length(); i++) {
		for (unsigned int j = i; j < messageIn.length() ; j++) {
			if (messageIn[i] == messageIn[j]) {
				letterCount++;
			}
		}
			huffMap.insert(pair<char, int>(messageIn[i], letterCount));
			cout << "Letter: " << messageIn[i] << endl;
			cout << "Letter Count: " << letterCount << endl;
			letterCount = 0;
	}

	//Assign the map to the priority queue 

	for (map<char, int>::iterator iter = huffMap.begin();
		iter != huffMap.end(); ++iter) {
		fq.push(new HuffNode(iter->first, iter->second));
		cout << "First: " <<iter->first << "\tSecond: " << iter->second << endl;
		cout << "Passed " << endl;
	}
	while (fq.size() > 1){
		HuffNode* a = fq.top();
		fq.pop();
		HuffNode* b = fq.top();
		fq.pop();
		cout << "First-a PQ: " << a->letterAmount << "\tSecond-a PQ: " << a->theLetter << endl;
		cout << "First-b PQ: " << b->letterAmount << "\tSecond-b PQ: " << b->theLetter << endl;
		HuffNode* p = new HuffNode((a->letterAmount + b->letterAmount), a, b); // The new node has two children `a` and `b`.
		fq.push(p);
	}
	string code = " ";
	getHuffmanEncoding(fq.top(), code);
}


void BinaryTree::getHuffmanEncoding(HuffNode* root, string code) {
		if (root->leftPtr == NULL) {
				root->setHuffmanCode(code);
				huffmanTable.insert(pair<char, string>((*root).theLetter, code));
				return;
		}
		else {
			getHuffmanEncoding(root->leftPtr, code + "0");
			getHuffmanEncoding(root->rightPtr, code + "1");
	}
}
