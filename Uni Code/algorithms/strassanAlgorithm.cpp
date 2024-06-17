#include <iostream>
using namespace std;


//Function that applies the algorithm
void algorithm( int a, int b, int c, int d, int e, int f, int g, int h)
{
    //calculate first part of multiplication
    int p1 = (f-h)*a;
    int p2 = (a+b)*h;
    int p3 = (c+d)*e;
    int p4 = (g-e)*d;
    int p5 = (a+d)*(e+h);
    int p6 = (b-d)*(g+h);
    int p7 = (a-c)*(e+f);

    //set matric C
    int array[2][2];

    //finish calculations
    array[0][0] = p5 + p4 - p2 + p6;
    array[0][1] = p1 + p2;
    array[1][0] = p3 + p4;
    array[1][1] = p1 + p5 - p3 - p7;

    cout << array[0][0] << " " << array[0][1] << endl;
    cout << array[1][0] << " " << array[1][1] << endl;
    cout << endl;
}

int main()
{

    int a,b,c,d,e,f,g,h = 0;

    //Problem 4 solver

    a=1, b=3, c=7, d=5, e=6, f=8, g=4, h=2;

    algorithm(a,b,c,d,e,f,g,h);

    //Custom solver

    //input for matrix A
    cout << "Please provide inputs for the 2x2 matrix A" << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cout << "Here's what you provided for matrix A" << endl;
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;   
    cout << endl;

    //input for matrix B
    cout << "Please provide inputs for the 2x2 matrix B" << endl;
    cin >> e;
    cin >> f;
    cin >> g;
    cin >> h;
    cout << "Here's what you provided for matrix B" << endl;
    cout << e << " " << f << endl;
    cout << g << " " << h << endl;   
    cout << endl;

    cout << "Using Strassen' algorithm this is the result of matrix C" << endl;
    algorithm(a,b,c,d,e,f,g,h);

    return 0;
}