/* William Tai
   MATH 428, Spring 2019
   HW#3
   Approximation of round off and truncation errors
   of the first derivative of the function
   f(x) = e^x + sin(x) @ x = 0.5 and initially
   h = 1 and halving it each time for 60 times.
*/

#include <iostream> //Function library for input/output
#include <cmath>    //Function library for math functions like exp, sine and cosine
#include <fstream>  //Function library for file input/output (used for data)
#include <cstdlib>  //Function library for the use of specific commands
#include <iomanip>  //Function library for file manipulation and spacing

using namespace std;        //tells the compiler to treat code in standard form

ofstream FOut;              //output file stream variable name declaration

int main()
{
    double h = 1.0; //h as a double precision variable type initialized as 1.0
    double x = 0.5; //x as a double precision variable type initialized as 0.5
    double TVal = 0.0; //TVal as a double precision variable type initialized as 0.0
    double Approx = 0.0; //Approximate value container
    double TError = 0.0; //Truncation Error container O(h^2)
    double temp = 0.0; //temp container of double precision
    double EPS = 0.5;  //initial value of Machine Epsilon test
    double MEPS = 0.0; //Machine Epsilon container

    //Opens and creates new "Data.txt" file to store the data being calculated
    FOut.open("Data.txt", ios::out | ios::app);

    //checks if the file is successfully opened
    if (!FOut)
    {
        //Error message
        cerr << "Error opening data file...!" << endl;
        exit(-1);
    }

    //File output of parameter titles
    FOut << '\n' << setw(15) << left << "Iteration: " << setw(15)
         << left << "h value: " << setw(15) << left << "Approx: " << endl;

    //code to find the machine epsilon for this computer
    //this number will be added to TError as a precaution
    while ((1 + EPS) != 1)
    {
        //Sets machine epsilon to established epsilon
        MEPS = EPS;

        //computation of epsilon
        EPS = EPS / 2;
    }
    //Sets Truncation Error to include machine epsilon
    TError = TError + MEPS;

    //loop for calculating and writing data to file
    //counts for i = 0 to 59 for a total of 60 times
    for (int i = 0; i < 60; i++)
    {
        //temp set to x + h for computation
        temp = x + h;

        //Calculation of Approximate value
        Approx = (((exp(temp) + cos(temp)) - (exp(x) + cos(x))) / (2 * h));

        //Compute True Value
        TVal = Approx + TError;

        //Output data to file, with precision to 20 decimal places
        FOut << setw(15) << left << i+1 << setw(100) << left << h << setw(100)
             << left << setprecision(52) << TVal << endl;

        //Halving h each iteration
        h = h / 2;
    }

    //closes the data file
    FOut.close();
    return 0;                       //program termination
}
