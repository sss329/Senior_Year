   #include <pthread.h>
   #include <stdio.h> 
   #include <stdlib.h>
   #define NUM_THREADS 8
   char *messages[NUM_THREADS];

   struct arguments
   {
      char *messages;
      int sum; 
      int t;	
   };

   typedef struct arguments SA; 

   void *PrintHello(void *threadarg)
    {

     int taskid, sum;
     char *hello_msg;
     /* added code here to set input arguments into struct */
     SA *args; 
     args = (SA *)threadarg;
     /* added code here to set the each element in the struct */
     sum = args->sum; 
     hello_msg = args->messages;
     taskid = args->t;  
	
     printf("Thread %d %s Sum=%d\n", taskid, hello_msg, sum);
     pthread_exit(NULL);
    }

   int main(int argc, char *argv[])
    {
     pthread_t threads[NUM_THREADS];
     int rc, t, sum;
     SA *arg; 
     sum=0;
     messages[0] = "Hello-0";
     messages[1] = "Hello-1";
     messages[2] = "Hello-2";
     messages[3] = "Hello-3";
     messages[4] = "Hello-4";
     messages[5] = "Hello-5";
     messages[6] = "Hello-6";
     messages[7] = "Hello-7";
     for(t = 0; t < NUM_THREADS; t++)
      {
       sum = sum + t;
       /* allocated the struct then set the variables in the struct*/
	arg = (SA *) calloc(1,sizeof(SA)); 
	arg->messages = messages[t]; 
	arg->sum = sum;
	arg->t = t; 
       printf("Creating thread %d\n", t);
       /* creat the thread then join once done*/
       pthread_create(&threads[t],NULL, PrintHello, (void *)arg);  
       pthread_join(threads[t],NULL);
      }
     pthread_exit(NULL);
    }
