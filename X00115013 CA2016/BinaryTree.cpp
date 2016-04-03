#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <bitset>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;

struct NodeCmp
{
	
	bool operator()(const HuffNode* lhs, const HuffNode* rhs) const { return (*lhs).letterAmount > rhs->letterAmount; }
};


BinaryTree::BinaryTree() : root(NULL)
{
}

BinaryTree::~BinaryTree()
{

}

// get message from in file
string BinaryTree::getMessage() {
	string messageIn = " ";
	ifstream originalMessage("TextIn.txt");
	while (getline(originalMessage, messageIn)) {
		cout << "Original Message " << endl << "-----------------------" << endl << messageIn << endl << endl;
	}
	originalMessage.close();
	return messageIn;
}

// get letter frequency
void BinaryTree::getFrequency() {
	//map<char, int> huffMap;
	priority_queue<HuffNode*, std::vector<HuffNode*>, NodeCmp> fq;
	string messageIn;
	ifstream originalMessage("TextIn.txt");
	while (getline(originalMessage, messageIn)) {
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
	};
	while (fq.size() > 1){
		HuffNode* a = fq.top();
		fq.pop();
		HuffNode* b = fq.top();
		fq.pop();
		cout << "First-a PQ: " << a->letterAmount << "\tSecond-a PQ: " << a->theLetter << endl;
		cout << "First-b PQ: " << b->letterAmount << "\tSecond-b PQ: " << b->theLetter << endl;
		HuffNode* p = new HuffNode((a->letterAmount + b->letterAmount), a, b); // The new node has two children `a` and `b`.
		fq.push(p);
	};
	string codeIns = "";
	HuffNode* c = fq.top();
	root = c;
	getHuffmanEncode(c, codeIns);
}


void BinaryTree::getHuffmanEncode(HuffNode* root, std::string codeIn) {
		if (root->leftPtr == NULL) {
			//code = codeIn;
			huffMapCapture.insert(pair<char, std::string>((*root).theLetter, codeIn));
			return;
		}
		else {
			getHuffmanEncode(root->leftPtr, codeIn + "0");
			getHuffmanEncode(root->rightPtr, codeIn + "1");
	}
}


void BinaryTree::displayHuffmanTable() {
		cout << "Huffman Map:" << endl;
		for (map<char, string>::iterator it = huffMapCapture.begin();
		it != huffMapCapture.end(); ++it) {
			cout << it->first << "\t" << it->second << endl;
	}
}

void BinaryTree::encode(string messageIn) {

	for (unsigned int i = 0; i < messageIn.length(); i++) {
		for (map<char, string>::iterator it = huffMapCapture.begin();
		it != huffMapCapture.end(); ++it) {
			if (messageIn[i] == it->first) {
				encodedData.append(it->second);
			}
		}
	}
	cout << "Encoded file: " << encodedData << endl;
	ofstream ofCode("TextOut.txt", ofstream::out);
	ofCode << encodedData;
	ofCode.close();
	int filler = 0;
	bool loop = true;
	while (loop) {
		if (encodedData.length() % 8 != 0) {
			cout << "\nNothing here to run" << endl;
			cout << "This is the length before : " << encodedData.length() << endl;
			filler = encodedData.length() % 8;
			for (int i = 0; i < (8 - filler); i++) {
				encodedData.append("0");
			}
		}
		else {
			cout << "This is the length after : " << encodedData.length() << endl; 
			istringstream in(encodedData);
			bitset<8> bs;
			ofstream ofs("ASCII.txt", ofstream::out);
			while (in >> bs) {
				char temp = ' ';
				temp = char(bs.to_ulong());
				cout << temp << "\t";
				ofs << temp;
			}
			cout << "\t\tGetting Here   " << endl;
			ofs.close();
			loop = false;
		}
	}
}

void BinaryTree::decode() {

	string messageIn = " ";
	ifstream originalMessage("TextOut.txt");
	while (getline(originalMessage, messageIn)) {
		cout << "\nTo be Decoded " << endl << "-----------------------" << endl << messageIn << endl << endl;
	}
	originalMessage.close();

	string res = "";
	HuffNode* node = root;

	for (unsigned int i = 0; i < messageIn.length(); i++) {
			if (messageIn[i] == '0') {
				node = node->leftPtr;
			}
			else if (messageIn[i] == '1') {
				node = node->rightPtr;
			}
			if (node->leftPtr == NULL)
			{
				res += node->theLetter;
				node = root;
			}
		}

	cout << "\nDecoded " << endl << "-----------------------" << endl << res << endl << endl;

}


void BinaryTree::getOutMessage() {
	string messageIn = " ";
	ifstream originalMessage("TextOut.txt");
	while (getline(originalMessage, messageIn)) {
		cout << "\nEncoded Message " << endl << "-----------------------" << endl << messageIn << endl << endl;
	}
	originalMessage.close();
}