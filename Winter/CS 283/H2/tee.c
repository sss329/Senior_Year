#include <stdlib.h>
#include<stdio.h> 
#include "csapp.h" 

int main(int argc, char **argv)
{
	char c;
	int len, aflag, option, fd1;
	char *file; 

	
	while((option = getopt(argc, argv, "ap1:b:")) != -1)
	{
		switch (option)
		{
			case 'a': 
			  aflag = 1; 
			  break; 
			default: 
			  break; 
		} 

	}	

	if(aflag == 1) 
	{
		
		file = argv[2];
	        fd1 = open(file, O_CREAT|O_APPEND|O_RDWR,S_IRUSR|S_IWUSR);
		while ((len = read(0 /*stdin*/, &c, 1)) == 1) {
			write(1 /*stdout*/, &c, 1);	
			rio_writen(fd1, &c, 1); 
		}
		if (len < 0) {
			printf ("read from stdin failed");
			exit (10);
		}
		exit(0);
	}	 

	else
	{
		file = argv[1];
	        fd1 = open(file, O_CREAT|O_TRUNC|O_RDWR,S_IRUSR|S_IWUSR);
		while ((len = rio_readn(0 /*stdin*/, &c, 1)) == 1) 
		{
			write(1 /*stdout*/, &c, 1);	
			rio_writen(fd1, &c, 1); 
			
		}
		if (len < 0) {
			printf ("read from stdin failed");
			exit (10);
		}
			exit(0); 

	}
}
