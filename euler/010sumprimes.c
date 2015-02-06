// Matt Piazza
// 5 FEB 2015
// solution to: https://www.hackerrank.com/contests/projecteuler/challenges/euler010

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 0
#define ARRAY_SIZE 100000

// getprime() and isprime() taken from nthprime.c
// getprime() modified to use indices instead of counting numbers

long primes[ARRAY_SIZE];
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

long sumprimes(int limit){
   int i = 0;
   long sum = 0;
   while (i < ARRAY_SIZE){
      if (primes[i] <= limit){
         sum += primes[i];
      }
      else{ // then primes[i] > limit
         return sum;
      }
      
      if (primes[i + 1] == 0){
         primes[i + 1] = getprime(i + 1);
      }
      i++;
   }
   return sum;
}

int main() {
   int cases, c, limit, i;
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
      scanf("%d\n", &limit);
      printf("%ld\n", sumprimes(limit));
   }
   if (DEBUG){
      for (i = 0; primes[i] > 0; i++){
         printf("%ld, ", primes[i]);
      }
      printf("\n");
   }
   return 0;
}
