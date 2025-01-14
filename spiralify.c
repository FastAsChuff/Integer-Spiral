/*=========================================================================================
  Makes a spiral of integers about the origin.
  Author: Simon Goater Jan2025
  Free to copy, modify and create derivatives from with attribution for non-commercial use.
==========================================================================================*/
#ifndef SPIRALIFY
#define SPIRALIFY

#define MAXN 50000

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
  if (t == 0) {
    *x = 0;
    *y = 0;
    return;
  }
  uint32_t sqrtringub = 3;
  uint64_t ringub = 9;
  while (ringub < t) {
    sqrtringub+=2;
    ringub = (uint64_t)sqrtringub*sqrtringub;
  }
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
