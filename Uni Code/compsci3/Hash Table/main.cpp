
#include "Hash.h"

int main() {
    LinearHash hashTable(10);

    int select;
    int loop = 1;
    cout << "Hash Table Menu" << endl << endl;

    while (loop == 1) {
        cout << "Menu:" << endl;
        cout << "1 - Insert" << endl;
        cout << "2 - Search" << endl;
        cout << "3 - Delete" << endl; 
        cout << "4 - Output" << endl; 
        cout << "5 - Quit" << endl << endl;
        cin >> select;

        switch(select) {
            case 1: {
                int x = 0;
                cout << "Please input a data element to be inserted into the hash table" << endl;
                cin >> x;

                hashTable.Insert(x);

                cout << "Data element " << x << " has been added to the hash table" << endl << endl;
                
                break;
            }
            case 2: {
                int x = 0;
                cout << "Please input a data element to be searched from the hash table" << endl;
                cin >> x;

                if (hashTable.Search(x) >= 0) {
                    cout << "The bucket of index " << x << " is: " << hashTable.Search(x) << endl << endl;
                }
                else {
                    cout << "That data element does not exist in the hash function" << endl << endl;
                }
                
                break;
            }
            case 3: {
                int x = 0;
                cout << "Please input a data element to be deleted from the hash table" << endl;
                cin >> x;

                if (hashTable.Search(x) >= 0) {
                    hashTable.Delete(x);
                    cout << "Data element " << x << " has been removed from the hash table" << endl << endl;
                }
                else {
                    cout << "That data element does not exist in the hash function" << endl << endl;
                }

                break;
            }
            case 4: {
                cout << "This what the hash table currently looks like" << endl << endl;
                hashTable.Print();
                
                break;
            }
            case 5: {
                loop = 0;
                break;
            }
            default: {
                cout << "Please input a correct number" << endl << endl;
                break;
            }
        }
    }
    return 0;
}



