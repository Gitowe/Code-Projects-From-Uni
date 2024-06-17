#include "IntChainHash.h"

/// Constructor for int chain hash
IntChainHash::IntChainHash(int n) {
	SIZE = n;
	table = new list<int>[SIZE];
}

/// The hashing function for the Integer Chain Hash
int IntChainHash::HashFunction(int x) {
	return (x % SIZE);
}

/// A function for inserting an item into the relevant list within the interger
void IntChainHash::InsertItem(int x) {
	int index = HashFunction(x);
	table[index].push_back(x);
}

/// Removes the given number from the hash table if it exists.
void IntChainHash::DeleteItem(int key) {
	int index = HashFunction(key);
	list<int> ::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++) {
		if (*i == key) {
			break;
		}
	}

	if (i != table[index].end()) {
		table[index].erase(i);
	}

}

/// Searches for the given key and return the index
int IntChainHash::HashSearch(int x) {
	int index = HashFunction(x);
	list<int> ::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++) {
		if (*i == x) {
			return index;
		}
	}

	return -1;
}

/// Displays the hash
void IntChainHash::DisplayHash() {
	for (int i = 0; i < SIZE; i++) {
		cout << i;
		for (auto x : table[i])
			cout << " --> " << x;
		cout << endl;
	}
}
