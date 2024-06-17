#include "IntQuadHash.h"

/// Constructor for the Quad Integer Hash Table
IntQuadHash::IntQuadHash(int n) {
	SIZE = n;
	table = new int[SIZE];
	for (int i = 0; i < SIZE; i++) {
		table[i] = -1;
	}
}

/// Inserts an item using a quadratic insert,
void IntQuadHash::InsertItem(int x) {
	int i = 0;
	int indexesProbed = 0;
	int index = HashFunction(x);

	while (indexesProbed < SIZE) {
		if (table[index] == -1) {
			table[index] = x;
			return;
		}
		int c1 = 1;
		int c2 = 1;
		i++;

		index = (HashFunction(x) + c1 * i + c2 *i * i) % SIZE;
		
		indexesProbed++;
	}
}

/// The hashing function for the Integer Quad Hash
int IntQuadHash::HashFunction(int x) {
	return (x % SIZE);
}

/// Removes the given number from the hash table if it exists.
void IntQuadHash::DeleteItem(int key) {
	int index = HashSearch(key);
	
	if (index != -1) {
		table[index] = -1;
	}
}

/// Searches for the given key and return the index
int IntQuadHash::HashSearch(int x) {
	int index = HashFunction(x);
	int indexesProbed = 0;
	int i = 0;

	while (indexesProbed < SIZE) {
		if (table[index] == x) {
			return index;
		}

		int c1 = 1;
		int c2 = 1;
		i++;
		
 		index = (HashFunction(x) + c1 * i + c2 * i * i) % SIZE;

		++indexesProbed;
	}
	return -1;
}

/// Displays the hash
void IntQuadHash::DisplayHash() {
	for (int i = 0; i < SIZE; i++) {
		cout << i << "---   " << table[HashFunction(i)];
		cout << endl;
	}
}

