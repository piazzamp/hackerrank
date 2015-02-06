// Matt Piazza
// 4 FEB 2015
// solution to: https://www.hackerrank.com/contests/projecteuler/challenges/euler006

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 1

// handles 1*1 + 2*2 + ... + n*n
long sumofsquares(int n){
   // apparently there's some mathematical trickery 
   // out there that can solve this
   long sum = 0;
   long i;
   for (i = 1; i <= n; i++){
      sum += (i * i);
   }
   return sum;
}

// handles (1 + 2 + ... + n)^2
long squareofsum(int n){
   long i, sum = 0;
   for (i = 1; i <= n; i++){
      sum += i;
   }
   return sum * sum;
}

int main() {
   int cases, c, n, solution;
   scanf("%d\n", &cases);
   for (c = 0; c < cases; c++){
      scanf("%d\n", &n);
      printf("%ld\n", (squareofsum(n) - sumofsquares(n)));
   }
   return 0;
}
