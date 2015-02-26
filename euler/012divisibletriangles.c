#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 0

#define ARRAY_SIZE 1000
#define T_ARRAY 100000

// getprime() and isprime() taken from nthprime.c
// getprime() modified to use indices instead of counting numbers

long primes[ARRAY_SIZE], triangles[T_ARRAY];
int factors[T_ARRAY];
long max; // biggest prime found
int index;

// iterate through previously found primes
// to determine if num is prime
int isprime(long num){
   double root = sqrt(num);
   int i = 0;
   while (primes[i] != 0 && primes[i] <= root){
      if (num % primes[i] == 0){
         // num is not prime
         return 0;
      }
      i++;
   }
   if (DEBUG){
     // fprintf(stderr, "%ld is prime!\n", num);
   }
   return 1;
}

// find the nth prime
long getprime(int n){
   int i;
   if (primes[n] != 0){
      return primes[n];
   }
   for (i = max + 2; index < n; i += 2){
      if (DEBUG){
         fprintf(stderr, "index < n: %d < %d?\n", index, n);
         fprintf(stderr,"isprime(%d)\n", i);
      }
      if (isprime(i)){
         primes[++index] = i;
         max = i;
      }
   }
   if (DEBUG){
      //printf("getprime(%d): %ld\n", n, primes[n]);
   }
   return primes[n];
}

int numdivisors(int num){
   if (num == 1){ return 1; }
   else if (isprime(num)){ return 2; }
   
   int exponents[ARRAY_SIZE], i;
   for (i = 0; i < ARRAY_SIZE; i++){
      exponents[i] = 0;
   }
   int divs = 1, remainder = num;
   double root = sqrt(num);
   i = 0;
   while (!isprime(remainder)){ // or while (!isprime(remainder))??
      if (remainder % primes[i] == 0){
         remainder = remainder / primes[i];
         // inc exponent at i by one
         exponents[i]++;
         i = 0; // restart division on the remainder
      }
      else{    // otherwise, try to divide by the next prime
         i++;
      }
      if (primes[i + 1] == 0){
         primes[i + 1] = getprime(i + 1);
      }
   }
   // find where remainder is and increment its exponent
   if (DEBUG){ printf("final remainder: %d\n", remainder); }
   for (i = 0; i < ARRAY_SIZE; i++){
      if (primes[i] == remainder){
         if (DEBUG) { fprintf(stderr, "incrementing %ld's exponent from %d to ", primes[i], exponents[i]); }
         exponents[i] += 1;
         if (DEBUG){ fprintf(stderr, "%d\n", exponents[i]); }
      }
      if (primes[i + 1] == 0){
         primes[i + 1] = getprime(i + 1);
      }
   }
   
   // now add up all the exponents
   if (DEBUG){ fprintf(stderr, "prime factors of %d: ", num); }
   for (i = 0; i < ARRAY_SIZE; i++){
      if (exponents[i] != 0){
         if (DEBUG){ printf("%ld^%d ", primes[i], exponents[i]); }
         divs *= (exponents[i] + 1);
      }
   }
   
   if (DEBUG){
      fprintf(stderr, "\n%d has %d divisors\n", num, divs);
   }
   return divs;
}

int testtriangles(int divs){
   int step = 1, total = 1;
   int i = 0;
   while (factors[i] <= divs){
      if (factors[i + 1] == 0){
         step = triangles[i] - triangles[i - 1] + 1;
         triangles[i + 1] = triangles[i] + step;
         factors[i + 1] = numdivisors(triangles[i + 1]);
         // if (DEBUGS){ printf("set factors of %d to %d\n", triangles[i + 1], factors[i + 1]); }
      }
      i++;
   }
   return triangles[i];
}

int main() {
   int cases, c, limit, i;
   // batten down the caches
   for (i = 0; i < ARRAY_SIZE; i++){
      primes[i] = 0;
   }
   for (i = 0; i < T_ARRAY; i++){
      triangles[i] = 0;
      factors[i] = 0;
   }
   triangles[0] = 1;
   triangles[1] = 3;
   factors[0] = 1;
   primes[0] = 2;
   primes[1] = 3;
   max = primes[1];
   index = 1;
   scanf("%d\n", &cases);
   for (c = 0; c < cases; c++){
      scanf("%d\n", &limit);
      // find the first triangle
      printf("%d\n", testtriangles(limit));
   }
   return 0;
}
