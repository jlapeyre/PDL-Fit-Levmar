#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#include "lm.h"

/* Meyer's (reformulated) problem, minimum at (2.48, 6.18, 3.45) */
void gaussian(double *p, double *x, int m, int n, void *data)
{
  register int i;
  double L = 10;
  double ui;
  for(i=0; i<n; ++i){
    ui= (double)(i*L)/(double)n - L/2;
    x[i]= p[1] * exp(-ui*ui*(p[0]*p[0]));
  }
}

void jacgaussian(double *p, double *jac, int m, int n, void *data)
{
  register int i,j;
  double ui;
  double L = 10;
  for(i=j=0; i<n; ++i){
    ui= (double)(i*L)/(double)n - L/2;
    jac[j++]= -p[1]*ui*ui*2*p[0] * exp(-ui*ui*(p[0]*p[0]));
    jac[j++]= exp(-ui*ui*(p[0]*p[0]));
  }
}

int main ()
{
  int i,j, ret;
  int N = 100;
  int m = 2;
  double p[10], x[N];
  double covar[m*m];

  double opts[LM_OPTS_SZ], info[LM_INFO_SZ];

  opts[0]=LM_INIT_MU; opts[1]=1E-15; opts[2]=1E-15; opts[3]=1E-20;
  opts[4]=LM_DIFF_DELTA; // relevant only if the finite difference jacobian version is used 

  p[0] = 2.0;
  p[1] = 2.5;

  gaussian(p,x,1,N,NULL); // setup gaussian

   x[50] += .1;
   x[70] += .2;
  p[0] = 4.0;  // change starting parameter
  p[1] = 3.0;  // change starting parameter
  ret = dlevmar_der(gaussian, jacgaussian, p, x, m, N, 
	      1000, opts, info, NULL, covar, NULL); // with analytic jacobian


  printf("Covariance of the fit:\n");
  for(i=0; i<m; ++i){
    for(j=0; j<m; ++j)
      printf("%g ", covar[i*m+j]);
    printf("\n");
  }
  printf("\n");


  printf("Levenberg-Marquardt returned %d in %g iter, reason %g\nSolution: ", ret, info[5], info[6]);
  for(i=0; i<m; ++i)
    printf("%.7g ", p[i]);
  printf("\n\nMinimization info:\n");
  for(i=0; i<LM_INFO_SZ; ++i)
    printf("%g ", info[i]);
  printf("\n");


  return 0;
}
