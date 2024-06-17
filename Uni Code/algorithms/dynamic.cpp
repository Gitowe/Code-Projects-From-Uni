#include <iostream>
#include <string>
using namespace std;

//finds LCS of two given strings and then prints it and its length
void analyzeLCS(string X, string Y, int m, int n)
{
    //b will be used to track location of LCS characters
    //c will be used to iterate through the LCS map
    char b[m + 1][n + 1]; 
    int c[m + 1][n + 1];

    //initialize c
    for (int i = 1; i <= m; i++)
    {
        c[i][0] = 0;
        for (int j = 0; j <= n; j++)
        {
            c[0][j] = 0;
        }
    }
    //iteration through the LCS map (grid from the given strings) to get length of LCS
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'V'; // Up Left
            }
            else if (c[i - 1][j] >=  c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'U'; // Up
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'L'; // Left
            }
        }
    }
 
    //c[m][n] is the length of the LCS, but b will help determine what the LCS is
    int length = c[m][n];
    cout << "LCS Length: " << length << endl;

    //print will store LCS characters
    char print[length + 1];
    print[length] = '\0';

    //iteration through b to find LCS characters
    int i = m, j = n;
    while (i > 0 && j > 0) 
    {
        if (b[i][j] == 'V') 
        {
            print[length - 1 ] = X[i - 1];
            length--;
            i--;
            j--;
        }
        else if (b[i][j] == 'U')
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout << "String 1 : " << X << endl;
    cout << "String 2 : " << Y << endl;
    cout << "LCS : " << print << endl << endl;


}

//main function
int main()
{     
    //test case from notes
    string X = "spanking";
    string Y = "amputation";
    int m = X.length();
    int n = Y.length();

    cout << "Sample test case" << endl << endl;
    analyzeLCS(X, Y, m, n);

    //custom test case
    cout << "Insert two strings to be analyzed" << endl;

    cout << "String 1:  ";
    cin >> X;
    n = Y.length();
    cout << "String 2:  ";
    cin >> Y;
    m = X.length();

    cout << "Results" << endl;

    analyzeLCS(X, Y, m, n);

    return 0;
}
