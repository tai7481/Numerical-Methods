/* William Tai
 * MATH 428, Spring 2019
 * Euler's Method for ODE
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

// dy/dx definition
double func(double x, double y);

// Function for Euler formula
void euler(double x0, double y, double h, double x);

// Driver program
int main()
{
    // Initial Values
    double x0 = 0;
    double y0 = 1;
    double h1 = 0.4, h2 = 0.2;  //step sizes

    // Value of x at the end of the range
    double xf = 6;

    cout << "Part 1: " << endl << endl;

    //h = 0.4 approximation
    euler(x0,y0,h1,xf);

    cout << endl << "Part 2: " << endl << endl;

    //h = 0.2 approximation
    euler(x0,y0,h2,xf);

    return 0;
}

double func(double x, double y)
{
    return ((x*x)-(y*y));
}

void euler(double x0, double y, double h, double x)
{
    double temp = 0;
    ofstream Fout;  //file pointer to output data to file
    Fout.open("Data.txt", ios::out | ios::app);

    if (!Fout)
    {
        cerr << "Error opening data file..." << endl;
        exit(-1);
    }

    // Iterating till the point at which we
    // need approximation
    while (x0 < x)
    {
        temp = y;
        y = y + h * func(x0, y);
        x0 = x0 + h;


    // Printing approximation to data file
    Fout << setw(10) << setprecision(7) << setw(20)
         << y << endl;
    }
    Fout << endl << endl;
    Fout.close();
}
