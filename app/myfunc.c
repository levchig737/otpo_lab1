
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "myfunc.h"

int val;

void qvadr(float a, float b, float c, float* x1, float* x2, int* flag) {
  float d;
  
  // Discriminant
  d = b*b - 4*a*c;

  *flag = 0;

  if (d>0) {
      *x1 = (-b + sqrt(d)) / (2*a);
      *x2 = (-b - sqrt(d)) / (2*a);
  }
  else
    if (d == 0) {
        *x1 = -b/(2*a);
        *x2 = -b/(2*a);
     }
    else
        *flag = 1;
}

