// Matt Piazza
// 6 FEB 2015
// solution to: https://www.hackerrank.com/challenges/manasa-and-stones

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 1

void solve(int stones, int a, int b){
   int temp, min, max, step, i;
   if (a == b){
      printf("%d\n", (stones - 1)*a);
   }
   // make a <= b
   else {
      if (a > b){
         temp = a;
         a = b;
         b = temp;
      }
      min = (stones - 1) * a;
      max = (stones - 1) * b;
      step = b - a;
      // finally figured out some magic math to avoid doing this
      // the long way!
      for (i = min; i <= max; i += step){
         printf("%d ", i); // doesn't really need to be flushed to the screen until the whole test is over
      }
      printf("\n");
   }
}

int main() {
   int cases, c, a, b, stones;
   scanf("%d\n", &cases);
   for (c = 0; c < cases; c++){
      scanf("%d\n%d\n%d\n", &stones, &a, &b);
      solve(stones, a, b);
   }
   return 0;
}
