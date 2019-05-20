#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

#define EPSILON 0.00000001

using namespace std;

double func(double x)
{
    return ((4-x)*exp(-0.5*x)-2);
}

double derivFunc(double x)
{
    return (0.5*x*exp(-0.5*x)-3*exp(-0.5*x));
}

// Function to find the root
void newtonRaphson(double x)
{
    double h = func(x) / derivFunc(x);
    while (abs(h) >= EPSILON)
    {
        h = func(x)/derivFunc(x);

        // x(i+1) = x(i) - f(x) / f'(x)
        x = x - h;
    }

    cout << "The value of the root is : " << setprecision(20)
         << x << endl;
}

// Driver program to test above
int main()
{
    //double x0 = 2; // Initial values assumed
    //double x0 = 6;
    double x0 = 8;
    newtonRaphson(x0);
    return 0;
}
