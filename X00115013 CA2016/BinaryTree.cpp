/*
* btree.cpp
*
*  Created on: 2 Mar 2010
*      Author: Mary
*/
#include "BinaryTree.h"
#include "FreqNode.h"
#include "Nodes.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;



BinaryTree::BinaryTree() : root(NULL)
{

}


HuffNode BinaryTree::newAdd(int item, HuffNode*& root) {
	if (root == 0)
	{
		Nodes *temp = new HuffNode(item);
		root = temp;
	}
	else {
		if (item <= root->letterAmount)
			return newAdd(item, root->leftPtr);
		else
			return newAdd(item, root->rightPtr);
	}
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
	priority_queue<Nodes*> fq;
	string messageIn;
	char letterAfterCount;
	int letterCount;
	ifstream originalMessage("TextIn.txt");
	while (getline(originalMessage, messageIn)) {
		messageIn += messageIn;
	}
	originalMessage.close();

	for (int i = 0; i <= messageIn.length(); i++) {
		for (int j = i; j <= messageIn.length() - i; j++) {
			if (messageIn[i] == messageIn[j]) {
				letterCount++;
			}
		}
			Nodes* pushed = new FreqNode(messageIn[i], letterCount);
			fq.push(pushed);
			letterCount = 0;
	}

	for (int i = 0; i < fq.size() - 1; i++)
	{
		Nodes* a = fq.top();
		fq.pop();
		Nodes* b = fq.top();
		fq.pop();
		Nodes* p = new HuffNode((a->letterAmount + b->letterAmount), a,b); // The new node has two children `a` and `b`.
		fq.push(p);
	}
	//return fq.top(); // Return root.
}
