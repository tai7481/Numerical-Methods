#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.141592654;

int main()
{
    double a, b, c, x1, x2, r, discriminant, realPart, imaginaryPart;
    r = 2.06;
    a = 1-(r*r); b = 2-(r*r);
    double angle = 34.0, temp = sin(angle * PI / 180.0), square = temp * temp;
    c = 1 - square;
    cout << setprecision(30) << c << endl;
    discriminant = b*b - 4*a*c;

    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "Roots are real and different." << endl;
        cout << "x1 = " << setprecision(30) << x1 << endl;
        cout << "x2 = " << setprecision(30) << x2 << endl;
    }

    else if (discriminant == 0) {
        cout << "Roots are real and same." << endl;
        x1 = (-b + sqrt(discriminant)) / (2*a);
        cout << "x1 = x2 =" << x1 << endl;
    }

    else {
        realPart = -b/(2*a);
        imaginaryPart =sqrt(-discriminant)/(2*a);
        cout << "Roots are complex and different."  << endl;
        cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
    }

    return 0;
}
