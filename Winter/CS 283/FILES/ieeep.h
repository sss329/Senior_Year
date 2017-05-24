/* Note:  The bit fields can change depending on whether the  */
/* the underlying machine is big or little endian.            */

/* This is for the Pentium architecture. */

typedef struct {
  unsigned mant    : 23;
  unsigned exp     : 8;
  unsigned sign    : 1;
  } ieees_rep;  

typedef union {
  float num;
  ieees_rep rep;
  }  ieees;

typedef struct {
  unsigned mant_l  : 32;
  unsigned mant_h  : 20;
  unsigned exp     : 11;
  unsigned sign    : 1;
  } ieeed_rep;  

typedef union {
  double num;
  ieeed_rep rep;
  }  ieeed;

#define BIAS_S 127

#define BIAS_D 1023
#define MAXEXP_D 1023
#define MAXEXP1_D 1024
#define MINEXP_D -1022
#define MINEXP1_D -1023
#define PREC_D 53
#define PREC1_D 52

/* the following three are for ieeedfp only.*/
/* the only role of this program is testing of other programs.*/
#define MAXBEXP_D 2047
#define MINBEXP_D 0
#define DENEXP_D -1022  
