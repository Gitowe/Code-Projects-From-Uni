#include <iostream>
using namespace std;
 
// Quicksort Algorithm

//prints the array as is (used for debugging and seeing changes in array)
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

//partitions the array
int partition(int array[], int p, int q)
{
    //p is starting point
    //q is end point
 
    int pivot = array[p];
    int i = p;
 
    for (int j = p + 1; j <= q; j++) {
        if (array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[p], array[i]);

    return i;
}

//sorts the array by partitioning it recursivly
void quickSort(int array[], int p, int r)
{
    if (p < r)
    {
        int q = partition(array, p, r);
        quickSort(array, p, q - 1);
        quickSort(array, q + 1, r);
    }
}

//sorts the array and then prints it
void printSort(int array[], int size)
{
    quickSort(array, 0, size - 1);
 
    printArray(array, size);
}
 
int main()
{
    cout << "Question 1 test case" << endl;
 
    //set of numbers used in question one
    int array[] = { 5, 13, 2, 25, 7, 17, 20, 8, 4 };


    int size = sizeof(array) / sizeof(int);
    printSort(array, size);

    //allows user to input their own array to test
    //works for integers only
    cout << "Custom test case" << endl;
    cout << "Insert new array length" << endl;

    int length;
    cin >> length;

    int array2[length];
    int input = 0;

    for (int i = 0; i < length; i++)
    {
        cout << "Input value for position " << i+1 << " in array" << endl;
        cin >> input;
        array2[i] = input;
    }
    cout << "Final sorted array" << endl;


    size = sizeof(array2) / sizeof(int);
    printSort(array2, size);

 
    return 0;
}