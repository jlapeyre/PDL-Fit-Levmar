/* This file Automatically created and deleted. Do not edit. */
#include<math.h>
#include <stdio.h>



#define FLOAT double
#define JACFUNNAME jacgaussian1
#define FITFUNNAME gaussian1
void JACFUNNAME(FLOAT *p, FLOAT *d, int m, int n, FLOAT *t)
{
  int i,j;
FLOAT arg, expf;
  for(i=j=0; i<n; ++i){
arg = t[i] - p[1];
expf = exp(-arg*arg*p[2]);
   d[j++] = expf;
   d[j++] = p[0] * 2 * arg * p[2] *expf;
   d[j++] = p[0]*(-arg*arg)*expf;
  }
}

void FITFUNNAME(FLOAT *p, FLOAT *x, int m, int n, FLOAT *t)
{
  int i;
  for(i=0; i<n; ++i){
x[i] = p[0] * exp(-(t[i]-p[1])*(t[i]-p[1])*p[2]);

  }
}


#undef FLOAT
#undef JACFUNNAME
#undef FITFUNNAME
#define FLOAT float
#define JACFUNNAME sjacgaussian1
#define FITFUNNAME sgaussian1
void JACFUNNAME(FLOAT *p, FLOAT *d, int m, int n, FLOAT *t)
{
  int i,j;
FLOAT arg, expf;
  for(i=j=0; i<n; ++i){
arg = t[i] - p[1];
expf = exp(-arg*arg*p[2]);
   d[j++] = expf;
   d[j++] = p[0] * 2 * arg * p[2] *expf;
   d[j++] = p[0]*(-arg*arg)*expf;
  }
}

void FITFUNNAME(FLOAT *p, FLOAT *x, int m, int n, FLOAT *t)
{
  int i;
  for(i=0; i<n; ++i){
x[i] = p[0] * exp(-(t[i]-p[1])*(t[i]-p[1])*p[2]);

  }
}

