#include <stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) 
{
  
  int R;
  long B = 0, i =1; 
  long  n = atoi(argv[1]);
 
	
   while( n !=0 )
    {
	R =n%2; 
 	n = n/2; 
	B = B + (R*i); 
        i = i*10;
    } 
   
   printf("%ld\n", B); 
  
}
