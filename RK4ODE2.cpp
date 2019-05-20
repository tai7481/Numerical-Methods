/* William Tai
 * MATH 428, SP19
 * Runge-Kutta 4th Order
 * 2nd Order ODE
 */

 #include <iostream>
 #include <cstdlib>
 #include <cmath>
 #include <iomanip>

 using namespace std;

 double d2x(double t, double x, double y);
 double dx(double t, double x, double y);
 void RK42O(double t0, double x0, double y0, double h, double t1);

 int main()
 {
     double t0, t1, x0, y0, h;

     t0 = 0;
     t1 = 15;
     x0 = 1;
     y0 = 0;
     h = 0.5;

     RK42O(t0, x0, y0, h, t1);

     return 0;
 }

 //dy/dt
 double d2x(double t, double x, double y)
 {
     double f2;
     f2 = (-5*y-20*x)/20;
     return f2;
 }

 //dx/dt
 double dx(double t, double x, double y)
 {
     double f1;
     f1 = y;
     return f1;
 }

 //RK4 iterations
 void RK42O(double t0, double x0, double y0, double h, double t1)
 {
     int i, n;
     double k1, k2, k3, k4, j1, j2, j3, j4;
     n = (t1-t0)/h;
     double *t = (double *) calloc(n + 1, sizeof(double));
     double *x = (double *) calloc(n + 1, sizeof(double));
     double *y = (double *) calloc(n + 1, sizeof(double));

     t[0] = t0;
     x[0] = x0;
     y[0] = y0;

     for (i = 0; i < n + 1; i++)
     {
         k1 = dx(t[i], x[i], y[i]);
         j1 = d2x(t[i], x[i], y[i]);

         k2 = dx(t[i]+h/2, x[i]+h*k1*0.5, y[i]+h*j1*0.5);
         j2 = d2x(t[i]+h/2, x[i]+h*k1*0.5, y[i]+h*j1*0.5);

         k3 = dx(t[i]+h/2, x[i]+h*k2*0.5, y[i]+h*j2*0.5);
         j3 = d2x(t[i]+h/2, x[i]+h*k2*0.5, y[i]+h*j2*0.5);

         k4 = dx(t[i]+h, x[i]+h*k3, y[i]+h*j3);
         j4 = d2x(t[i]+h, x[i]+h*k3, y[i]+h*j3);

         t[i+1] = t[i] + h;
         x[i+1] = x[i] + h*(k1+2*k2+2*k3+k4)/6;
         y[i+1] = y[i] + h*(k1+2*k2+2*k3+k4)/6;

         cout << "t = " << setprecision(7) << setw(10) << t[i+1]
              << " x = " << setprecision(7) << setw(10) << x[i+1]
              << " y = " << setprecision(7) << setw(10) << y[i+1]
              << endl << endl;
     }
 }
