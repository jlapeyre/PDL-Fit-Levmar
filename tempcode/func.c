#include <strings.h>
/* This file Automatically created and deleted. Do not edit. */
#include<math.h>
#include <stdio.h>


#define FLOAT double
#define JACFUNNAME 
#define FITFUNNAME func
void FITFUNNAME(FLOAT *p, FLOAT *x, int m, int n, FLOAT *t)
{
  int i;
  for(i=0; i<n; ++i){
                     x[i] = p[0] * exp( -t[i]*t[i] * p[1]);
           
  }
}


#undef FLOAT
#undef JACFUNNAME
#undef FITFUNNAME
#define FLOAT float
#define JACFUNNAME s
#define FITFUNNAME sfunc
void FITFUNNAME(FLOAT *p, FLOAT *x, int m, int n, FLOAT *t)
{
  int i;
  for(i=0; i<n; ++i){
                     x[i] = p[0] * exp( -t[i]*t[i] * p[1]);
           
  }
}

