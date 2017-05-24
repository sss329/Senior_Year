   #include <pthread.h>
   #define NUMTHRDS 4
   #define VECLEN 100000
   pthread_t callThd[NUMTHRDS];
   double *array_a;
   double *array_b;
   double big_sum;
   int veclen;
   void *dotprod(void *arg)
    {
     /* ... */
     x = array_a;
     y = array_b;
     /* ... */
     mysum = 0;
     for (i=start; i<end ; i++)
      {
       mysum += (x[i] * y[i]);
      }
     /* ... */
     /* ... */
    }
   int main (int argc, char *argv[])
    {
     long i;
     double *a, *b;
     void *status;
     a = (double*) malloc (NUMTHRDS*VECLEN*sizeof(double));
     b = (double*) malloc (NUMTHRDS*VECLEN*sizeof(double));
     for (i=0; i<VECLEN*NUMTHRDS; i++)
      {
       a[i]=1;
       b[i]=a[i];
      }
     veclen = VECLEN;
     array_a = a;
     array_b = b;
     big_sum = 0;
     /* ... */
     /* create threads */
     /* ... */
     for(i=0;i<NUMTHRDS;i++)
      {
       /* Each thread works on a different set of data.
          The offset is specified by 'i'. The size of
          the data for each thread is indicated by VECLEN.
       */
      }
     /* Wait on the other threads */
     /* ... */
     printf ("Sum = %f \n", big_sum);
     free (a);
     free (b);
    }
