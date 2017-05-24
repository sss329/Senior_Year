   #include <pthread.h>
   #include<stdio.h> 
   #include<stdlib.h>
   #define NUMTHRDS 4
   #define VECLEN 100000
   pthread_t callThd[NUMTHRDS];
   double *array_a;
   double *array_b;
   double big_sum;
   int veclen;
   //create mutex lock
   pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
   //create structure for arguments 
   struct arguments
   { 
	long start;
	long end;
   };
  //create struct type arguments 
   typedef struct arguments SA; 
   //dotprod function
   void *dotprod(void *arg)
    {
     /* set arguments */
     SA *args; 
     args = (SA *)arg; 
     double *x = array_a;
     double *y = array_b;
     /* set start and end*/
     long start = args->start; 
     long end = args->end; 
     double mysum = 0;
     for (int i=start; i<end ; i++)
      {
       mysum += (x[i] * y[i]);
      }
     /* lock mutex then wrtie to bigsum*/
     pthread_mutex_lock( &mutex ); 
     big_sum = mysum + big_sum;
     pthread_mutex_unlock( &mutex );  
     /* exit the thread*/
     pthread_exit(NULL); 
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
        SA *arg = (SA *) calloc(1,sizeof(SA)); 
	arg->start = 0; 
	arg->end = VECLEN; 
        pthread_create(&callThd[i],NULL,dotprod, (void *)arg); 
	//pthread_join(callThd[i],NULL); 
      }
     /* Wait on the other threads */
    for ( i = 0; i < NUMTHRDS; i++)
       pthread_join(callThd[i], NULL);     
     /* ... */
     printf ("Sum = %f \n", big_sum);
     free (a);
     free (b);
    }
