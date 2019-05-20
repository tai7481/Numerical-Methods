#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

#define EPSILON 0.0000000000001

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
void newtonRaphson2(double x1, double x2)
{
    double y1, y2, dy, temp, h; //variable declaration

    y1 = func(x1);
    y2 = func(x2);
    dy = derivFunc(x1);

    h = (x1-x2)/(1-(y2/y1)*(((y2-y1)/(x2-x1))/dy));
    cout << setprecision(20) << h << endl;

    while (abs(h) >= EPSILON)  //loop
    {
        y1 = func(x1);     //f(x1)
        y2 = func(x2);     //f(x2)
        dy = derivFunc(x1); //f'(x1)

        h = (x1-x2)/(1-(y2/y1)*(((y2-y1)/(x2-x1))/dy));

        temp = x2;
        x2 = x1 - h;
        x1 = temp;
    }

    cout << "The value of the root is : " << setprecision(20)
         << x2 << endl;
}

// Driver program to test above
int main()
{
    double x0 = 2, x1 = 3; // Initial values assumed
    //double x0 = 6, x1 = 7;
    //double x0 = 8, x1 = 8.5;
    newtonRaphson2(x0, x1);
    return 0;
}
