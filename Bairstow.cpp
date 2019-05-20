/****************************************************
* ------------------------------------------------- *
* Example: Find two complex roots of polynomial:    *
*            f(x) = x^5-10x^4+35x^3-50x^2+24x       *
*                                                   *
* SAMPLE RUN:                                       *
*                                                   *
* Input order of polynomial: 5                      *
*                                                   *
* Input the polynomial coefficients:                *
*                                                   *
*    A(0) =  0                                      *
*    A(1) =  24                                     *
*    A(2) =  -50                                    *
*    A(3) =  35                                     *
*    A(4) =  -10                                    *
*    A(5) =  1                                      *
*                                                   *
* Convergence factor: 0.000001                      *
* Maximum number of iterations: 50                  *
*                                                   *
* The roots found are:                              *
*                                                   *
*      X1 =  1.000000                               *
*      Y1 =  0.000000                               *
*                                                   *
*      X2 =  0.000000                               *
*      Y2 =  0.000000                               *
*                                                   *
* The number of iterations was:  11                 *
*                                                   *
****************************************************/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>

double A[10],B[10],C[10],D[10];
int    i,k,m,n;
double aa,bb,e,PI,x1,x2,yy1,y2;


/*************************************************
*       Bairstow complex root subroutine         *
* ---------------------------------------------- *
* INPUTS:                                        *
*  Polynomial coefficients      : A(0) to A(m)   *
*  Order of polynomial (>=4)    : m              *
*  Initial guess                : a and b        *
*  Convergence factor           : e              *
*  Maximum number of iterations : n              *
* OUTPUTS:                                       *
*  Two conjugate complex roots  : x1,y1  x2,y2   *
*  Number of iterations         : k              *
*************************************************/
void Bairstow()
{
  // Labels: e100,e200,e300,e400
  int i,j;
  double a1, b1, cc, dd, d2;

  //Normalize the A[i] series
  for (i=0; i<m+1; i++)
  {
      C[i]=A[i]/A[m];
  }

  //Take initial estimates for aa and bb
  k=0;
  B[m]=1.0;

  //Start iteration sequence
e100: B[m-1]=C[m-1]-aa;
  for (j=2; j<m; j++)
  {
      B[m-j]=C[m-j]-aa*B[m+1-j]-bb*B[m+2-j];
  }

  B[0]=C[0]-bb*B[2];
  D[m-1]=-1.0; D[m-2]=-B[m-1]+aa;

  for (j=3; j<m; j++)
  {
      D[m-j]=-B[m+1-j]-aa*D[m+1-j]-bb*D[m+2-j];
  }

  D[0]=-bb*D[2];
  d2=-B[2]-bb*D[3];
  dd=D[1]*d2-D[0]*D[2];
  a1=-B[1]*d2+B[0]*D[2]; a1=a1/dd;
  b1=-D[1]*B[0]+D[0]*B[1]; b1=b1/dd;
  aa=aa+a1; bb=bb+b1; k=k+1;

  //Test for the number of iterations
  if (k>=n) goto e200;

  //Test for convergence
  if (fabs(a1)+fabs(b1)>e*e) goto e100;

  //Extract roots from quadratic equation
e200: cc=aa*aa-4.0*bb;

  //Test to see if a complex root
  if (cc>0)
    goto e300;

  x1=-aa; x2=x1; yy1=sqrt(-cc); y2=-yy1;

  goto e400;

e300: x1=-aa+sqrt(cc);
  x2=-aa-sqrt(cc); yy1=0; y2=yy1;

e400: x1=x1/2.0; x2=x2/2.0; yy1=yy1/2.0; y2=y2/2.0;
}

int main()
{
  PI = 4*atan(1);

  printf("\n Order of polynomial: "); scanf("%d",&m);
  printf("\n Input the polynomial coefficients:\n\n");
  for (i=0; i<m+1; i++) {
    printf("     A(%d) = ",i); scanf("%lf",&A[i]);
  }
  printf("\n Convergence factor: "); scanf("%lf",&e);
  printf(" Maximum number of iterations: "); scanf("%d",&n);

  aa=PI; bb=sqrt(2.0);

  Bairstow();     // Call Bairstow subroutione

  printf("\n The roots found are:\n");
  printf("\n      X1 = %f\n", x1);
  printf("      Y1 = %f\n", yy1);
  printf("\n      X2 = %f\n", x2);
  printf("      Y2 = %f\n", y2);
  printf("\n The number of iterations was: %d\n\n", k);

  return 0;
}
