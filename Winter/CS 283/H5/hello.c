#include "csapp.h" 

void *thread(void *vargp); 

int main(int argc, char *argv[]) 
{
	pthread_t tid; 
	long num=strtol(argv[1],NULL,0); 
	for(int i=0; i<num;i++)
	{
		
		Pthread_create(&tid, NULL, thread, NULL);
		Pthread_join(tid, NULL); 
	}


	exit(0); 
}
void *thread(void *vargp) /* Thread routine */ 
{
	printf("Hello, world!\n"); 
	return NULL; 
}
