
#define FLOAT double

/* Boggs - Tolle problem 3 (linearly constrained),*/
/* minimum at (-0.76744, 0.25581, 0.62791, -0.11628, 0.25581) */
// constr1: p[0] + 3*p[1] = 0;
// constr2: p[2] + p[3] - 2*p[4] = 0;
// constr3: p[1] - p[4] = 0;

void bt3(FLOAT *p, FLOAT *x, int m, int n, void *data)
{
register int i;
FLOAT t1, t2, t3, t4;

  t1=p[0]-p[1];
  t2=p[1]+p[2]-2.0;
  t3=p[3]-1.0;
  t4=p[4]-1.0;

  for(i=0; i<n; ++i)
    x[i]=t1*t1 + t2*t2 + t3*t3 + t4*t4;
}

void jacbt3(FLOAT *p, FLOAT *jac, int m, int n, void *data)
{
register int i, j;
FLOAT t1, t2, t3, t4;

  t1=p[0]-p[1];
  t2=p[1]+p[2]-2.0;
  t3=p[3]-1.0;
  t4=p[4]-1.0;

  for(i=j=0; i<n; ++i){
    jac[j++]=2.0*t1;
    jac[j++]=2.0*(t2-t1);
    jac[j++]=2.0*t2;
    jac[j++]=2.0*t3;
    jac[j++]=2.0*t4;
  }
}


#undef FLOAT
#define FLOAT float

/* Boggs - Tolle problem 3 (linearly constrained),*/
/* minimum at (-0.76744, 0.25581, 0.62791, -0.11628, 0.25581) */
// constr1: p[0] + 3*p[1] = 0;
// constr2: p[2] + p[3] - 2*p[4] = 0;
// constr3: p[1] - p[4] = 0;

void sbt3(FLOAT *p, FLOAT *x, int m, int n, void *data)
{
register int i;
FLOAT t1, t2, t3, t4;

  t1=p[0]-p[1];
  t2=p[1]+p[2]-2.0;
  t3=p[3]-1.0;
  t4=p[4]-1.0;

  for(i=0; i<n; ++i)
    x[i]=t1*t1 + t2*t2 + t3*t3 + t4*t4;
}

void sjacbt3(FLOAT *p, FLOAT *jac, int m, int n, void *data)
{
register int i, j;
FLOAT t1, t2, t3, t4;

  t1=p[0]-p[1];
  t2=p[1]+p[2]-2.0;
  t3=p[3]-1.0;
  t4=p[4]-1.0;

  for(i=j=0; i<n; ++i){
    jac[j++]=2.0*t1;
    jac[j++]=2.0*(t2-t1);
    jac[j++]=2.0*t2;
    jac[j++]=2.0*t3;
    jac[j++]=2.0*t4;
  }
}

