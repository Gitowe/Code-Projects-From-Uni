#include "IntLinHash.h"

/// Constructor for the Linear Integer Hash Table
IntLinHash::IntLinHash(int n) {
	SIZE = n;
	table = new int[SIZE];
	for (int i = 0; i < SIZE; i++) {
		table[i] = -1;
	}
}

/// Inserts an item using a linear insert,
/// which will look in subsequent buckets if the current one is filled.
void IntLinHash::InsertItem(int x) {
	int index = HashFunction(x);
	int indexesProbed = 0;

	while (indexesProbed < SIZE) {
		if (table[index] == -1) {
			table[index] = x;
			
			return;
		}
		

		index = (index + 1) % SIZE;

		++indexesProbed;
	}
}

/// The hashing function for the Integer Linear Hash
int IntLinHash::HashFunction(int x) {
	return (x % SIZE);
}

/// Removes the given number from the hash table if it exists.
void IntLinHash::DeleteItem(int key) {
	int index = HashSearch(key);
	
	if (index != -1) {
		table[index] = -1;
	}
}

/// Searches for the given key and return the index
int IntLinHash::HashSearch(int x) {
	int index = HashFunction(x);
	int indexesProbed = 0;

	while (indexesProbed < SIZE) {
		if (table[index] == x) {
			return index;
		}
		index = (index + 1) % SIZE;

		++indexesProbed;
	}
	return -1;
}

/// Displays the hash
void IntLinHash::DisplayHash() {
	for (int i = 0; i < SIZE; i++) {
		cout << i << "---   " << table[HashFunction(i)];
		cout << endl;
	}
}

