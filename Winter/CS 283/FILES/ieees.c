#include <stdio.h>
#include "ieeep.h"

main()
{
  float f;
  ieees   F;
  unsigned int s,e,m;

  printf("Enter a floating point number:  ");
  scanf("%f",&f);
  printf("f = %f\n",f);

  printf("Internal representation:  \n");
  F.num = f;
  s = F.rep.sign;
  e = F.rep.exp;
  m = F.rep.mant;

  printf("sign = %x\n",s);
  printf("exp = %x\n",e);
  printf("mantissa = %x\n",m);

  printf("Unbiased exponent = %d\n",e-BIAS_S);
}
