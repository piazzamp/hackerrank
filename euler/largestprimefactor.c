// Matt Piazza
// 2 FEB 2015
// solution to: https://www.hackerrank.com/contests/projecteuler/challenges/euler003

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 0

// canonical, speedy implementation thanks to wikipedia
int is_prime(long num){
   long try;
   if (DEBUG){
      printf("(is_prime)--> long:%ld  double:%.2f\n", num, ((double) num));
   }
   double root = sqrt((double) num);
    // factors can only be as large as sqrt(num), right?
    if (num <= 3){
        return num > 1;
        //1 is not prime
    }
    // eliminate 5/6 iterations, sieve of eratosthenes style
    else if (num % 2 == 0 || num % 3 == 0){
        return 0;
    }
    else {
        for(try = 5; try <= root; try += 6){
            if (num % try == 0 || num % (try + 2) == 0){
                // then try divides num and it's _not_ prime:
                return 0;
            }
        }
        return 1;
    }
}

int main() {
   int cases, c, isfactor;
   long remainder, factor = 2, max, stop;
   scanf("%d\n", &cases);
   if (DEBUG){
      printf("got %d cases\n", cases);
   }
   for (c = 0; c < cases; c++){
      max = -1;
      scanf("%ld\n", &remainder);
      if (DEBUG){
         printf("got case: %ld\n", remainder);
      }
      
      // now find remainder's greatest factor
      stop = remainder / 2;

      while (remainder > 1){ // stop when remainder / factor = 1
         if (is_prime(remainder)){
            max = remainder;
            remainder = 1;
         }
         else {
            isfactor = 0;
            for (factor = 2; factor <= stop && !isfactor; ){
               if (DEBUG){
                  printf("%ld divides %ld?\n", factor, remainder);
               }
               // upon finding a prime factor restart the while loop with remainder / factor
               if (remainder % factor == 0 && is_prime(factor)){
                  isfactor = 1;
                  if (factor > max){
                     max = factor;
                  }
                  if (DEBUG){
                     printf("%ld is a prime factor of %ld\n", factor, remainder);
                  }
               }
               else{
                  factor++;
               }
            }
            if (DEBUG){
               printf("remainder / factor = %ld / %ld = %ld\n", remainder, factor, remainder / factor);
            }
            remainder = remainder / factor;
         }
      }
   printf("%ld\n", max);
   }
   return 0;
}
