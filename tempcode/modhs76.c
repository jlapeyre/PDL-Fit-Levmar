
#define FLOAT double


#include <math.h>
#include <stdio.h>
void modhs76(double *p, double *x, int m, int n, void *data)
{
  x[0]=p[0];
  x[1]=sqrt(0.5)*p[1];
  x[2]=p[2];
  x[3]=sqrt(0.5)*p[3];
}

void jacmodhs76(double *p, double *jac, int m, int n, void *data)
{
register int j=0;

  jac[j++]=1.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;

  jac[j++]=0.0;
  jac[j++]=sqrt(0.5);
  jac[j++]=0.0;
  jac[j++]=0.0;

  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=1.0;
  jac[j++]=0.0;

  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=sqrt(0.5);
}

#undef FLOAT
#define FLOAT float


#include <math.h>
#include <stdio.h>
void smodhs76(double *p, double *x, int m, int n, void *data)
{
  x[0]=p[0];
  x[1]=sqrt(0.5)*p[1];
  x[2]=p[2];
  x[3]=sqrt(0.5)*p[3];
}

void sjacmodhs76(double *p, double *jac, int m, int n, void *data)
{
register int j=0;

  jac[j++]=1.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;

  jac[j++]=0.0;
  jac[j++]=sqrt(0.5);
  jac[j++]=0.0;
  jac[j++]=0.0;

  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=1.0;
  jac[j++]=0.0;

  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=sqrt(0.5);
}
