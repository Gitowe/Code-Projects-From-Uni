#include "Hash.h"

// Creates the hash table
LinearHash::LinearHash(int setSize) 
{
	size = setSize;
	table = new int[size];

	for (int i = 0; i < size; i++) 
	{
		table[i] = -1;
	}
}

// Hashing function implentation
int LinearHash::Function(int n) 
{
	return (n % size);
}

// Inserts an item into the hash table
void LinearHash::Insert(int input) 
{
	int index = Function(input);
	int probed = 0;

	while (probed < size) 
	{
		if (table[index] == -1) 
		{
			table[index] = input;
			
			return;
		}

		index = (index + 1) % size;
		++probed;
	}
}

// Removes an item from the hash table
void LinearHash::Delete(int key) 
{
	int index = Search(key);
	
	if (index != -1) 
	{
		table[index] = -1;
	}
}


// Searches for item from hash table
int LinearHash::Search(int input) 
{
	int index = Function(input);
	int probed = 0;

	while (probed < size) 
	{
		if (table[index] == input) 
		{
			return index;
		}

		index = (index + 1) % size;
		++probed;
	}
	return -1;
}

// Prints out the hash
void LinearHash::Print() 
{
	cout << "Hash Table:" << endl;
	for (int i = 0; i < size; i++) 
	{
		if (table[Function(i)] >= 0) 
		{
			cout << " " << i << "  --  " << table[Function(i)];
		}
		else
		{
			cout << " " << i << "  --  " << "#";
		}
		cout << endl;
	}
	cout << endl;
}

