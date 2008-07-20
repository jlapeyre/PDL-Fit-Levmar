#include <math.h>
#include <stdio.h>

void gauss_from_c(FLOAT *p, FLOAT *x, int m, int n, void *data)
{
  int i;
  FLOAT *t = (FLOAT *) data;
  for(i=0; i<n; ++i){
   x[i] = p[0] * exp(-(t[i] - p[1])*(t[i] - p[1])*p[2]);
  }
}
