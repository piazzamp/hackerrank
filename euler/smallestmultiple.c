// Matt Piazza
// 4 FEB 2015
// solution to: https://www.hackerrank.com/contests/projecteuler/challenges/euler005

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 0

int gcd(int a, int b){
   // euclid, et al
   // done recursively, could also do while(a > 0)
   // ensure a < b
   int temp, rem;
   if (a > b){
      temp = a;
      a = b;
      b = temp;
   }
   rem = b % a;
   if (rem == 0){
      if (DEBUG){
         printf("----\n");
      }
      return a;
   }
   else{
      if (DEBUG){
         printf("recurring with (%d, %d)\n", a, rem);
      }
      return gcd(a, rem);
   }
}

int lcm(int a, int b){
   // product divided by their greatest common divisor! neat-o
   return (a * b) / gcd(a, b);
}

int solve(int limit){
   // iterate through 1..limit testing if they divide the sum
   int i, prod = limit;
   for (i = 2; i <= limit; i++){
      if (prod % i != 0){
         if (DEBUG){
            printf("calling lcm(%d, %d): ", i, prod);
         }
         prod = lcm(i, prod);
         if (DEBUG){
            printf("%d\n", prod);
         }
      }
   }
   return prod;
}

int main() {
   if (DEBUG){
      printf("gcd(200,125): %d\n", gcd(200,125));
   }
   int cases, c, n;
   scanf("%d\n", &cases);
   for (c = 0; c < cases; c++){
      scanf("%d\n", &n);
      printf("%d\n", solve(n));
   }
   return 0;
}
