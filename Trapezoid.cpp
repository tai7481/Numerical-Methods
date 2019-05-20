/* William Tai
 * MATH 428, SP19
 * Trapezoidal Integration
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

//function prototypes
double y(double x);   //function
double Trapezoid(double a, double b, double n);

// Driver
int main()
{
    // Limits of integration
    double x0 = 0;
    double xf = 4;
    //The three different n steps
    int n1 = 5, n2 = 10, n3 = 20;

    cout << "With n = " << setw(5) << n1 << " Value of integral is: "
         << "\t\t\t" << setprecision(6) << Trapezoid(x0, xf, n1)
         << endl << endl;
    cout << "With n = " << setw(5) << n2 << " Value of integral is: "
         << "\t\t\t" << setprecision(6) << Trapezoid(x0, xf, n2)
         << endl << endl;
    cout << "With n = " << setw(5) << n3 << " Value of integral is: "
         << "\t\t\t" << setprecision(6) << Trapezoid(x0, xf, n3)
         << endl << endl;
    return 0;
}

double y(double x)
{
    // function declaration
    return (x*(1-x)*exp(-x));
}

double Trapezoid(double a, double b, double n)
{
    // Grid spacing
    double h = (b - a)/n;

    // Computing sum of first and last terms
    double s = y(a) + y(b);

    // Adding middle terms in above formula
    for (int i = 1; i < n; i++)
    {
        s = s + 2*y(a+i*h);
    }

    // h/2 indicates (b-a)/2n. Multiplying h/2
    // with s.
    return (h/2)*s;
}
