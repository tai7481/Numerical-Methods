/* William Tai
 * MATH 428, Spring 2019
 * Runge-Kutta 4th Order ODE
 */
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

// Function Prototypes
double dydx(double x, double y);
double RungeKutta(double x0, double y0, double x, double h);

// Driver
int main()
{
    double x0 = 0, y = 2.75, h = 1;
    //Approximate solutions for x values using RK 4th Order
    double x1 = 7486, x2 = 7487.99, x3 = 7488;//, x4 = 7488, x5 = 7489;

    cout << "The approximate solution for x at " << setw(7) << x1
         << " is: " << setprecision(8) << RungeKutta(x0, y, x1, h)
         << endl;
    cout << "The approximate solution for x at " << setw(7) << x2
         << " is: " << setprecision(8) << RungeKutta(x0, y, x2, h)
         << endl;
    cout << "The approximate solution for x at " << setw(7) << x3
         << " is: " << setprecision(8) << RungeKutta(x0, y, x3, h)
         << endl;

    return 0;
}

double dydx(double x, double y)
{
    return((-0.00012375*sqrt(19.62*y))/(3*y-y*y));
}

// Finds value of y for a given x using step size h
// and initial value y0 at x0.
double RungeKutta(double x0, double y0, double x, double h)
{
    // Count number of iterations using step size or
    // step height h
    int n = (int)((x - x0) / h);

    double k1, k2, k3, k4;

    // Iterate for number of iterations
    double y = y0;
    for (int i = 1; i <= n; i++)
    {
        // Apply Runge-Kutta Formulas to find
        // next value of y
        k1 = h*dydx(x0, y);
        k2 = h*dydx(x0 + 0.5*h, y + 0.5*k1);
        k3 = h*dydx(x0 + 0.5*h, y + 0.5*k2);
        k4 = h*dydx(x0 + h, y + k3);

        // Update next value of y
        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);;

        // Update next value of x
        x0 = x0 + h;
    }

    return y;
}
