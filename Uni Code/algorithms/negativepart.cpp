#include <iostream>
using namespace std;
 

void printArray(int array[], int size)
{


    int i = 0;
    int j = size -1;

    while (i < j)
    {
        if (array[i] < 0)
        {
            i++;
        }
        else
        {
            swap(array[i], array[j]);
            j--;
        }
    }

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
}


int main()
{
    cout << "Question 1 test case" << endl;
 
    int array[] = { 5, -13, 2, 25, -7, 17, -20, 8, -4 };


    int size = sizeof(array) / sizeof(int);
    printArray(array, size);

 
    return 0;
}