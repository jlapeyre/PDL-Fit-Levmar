
#define FLOAT double

#define MODROSLAM 1E02
/* Modified Rosenbrock problem, global minimum at (1, 1) */
void modros(FLOAT *p, FLOAT *x, int m, int n, void *data)
{
register int i;

  for(i=0; i<n; i+=3){
    x[i]=10*(p[1]-p[0]*p[0]);
	  x[i+1]=1.0-p[0];
	  x[i+2]=MODROSLAM;
  }
}
void jacmodros(FLOAT *p, FLOAT *jac, int m, int n, void *data)
{
register int i, j;

  for(i=j=0; i<n; i+=3){
          jac[j++]=-20.0*p[0];
	  jac[j++]=10.0;

	  jac[j++]=-1.0;
	  jac[j++]=0.0;

	  jac[j++]=0.0;
	  jac[j++]=0.0;
  }
}

#undef FLOAT
#define FLOAT float

#define MODROSLAM 1E02
/* Modified Rosenbrock problem, global minimum at (1, 1) */
void smodros(FLOAT *p, FLOAT *x, int m, int n, void *data)
{
register int i;

  for(i=0; i<n; i+=3){
    x[i]=10*(p[1]-p[0]*p[0]);
	  x[i+1]=1.0-p[0];
	  x[i+2]=MODROSLAM;
  }
}
void sjacmodros(FLOAT *p, FLOAT *jac, int m, int n, void *data)
{
register int i, j;

  for(i=j=0; i<n; i+=3){
          jac[j++]=-20.0*p[0];
	  jac[j++]=10.0;

	  jac[j++]=-1.0;
	  jac[j++]=0.0;

	  jac[j++]=0.0;
	  jac[j++]=0.0;
  }
}
