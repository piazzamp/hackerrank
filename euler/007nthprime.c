// Matt Piazza
// 4 FEB 2015
// solution to: https://www.hackerrank.com/contests/projecteuler/challenges/euler007

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 0
#define ARRAY_SIZE 10000

long primes[ARRAY_SIZE];
long max; // biggest prime found
int index;

// iterate through previously found primes
// to determine if num is prime
int isprime(long num){
   int i = 0;
   while (primes[i] != 0){
      if (num % primes[i] == 0){
         // num is not prime
         return 0;
      }
      i++;
   }
   if (DEBUG){
      fprintf(stderr, "%ld is prime!\n", num);
   }
   return 1;
}

// find the nth prime
long getprime(int n){
   int i;
   if (primes[n - 1] != 0){
      return primes[n - 1];
   }
   for (i = max + 1; index < n; i++){
      if (DEBUG){
         fprintf(stderr, "index < n: %d < %d?\n", index, n);
         fprintf(stderr,"isprime(%d)\n", i);
      }
      if (isprime(i)){
         primes[++index] = i;
         max = i;
      }
   }
   return primes[n - 1];
}

int main() {
   int cases, c, n, i;
   // initialize array
   for (i = 0; i < ARRAY_SIZE; i++){
      primes[i] = 0;
   } // prime array
   primes[0] = 2;
   primes[1] = 3;
   max = primes[1];
   index = 1;
   
   scanf("%d\n", &cases);
   for (c = 0; c < cases; c++){
      scanf("%d\n", &n);
      if (DEBUG){
         fprintf(stderr, "examining %d\n", n);
      }
      printf("%ld\n", getprime(n));
   }
   return 0;
}
