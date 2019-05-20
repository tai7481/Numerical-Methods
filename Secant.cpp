/* C++ Program to find root of an
 * equations using Secant method
 * William Tai
 * MATH 428, Spring 2019
 * Take Home Exam 1
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x);
void Secant(double x1, double x2, double E);

int main()
{
    // initializing the values
    double x1 = 0;    //first initial guess
    double x2 = 1000;    //second initial guess
    double E = 0.00001; //tolerance

    Secant(x1, x2, E);  //function call while passing
                        //first/second guesses as well
                        //as the error tolerance

    return 0;
}

//Calculates the function value with given
//x values
double f(double x)
{
    //we are taking the equation with constants filled out
    //in Problem 2
    double f = (22320/(x-((x-36580)/3742)*x*(-1.23+0.0003686*x)))
             + (930.3/(x-((x-2387)/3742)*x*(-1.23+0.0003686*x))) - 1;

    return f;
}

void Secant(double x1, double x2, double E)
{
    double xm;  //possible root container
    double x0;  //intermediate value container
    double c;
    int n = 0;  //counter for number of iterations

    if (f(x1) * f(x2) < 0) {
        do
        {
            // calculate the intermediate value
            x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));

            // check if x0 is root of equation or not
            c = f(x1) * f(x0);

            // update the value of interval
            x1 = x2;
            x2 = x0;

            // update number of iteration
            n++;

            // if x0 is the root of equation then break the loop
            if (c == 0.0)
                break;
            xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        } while ((fabs(xm - x0)/xm) >= E); //Repeat until relative error is < 0.00001

        cout << "Root of the given equation = " << setprecision(8)
             << x0 << endl; //outputs roots with precision of 8 sig figs
        cout << "No. of iterations = " << n << endl;
    }
    else
        cout << "Cannot find a root in the given interval";
}
