// Matt Piazza
// 4 MAR 2015
// solution to: https://www.hackerrank.com/contests/101hack22/challenges/marble-cut

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long good(long long l, long long b){
   // area is all that matters since the planks
   // can lay vertically or horizontally
	return ((l % 3) * (b % 3)) % 3;
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
