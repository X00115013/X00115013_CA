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


void BinaryTree::compressCode() {
	ifstream readCode("TextIn.txt"); // take coded message
	
	string codeToCompress; // coded message put into a string
	getline(readCode, codeToCompress);
	readCode.close();

	ofstream writeCompressCode("TextOut.txt"); // write compressed message
	//////////////////loop start
	cout << "Compressed characters" << endl << "-----------------------" << endl;
	while (codeToCompress.size() > 0) {
		string charBinCode; // 8 bit charater code holder
		int intBinCode; // takes the string and makes it an int to hold binary num
		int intDecCode = 0; // holds the decimal num for binary code
		//cout << "intBinCode " << intBinCode << endl;
		cout << "intDecCode " << intDecCode << endl;

							// takes first 8 charaters from the coded message
		if (codeToCompress.size() >= 8) {
			for (unsigned int j = 0; j < 8; j++) {
				charBinCode += codeToCompress[j];
				cout << "charBinCode >= " << charBinCode << endl;
			}
			codeToCompress.erase(0, 8); // erase 8 used chars(1s and 0s)
		}
		// when we reach the end of the codedfile and there is less than 8 chars left
		else {
			for (unsigned int j = 0; j < codeToCompress.size(); j++) {
				charBinCode += codeToCompress[j];
				cout << "charBinCode < " << charBinCode << endl;
			}
			codeToCompress.erase(0, codeToCompress.size()); // erase last of used chars(1s and 0s)
		}

		// converts string binary code to an int

		char *y = new char[charBinCode.length() + 1];
		std::strcpy(y, charBinCode.c_str());


		cout << "charBinCode >= " << y << endl;
		cout << "charBinCode >= " << charBinCode << endl;
		intBinCode = atoi(charBinCode.c_str());
		intBinCode = 1010;
		cout << "intBinCode \t" << intBinCode << endl;


		//convert binary to decimal
		for (int i = 0; intBinCode > 0; ++i)
		{
			if ((intBinCode % 10) == 1)
				intDecCode += (1 << i);

			intBinCode /= 10;
		}

		// the char is given the value of the letter 
		//that equals to the decimal code passed to it
		unsigned char compressedChar = intDecCode; // unsigned stops minus
		cout << "CompressedChar " << compressedChar << "intDecCode " << intDecCode << endl;
		writeCompressCode << compressedChar; // write char to file
	}

	writeCompressCode.close();
	
}