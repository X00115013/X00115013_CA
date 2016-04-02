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
				//encodedData.append(" ");
				//cout << "Encoded loop: " << encodedData << endl;
			}
		}
	}
	cout << "Encoded file: " << encodedData << endl;

	std::istringstream in(encodedData);
	stringstream ss;
	string s;
	char c = 'a';
	ss << c;
	ss >> s;
	std::bitset<8> bs;
	string ascii = "";
	char temp = ' ';
	while (in >> bs) {
		//cout << char(bs.to_ulong()) << "\t\t";
		temp = char(bs.to_ulong());
		cout << temp << "\t";
		//ss << temp;
		//ss >> s;
		//cout << s;
		//ascii.append(s);
	}
	ofstream ofs("TextOut.txt", ofstream::out);
	//ofs << encodedData;
	ofs << ascii;
	ofs.close();
}

void BinaryTree::getOutMessage() {
	string messageIn = " ";
	ifstream originalMessage("TextOut.txt");
	while (getline(originalMessage, messageIn)) {
		cout << "\nEncoded Message " << endl << "-----------------------" << endl << messageIn << endl << endl;
	}
	originalMessage.close();
}