// C++ Program to find root of a function, f(x)
// using Muller's method for finding
// polynomial roots.
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#define Eps = 0.000000001

using namespace std;

const int MAX_ITERATIONS = 10000;

double f(double x);
void Muller(double a, double b, double c);

// Driver main function
int main()
{
    double a = 2, b = 0, c = -2;
    Muller(a, b, c);

    return 0;
}

// Function to calculate f(x)
double f(double x)
{
    // Taking f(x) = x^3 - x^2 + 2x - 2
    return (x*x*x) - (x*x) + (2*x) - 2;
}

void Muller(double a, double b, double c)
{
    int i;
    double res, x, y;
    double realpart, imagpart, a0, a1, a2;

    for (i = 0;;i++)
    {
        // Calculating various constants required
        // to calculate x3
        double f1 = f(a);
        double f2 = f(b);
        double f3 = f(c);
        double d1 = f1 - f3;
        double d2 = f2 - f3;
        double h1 = a - c;
        double h2 = b - c;
        a0 = f3;
        a1 = (((d2 * pow(h1, 2)) - (d1 * pow(h2, 2)))
                    / ((h1 * h2) * (h1 - h2)));

        a2 = (((d1*h2) - (d2*h1))/((h1*h2) * (h1-h2)));
        x = ((-2*a0) / (a1 + abs(sqrt(a1*a1-4*a0*a2))));
        y = ((-2*a0) / (a1-abs(sqrt(a1*a1-4*a0*a2))));
        realpart = a1;
        imagpart = abs(sqrt(a1*a1-4*a0*a2));

        // Taking the root which is closer to x2
        if (x >= y)
            res = x + c;
        else
            res = y + c;

        // checking for resemblance of x3 with x2 till
        // two decimal places
        double m = res * 100;
        double n = c * 100;
        m = floor(m);
        n = floor(n);
        if (m == n)
            break;
        a = b;
        b = c;
        c = res;
        if (i > MAX_ITERATIONS)
        {
            cout << "Root cannot be found using"
                 << " Muller's method" << endl;
            break;
        }
    }
    if (i <= MAX_ITERATIONS)
    {
        cout << "The real root is: " << setprecision(8)
             << res << endl;
    }
}
