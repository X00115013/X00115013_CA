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
	map<char , int> huffMap;
	map<char, int>::const_iterator iter;
	priority_queue<HuffNode*, std::vector<HuffNode*>, NodeCmp> fq;
	string messageIn;
	int letterCount =0;
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
	//Assign the movie name as an unique iterator 
	for (int i = 0; i < huffMap.size(); ++i)
	{
		iter = huffMap.find(letterCount);
		if (iter == huffMap.end())
			cout << "Map is passed to Priority Queue" << endl;
		else {
			HuffNode* huffTemp;
			(*huffTemp).letterAmount = huffMap.find(messageIn[i]);
			(*huffTemp).theLetter = iter->letterCount;
			fq.push(huffTemp*);

	}
	for (unsigned int i = 0; i < fq.size() - 1; i++)
	{
		HuffNode* a = fq.top();
		fq.pop();
		HuffNode* b = fq.top();
		fq.pop();
		HuffNode* p = new HuffNode((a->letterAmount + b->letterAmount), a,b); // The new node has two children `a` and `b`.
		fq.push(p);
	}
	
	//return fq.top(); // Return root.
}
