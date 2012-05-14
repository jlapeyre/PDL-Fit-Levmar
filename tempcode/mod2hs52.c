
#define FLOAT double

void mod2hs52(double *p, double *x, int m, int n, void *data)
{
  x[0]=4.0*p[0]-p[1];
  x[1]=p[1]+p[2]-2.0;
  x[2]=p[3]-1.0;
  x[3]=p[4]-1.0;
  x[4]=p[0]-0.5;
}

void jacmod2hs52(double *p, double *jac, int m, int n, void *data)
{
register int j=0;

  jac[j++]=4.0;
  jac[j++]=-1.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;

  jac[j++]=0.0;
  jac[j++]=1.0;
  jac[j++]=1.0;
  jac[j++]=0.0;
  jac[j++]=0.0;

  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=1.0;
  jac[j++]=0.0;

  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=1.0;

  jac[j++]=1.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
}
     
#undef FLOAT
#define FLOAT float

void smod2hs52(double *p, double *x, int m, int n, void *data)
{
  x[0]=4.0*p[0]-p[1];
  x[1]=p[1]+p[2]-2.0;
  x[2]=p[3]-1.0;
  x[3]=p[4]-1.0;
  x[4]=p[0]-0.5;
}

void sjacmod2hs52(double *p, double *jac, int m, int n, void *data)
{
register int j=0;

  jac[j++]=4.0;
  jac[j++]=-1.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;

  jac[j++]=0.0;
  jac[j++]=1.0;
  jac[j++]=1.0;
  jac[j++]=0.0;
  jac[j++]=0.0;

  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=1.0;
  jac[j++]=0.0;

  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=1.0;

  jac[j++]=1.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
  jac[j++]=0.0;
}
     