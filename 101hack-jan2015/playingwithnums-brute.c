// Matt Piazza
// 31 JAN 2015
// solution to: https://www.hackerrank.com/contests/101hack21/challenges/playing-with-numbers
// but it doesn't use the proper mathematical tricks
// so it timed with large input arrays

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 0

// find the sum of the abs() of the array items using ...
// brute force, not math magic
long absarraytot(long *ray, int length){
   int i;
   long total = 0;
   for (i = 0; i < length; i++){
      total += labs(ray[i]);
      if (DEBUG){
         printf("%ld, ", ray[i]);
      }
   }
   if (DEBUG){
      printf("\n");
   }
   return total;
}

void addtoarray(long *ray, int length, int num){
   int i;
   for (i = 0; i < length; i++){
      ray[i] += num;
   }
}

int main() {
   int arraysize, numqueries, query, i, currentnum;
   long total;
   scanf("%d\n", &arraysize);
   long ray[arraysize];
   for (i = 0; i < arraysize; i++){
      scanf("%d ", &currentnum);
      ray[i] = currentnum;
      total += currentnum;
   }
   if (DEBUG){
      printf("inital total: %ld\n", absarraytot(ray, arraysize));
   }
   scanf("%d\n", &numqueries);
   for (i = 0; i < numqueries; i++){
      scanf("%d ", &query);
      // apply the query to all array elements and add to total
      if (query == 0){
         printf("%ld\n", total);
      }
      else {
         addtoarray(ray, arraysize, query);
         total = absarraytot(ray, arraysize);
         printf("%ld\n", total);
      }
   }
   return 0;
}
