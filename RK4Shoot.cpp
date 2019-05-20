/* William Tai
 * MATH428, SP19
 * Shooting method
 * with RK4
 */

 #include <iostream>
 #include <cstdlib>
 #include <cmath>
 #include <iomanip>

 using namespace std;

 //function prototypes
 double f1(double x, double y, double z);   //first function
 double f2(double x, double y, double z);   //second function
 double Shoot(double x0, double y0, double xf, double yf, double h, double alpha);

 int main()
 {
     //initial or given conditions
     double xi, xf, yi, yf, h, alpha;
     xi = 0;
     xf = 1500;
     yi = 20;
     yf = 10;
     h = 5;

     cout << "\nEnter your estimate for alpha: ";
     cin >> alpha;

     cout << "The solution for your alphas is: " << setprecision(8)
          << "\t\t\t" << Shoot(xi, yi, xf, yf, h, alpha) << endl;

     return 0;
 }

 double f1(double x, double y, double z)
 {
     return z;
 }

 double f2(double x, double y, double z)
 {
     return (-0.0002/y);
 }
 double Shoot(double x0, double y0, double xf, double yf, double h, double alpha)
 {
    double x, y, z, k1, k2, k3, k4, j1, j2, j3, j4, k, j, x1, y1, z1;
    double ymax = 0.0, xmax = 0.0;
    x = x0;
    y = y0;
    z = alpha;
    do  //RK4-2nd derivative algorithm
    {
        k1 = h * f1(x,y,z);
        j1 = h * f2(x,y,z);
        k2 = h * f1(x + h/2.0, y + k1/2.0, z + j1/2.0);
        j2 = h * f2(x + h/2.0, y + k1/2.0, z + j1/2.0);
        k3 = h * f1(x + h/2.0, y + k2/2.0, z + j2/2.0);
        j3 = h * f2(x + h/2.0, y + k2/2.0, z + j2/2.0);
        k4 = h * f1(x + h, y + k3, z + j3);
        j4 = h * f2(x + h, y + k3, z + j3);
        j = (1.0/6.0)*(j1 + 2*j2 + 2*j3 + j4);
        k = (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);
        y1 = y + k;
        x1 = x + h;
        z1 = z + j;
        x = x1;
        y = y1;
        z = z1;

        if (y > ymax)
        {
            ymax = y;
            xmax = x;
        }
    }while(x < xf);

    cout << "Max water depth: " << setprecision(5) << ymax
         << " @ x = " << "\t\t\t" << xmax << endl;
    return y;
 }
