#include<stdio.h>
int bitCount(long int n);
int main(int argc, long int **argv)
{
  unsigned long prt1 = (unsigned long)&argv[0]; 
  unsigned long prt2 = (unsigned long)(&argv[0]+1);
  printf("%s\n","This is the bits in use"); 
  printf("%lu\n", (prt2-prt1)*8);
  printf("%s\n","This is the output of sizeof"); 
  printf("%lu\n", sizeof(argv[0]));

}
