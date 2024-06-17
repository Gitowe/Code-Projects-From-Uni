#include <vector>
#include <iostream>

using namespace std;

// Swap function to switch two integers
void swap(int* from, int* to)
{
    int temp = *from;
    *from = *to;
    *to = temp;
}

// Processes the heap function
void heapProcess(vector<int> &num, int heapSize, int index) 
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heapSize && num[left] > num[largest])
    {
        largest = left;
    }

    if (right < heapSize && num[right] > num[largest])
    {
        largest = right;
    }

    if (largest != index) 
    {
        swap(num[index], num[largest]);
        heapProcess(num, heapSize, largest);
    }
}

// Processes the merge function
void mergeProcess(vector<int> &num, int left, int mid, int right) 
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    vector<int> leftPart(leftSize);
    vector<int> rightPart(rightSize);

    int leftSection;
    leftSection = 0;

    int rightSection; 
    rightSection = 0;

    int indexMerged;
    indexMerged = left;

    for (int i = 0; i < leftSize; i++)
    {
        leftPart[i] = num[left + i];
    }
    for (int i = 0; i < rightSize; i++)
    {
        rightPart[i] = num[mid + 1 + i];

    }

    while (leftSection < leftSize && rightSection < rightSize) 
    {
        if (leftPart[leftSection] <= rightPart[rightSection]) 
        {
            num[indexMerged] = leftPart[leftSection];
            leftSection++;
        } 
        else 
        {
            num[indexMerged] = rightPart[rightSection];
            rightSection++;
        }
        indexMerged++;
    }

    while (leftSection < leftSize) 
    {
        num[indexMerged] = leftPart[leftSection];
        leftSection++;
        indexMerged++;
    }

    while (rightSection < rightSize) 
    {
        num[indexMerged] = rightPart[rightSection];
        rightSection++;
        indexMerged++;
    }
}

// Processes the quick function
int quickProcess(vector<int> &num, int low, int high) 
{
    int pivot = num[high];
    int index = (low - 1);

    for (int j = low; j <= high - 1; j++) 
    {
        if (num[j] < pivot) 
        {
            index++;
            swap(num[index], num[j]);
        }
    }

    swap(num[index + 1], num[high]);

    return (index + 1);
}

// Insertion function
void Insertion(vector<int> &num, int size) 
{
    for (int i = 1; i < size; i++) 
    {
        int check = num[i];

        int j = i - 1;

        while (j >= 0 && num[j] > check) 
        {
            num[j + 1] = num[j];
            j = j - 1;
        }

        num[j + 1] = check;
    }
}

// Selection Function
void Selection(vector<int> &num, int size)
{

    for (int i = 0; i < size - 1; i++) 
    {
        int check = i;

        for (int j = i + 1; j < size; j++)
        {
            if (num[j] < num[check])
            {
                check = j;
            }
        }
        swap(num[check], num[i]);
    }
}

// Heap Function
void Heap(vector<int> &num, int size) 
{

    for (int i = (size / (2 - 1)); i >= 0; i--)
    {
        heapProcess(num, size, i);
    }

    for (int i = (size - 1); i > 0; i--) 
    {
        swap(num[0], num[i]);

        heapProcess(num, i, 0);
    }
}

// Merge function
void Merge(vector<int> &num, int begin, int end) 
{
    if (begin >= end) 
    {
        return;
    }

    int mid = begin + (end - begin) / 2;
    Merge(num, begin, mid);
    Merge(num, mid + 1, end);
    mergeProcess(num, begin, mid, end);
}

// Quick function
void Quick(vector<int> &num, int low, int high) 
{
    if (low < high) 
    {
        int partition = quickProcess(num, low, high);

        Quick(num, low, partition - 1);
        Quick(num, partition + 1, high);
    }
}

int main() 
{
    int input;
    cout << "Please input desired vector size" << endl;
    cin >> input;
    cout << endl;

    int size = input;
    bool loop = true;
    int select;
    vector<int> num(size);

    for (int i = 0; i < size; i++) 
    {   
        //inserting numbers that range in 0 to 100k
        num[i] = rand() % 100001;
    }
    
    while (loop == true)
    {
        cout << "Sorting Functions:" << endl;
        cout << "1 - Insertion Sort" << endl;
        cout << "2 - Selection Sort" << endl;
        cout << "3 - Heap Sort" << endl;
        cout << "4 - Merge Sort" << endl;
        cout << "5 - Quick Sort" << endl;
        cout << "6 - Output vector list of numbers" << endl;
        cout << "7 - Quit" << endl << endl;
        loop = 1;
        cin >> select;

        switch(select)
        {
            case 1:
            {
                Insertion(num, size);
                break;
            }
            case 2:
            {
                Selection(num, size);
                break;
            }
            case 3:
            {
                Heap(num, size);
                break;
            }
            case 4:
            {
                Merge(num, 0, size - 1);
                break;
            }
            case 5:
            {
                Quick(num, 0, size - 1);
                break;
            }
            case 6:
            {
                for (int i = 0; i < size; i++) 
                {   
                    cout << num[i] << endl;
                }
                cout << endl;

                break;
            }
            case 7:
            {
                loop = false;
                break;
            }
            default:
            {
                cout << "Please input a correct number" << endl << endl;
                break;
            }
        }
    }


    return 0;
}