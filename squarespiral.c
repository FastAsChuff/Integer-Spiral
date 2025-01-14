#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include </home/simon/spiralify.c>

// Inspired by https://www.youtube.com/watch?v=OcYXKNk0lK0
// Sub is @ S(t) = u + vt for some u,v in Z
// Check @ x(t) + y(t)t for t>=0 until equal to S(t).

// gcc squarespiral.c -o squarespiral.bin -O3 -march=native -Wall -std=c11

int main(int argc, char* argv[]) {
  uint32_t n = 3;
  int32_t x,y; 
  uint32_t digits;
  uint64_t m, digitsub;
  if (argc > 1) n = atol(argv[1]);
  if (n > MAXN) { 
    printf("1 < n <= %u\n", MAXN);
    exit(0); 
  }
  m = (2*n+1)*(2*n+1);
  /*
  for (uint64_t i = 0; i<m; i++) {
    spiralify(&x, &y, i);
    printf("%lu (%i, %i)\n", i,x,y);    
  }
  exit(0);
  */
  uint64_t *matrix = malloc(m*sizeof(uint64_t));
  digits = 1;
  digitsub = 10;
  while (digitsub <= m) {
    digits++;
    digitsub *= 10;
  }
  for (uint64_t i = 0; i<m; i++) {
    spiralify(&x, &y, i);
    matrix[spiralify_matrixpos(x, y, n)] = i;
  }
  for (uint64_t i = 0; i<(2*n+1); i++) {
    for (uint64_t j = 0; j<(2*n+1); j++) {
      printf("%0*lu ", digits, matrix[i*(2*n+1) + j]);
    }
    printf("\n");
  }
  free(matrix);
}

/*
./squarespiral.bin 10
380 379 378 377 376 375 374 373 372 371 370 369 368 367 366 365 364 363 362 361 440 
381 306 305 304 303 302 301 300 299 298 297 296 295 294 293 292 291 290 289 360 439 
382 307 240 239 238 237 236 235 234 233 232 231 230 229 228 227 226 225 288 359 438 
383 308 241 182 181 180 179 178 177 176 175 174 173 172 171 170 169 224 287 358 437 
384 309 242 183 132 131 130 129 128 127 126 125 124 123 122 121 168 223 286 357 436 
385 310 243 184 133 090 089 088 087 086 085 084 083 082 081 120 167 222 285 356 435 
386 311 244 185 134 091 056 055 054 053 052 051 050 049 080 119 166 221 284 355 434 
387 312 245 186 135 092 057 030 029 028 027 026 025 048 079 118 165 220 283 354 433 
388 313 246 187 136 093 058 031 012 011 010 009 024 047 078 117 164 219 282 353 432 
389 314 247 188 137 094 059 032 013 002 001 008 023 046 077 116 163 218 281 352 431 
390 315 248 189 138 095 060 033 014 003 000 007 022 045 076 115 162 217 280 351 430 
391 316 249 190 139 096 061 034 015 004 005 006 021 044 075 114 161 216 279 350 429 
392 317 250 191 140 097 062 035 016 017 018 019 020 043 074 113 160 215 278 349 428 
393 318 251 192 141 098 063 036 037 038 039 040 041 042 073 112 159 214 277 348 427 
394 319 252 193 142 099 064 065 066 067 068 069 070 071 072 111 158 213 276 347 426 
395 320 253 194 143 100 101 102 103 104 105 106 107 108 109 110 157 212 275 346 425 
396 321 254 195 144 145 146 147 148 149 150 151 152 153 154 155 156 211 274 345 424 
397 322 255 196 197 198 199 200 201 202 203 204 205 206 207 208 209 210 273 344 423 
398 323 256 257 258 259 260 261 262 263 264 265 266 267 268 269 270 271 272 343 422 
399 324 325 326 327 328 329 330 331 332 333 334 335 336 337 338 339 340 341 342 421 
400 401 402 403 404 405 406 407 408 409 410 411 412 413 414 415 416 417 418 419 420 
*/
