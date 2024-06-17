#ifndef HASH
#define HASH

#include<string>
#include<list>
#include<iostream>
using namespace std;

class LinearHash {

public:

	//functions that create the hash tables
	LinearHash(int setSize);

	int Function(int n);

	//functions that perform object oriented capabilities
	void Insert(int input);

	void Delete(int key);

	int Search(int input);

	void Print();

private:
	int size;
	int* table;

};

#endif