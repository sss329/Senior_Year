#include "csapp.h" 

void *thread(void *vargp); 

int main(int argc, char *argv[]) 
{
	pthread_t tid; 
	//set argument string to number 
	int num=atoi(argv[1]); 
	//creat thread and run thread routine
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
