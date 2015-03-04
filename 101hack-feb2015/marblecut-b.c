// Matt Piazza
// 4 MAR 2015
// solution to: https://www.hackerrank.com/contests/101hack22/challenges/marble-cut
// by my drawings this should work, but it scores significantly worse than
// my other solution which neglects 4-piece leftovers?

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long good(long long l, long long b){
   // think of 5x5, which will have remaining area: 4
   // in this case we see remianing area 2x2 = 4
   return (l % 3) * (b % 3);
}

int main() {
   int cases, c;
   long long l, b, answer;
   scanf("%d\n", &cases);
   for (c = 0; c < cases; c++){
      scanf("%lld %lld\n", &l, &b);
      answer = good(l, b);
      if (answer == 0){
         printf("YES\n");
      }
      else {
         printf("NO %lld\n", answer);
      }
   }
   return 0;
}
