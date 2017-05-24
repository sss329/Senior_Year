#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 128 

int main (int argc, char **argv)  
 {
   char line[SIZE];
   FILE *fp;
   int i=0;
   int j=0;
   char *array[100000];

   fp = fopen(argv[1],"r");

   if (fp == NULL) 
	{
	  printf("file NULL \n");
	return 1;  
	}
    while(fgets(line, SIZE , fp) != NULL)
	{
           array[i] = malloc(100*sizeof(line)); 
           strcpy(array[i],line);
	   i++; 
 	}
       for(j=i-1;j>=0;j--) 
        {
	  printf("%s", array[j]);
	}  
   } 
