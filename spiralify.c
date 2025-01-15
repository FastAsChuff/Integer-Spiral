/*=========================================================================================
  Description: Makes a spiral of integers about the origin.
  Author: Simon Goater 
  Date: Jan 2025
  With conspicuous attribution, permission is granted for this software to freely be copied,
  modified, and used to derive further works for non-commercial use only. No warranty is
  given, and no liability recognised by the author. Use ENTIRELY AT YOUR OWN RISK.
============================================================================================
ChangeLog:-
---------

    Date     Author                    Description Of Change
(YYYY/MM/DD) 

 2025/01/15  Simon Goater              Added isqrt functionality for more efficient spiralify()
                                       evaluation for large t values. Compile with math.h.
==========================================================================================*/
#ifndef SPIRALIFY
#define SPIRALIFY
#define SPIRALIFY_MAXT 1000000000000000000ULL

#ifdef _MATH_H
uint32_t spiralify_isqrt(uint64_t n) {
  if (n < 2) return n;
  uint64_t ai = sqrt(n);
  while (!((ai <= n/ai) && ((ai+1) > n/(ai+1)))) {    
    ai = (ai + n/ai)/2;
  }
  return ai;
}
#endif

void spiralify(int32_t *x, int32_t *y, uint64_t t) {
/*
  Maps Z onto Z^2.
  ================
   12 11 10 09 24
   13 02 01 08 23
   14 03 00 07 22
   15 04 05 06 21
   16 17 18 19 20
*/
  if (t > SPIRALIFY_MAXT) {
    fprintf(stderr,"spiralify() Error! 0 <= t <= %llu required but t = %lu\n", SPIRALIFY_MAXT, t);
    t = 0;
  }
  if (t == 0) {
    *x = 0;
    *y = 0;
    return;
  }
  uint32_t sqrtringub = 3;
  uint64_t ringub = 9;
#ifdef _MATH_H
  sqrtringub = (1+spiralify_isqrt(t))/2;
  sqrtringub = (2*sqrtringub+1);
  ringub = (uint64_t)sqrtringub*sqrtringub;
#else
  while (ringub < t) {
    sqrtringub+=2;
    ringub = (uint64_t)sqrtringub*sqrtringub;
  }
#endif
  if (t >= ringub - sqrtringub) {
    *x = sqrtringub/2;
    *y = -(*x) + t - (ringub - sqrtringub); 
    return;
  }
  if (t >= ringub - 2*sqrtringub + 1) {
    *y = sqrtringub/2;
    *y = -(*y);
    *x = *y + t - (ringub - 2*sqrtringub + 1); 
    return;
  }
  if (t >= ringub - 3*sqrtringub + 2) {
    *x = sqrtringub/2;
    *y = *x - t + (ringub - 3*sqrtringub + 2);
    *x = -(*x);
    return;
  }
  if (t >= ringub - 4*sqrtringub + 3) {
    *y = sqrtringub/2;
    *x = *y - t + (ringub - 4*sqrtringub + 3);
    return;
  }
}

uint64_t spiralify_matrixpos(int32_t x, int32_t y, uint32_t n) {
  int64_t col = x+n;
  int64_t row = n-y;
  return (2*n+1)*row + col;
}
#endif
//=========================================================================================

