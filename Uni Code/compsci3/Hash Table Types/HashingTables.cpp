#include <iostream>
#include "IntChainHash.h"
#include "IntLinHash.h"
#include "IntQuadHash.h"

using namespace std;

// Function to display the Integer Chain Hash Table
void DisplayIntChainHash(int *arr, int len, int deleteElement, int *checkElement) {
    cout << "Integer Chain Hash Table -------\n";

    IntChainHash integerChainHash(len + 2);

    for (int i = 0; i < len; i++) {
        integerChainHash.InsertItem(arr[i]);
    }

    integerChainHash.DeleteItem(deleteElement);

    integerChainHash.DisplayHash();

    cout << "BUCKET OF INDEX " << checkElement[0] << ": " << integerChainHash.HashSearch(checkElement[0]) << endl;
    cout << "BUCKET OF INDEX " << checkElement[1] << ": " << integerChainHash.HashSearch(checkElement[1]) << endl;
    cout << "BUCKET OF INDEX " << checkElement[2] << ": " << integerChainHash.HashSearch(checkElement[2]) << endl;
    cout << "---------------------------------\n";
}

// Function to display the Linear Hash Table
void DisplayIntLinHash(int *arr, int len, int deleteElement, int *checkElement) {
    cout << "Integer Linear Hash Table -------\n";

    IntLinHash integerLinHash(len + 2);

    for (int i = 0; i < len; i++) {
        integerLinHash.InsertItem(arr[i]);
    }

    integerLinHash.DeleteItem(deleteElement);

    integerLinHash.DisplayHash();

    cout << "BUCKET OF INDEX " << checkElement[0] << ": " << integerLinHash.HashSearch(checkElement[0]) << endl;
    cout << "BUCKET OF INDEX " << checkElement[1] << ": " << integerLinHash.HashSearch(checkElement[1]) << endl;
    cout << "BUCKET OF INDEX " << checkElement[2] << ": " << integerLinHash.HashSearch(checkElement[2]) << endl;
    cout << "---------------------------------\n";
}

// Function to display the Integer Quad Hash Table
void DisplayIntQuadHash(int *arr, int len, int deleteElement, int *checkElement) {
    cout << "Integer Quad Hash Table -------\n";

    IntQuadHash integerQuadHash(len + 2);

    for (int i = 0; i < len; i++) {
        integerQuadHash.InsertItem(arr[i]);
    }

    integerQuadHash.DeleteItem(deleteElement);

    integerQuadHash.DisplayHash();

    cout << "BUCKET OF INDEX " << checkElement[0] << ": " << integerQuadHash.HashSearch(checkElement[0]) << endl;
    cout << "BUCKET OF INDEX " << checkElement[1] << ": " << integerQuadHash.HashSearch(checkElement[1]) << endl;
    cout << "BUCKET OF INDEX " << checkElement[2] << ": " << integerQuadHash.HashSearch(checkElement[2]) << endl;
    cout << "---------------------------------\n";
}

// Function to check if the input is an integer
int numberChecker (int n) {
    cin >> n;
    if (cin.fail()) {
        cout << "The number of elements you entered is not a valid integer." << endl;
        while (cin.fail()) {
            cout << "Please enter a correct integer number: ";
            cin >> n;
        }
    }
    return n;
}

// Function to check if the element is in the array
bool isElementInArray (int element, int *arr, int n) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            found = true;
            break;
        }
    }
    return found;
}

int main() {

    // Number of elements to be inserted into the Hash Table
    int n;
    cout << "This program demonstrates the use of various Hash Tables." << endl;
    cout << "Please enter the number of elements you would like to insert into the Hash Table: ";
    n = numberChecker(n);
    if (n <= 0) {
        cout << "The number of elements you entered is not positive." << endl;
        while (n <= 0) {
            cout << "Please enter a positive number or a number great than zero: ";
            cin >> n;
        }
    }

    // Array of elements to be inserted into the Hash Table
    int *arr = new int(n);
    cout << endl << "Please enter the integer elements you would like to insert into the Hash Table:" << endl;
    for (int i = 0; i < n; i++) {
        arr[i] = numberChecker(arr[i]);
    }

    // Length of the array
    int len = sizeof(arr);

    // Element to be deleted from the Hash Table
    cout << endl << "Please input which element you would like to delete from the Hash Tables: ";
    int deleteElement;
    bool found = false;
    deleteElement = numberChecker(deleteElement);
    found = isElementInArray(deleteElement, arr, n);
    if (!found) {
        cout << "The element you entered is not in the Hash Tables." << endl;
        while (!found) {
            cout << "Please enter a correct element: ";
            cin >> deleteElement;
            found = isElementInArray(deleteElement, arr, n);
        }
    }

    // Elements to be checked in the Hash Table
    cout << endl << "Please input which three elements you would like to check the buckets for in the Hash Tables: ";
    int checkElement[3];
    for (int i = 0; i < 3; i++) {
        bool found = false;
        checkElement[i] = numberChecker(checkElement[i]);
        if (checkElement[i] == deleteElement) {
            cout << "The element you entered is the element you want to delete." << endl;
            while (checkElement[i] == deleteElement) {
                cout << "Please enter a different element: ";
                cin >> checkElement[i];
            }
        } 
        found = isElementInArray(checkElement[i], arr, n);
        if (!found) {
            cout << "The element you entered is not in the Hash Tables." << endl;
            while (!found) {
                cout << "Please enter a correct element: ";
                cin >> checkElement[i];
                found = isElementInArray(checkElement[i], arr, n);
            }
        }
    }
    
    // Display the Hash Tables
    cout << "Here are the Hash Tables: \n\n";

    DisplayIntChainHash(arr, len, deleteElement, checkElement);
    cout << endl << endl;

    DisplayIntLinHash(arr, len, deleteElement, checkElement);
    cout << endl << endl;

    DisplayIntQuadHash(arr, len, deleteElement, checkElement);

}



