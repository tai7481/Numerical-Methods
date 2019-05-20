/* William Tai
 * MATH 428, Spring 2019
 * Midpoint Method ODE
 */
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

// Function Prototypes
double dydx(double x, double y);
double midp(double x0, double y0, double x, double h);

// Driver
int main()
{
    double x0 = 0, y = 1, h = 0.5;
    //Approximate solutions for x values using RK 4th Order
    double x1 = 0, x2 = 0.5, x3 = 1, x4 = 1.5, x5 = 2;

    cout << "The approximate solution for x at " << setw(5) << x1
         << " is: " << setprecision(8) << midp(x0, y, x1, h)
         << endl;
    cout << "The approximate solution for x at " << setw(5) << x2
         << " is: " << setprecision(8) << midp(x0, y, x2, h)
         << endl;
    cout << "The approximate solution for x at " << setw(5) << x3
         << " is: " << setprecision(8) << midp(x0, y, x3, h)
         << endl;
    cout << "The approximate solution for x at " << setw(5) << x4
         << " is: " << setprecision(8) << midp(x0, y, x4, h)
         << endl;
    cout << "The approximate solution for x at " << setw(5) << x5
         << " is: " << setprecision(8) << midp(x0, y, x5, h)
         << endl;

    return 0;
}

double dydx(double x, double y)
{
    return(y*x*x-1.1*y);
}

// Finds value of y for a given x using step size h
// and initial value y0 at x0.
double midp(double x0, double y0, double x, double h)
{
    // Count number of iterations using step size or
    // step height h
    int n = (int)((x - x0) / h);

    double k1, k2;

    // Iterate for number of iterations
    double y = y0;
    for (int i = 1; i <= n; i++)
    {
        // Apply midpoint Formulas to find
        // next value of y
        k1 = h*dydx(x0, y);
        k2 = h*dydx(x0 + 0.5*h, y + 0.5*k1);


        // Update next value of y
        y = y + (1.0/2.0)*(k1 + 2*k2);;

        // Update next value of x
        x0 = x0 + h;
    }

    return y;
}
