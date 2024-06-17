#include <iostream>
#include <string>
using namespace std;

//finds LCS of two given strings and then prints it and its length
void change(int d[], int x, int m)
{
    int n = x;
    for (int i = 0; i <= m; i++) // iterate through denominations
    {
        int count = 0; // number of denominations needed for change
        while (n >= d[i]) // iterate through denomination values
        {
            count = count + 1; 
            n = n - d[i]; 
        }
        if (count > 0)
        {
            cout << "Number of cents: " << count << ", Value of denomination: " << d[i] << endl; // result
        }
    }
}

int main()
{
    //Example
    int m; // number of denominations
    m = 4;

    int d[m]; // setting value of each denomination
    d[0] = 25; d[1] = 10; d[2] = 5; d[3] = 1;

    int x = 67; // value to be converted to optimal change

    cout << "Example problem" << endl;
    cout << "Change for 67 cents using quarters, dimes, nickels, pennies" << endl;
    change(d, x, m);
    cout << endl;



    //Enter your own
    cout << "Input how many denominations you want" << endl;
    cin >> m; // number of denominations

    d[m]; // setting value of each denomination
    for (int i = 0; i < m; i++)
    {
        cout << "Input valaue for denomination int " << i+1 << " (highest first, lowest last)" << endl;
        cin >> d[i];
    }

    cout << "Input what amount you want to turn into change" << endl;
    cin >> x; // value to be converted to optimal change

    cout << "Results:" << endl;
    change(d, x, m);
    cout << endl;


    return 0;
}
