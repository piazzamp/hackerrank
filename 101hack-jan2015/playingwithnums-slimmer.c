// Matt Piazza
// 31 JAN 2015
// solution to: https://www.hackerrank.com/contests/101hack21/challenges/playing-with-numbers
// but it doesn't use the proper mathematical tricks
// so it timed out with large input arrays

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 0

// add num to each item in the array
// and return the sum of the absolute value of each array item
long query(long *ray, int length, int num){
   int i;
   long ptotal = 0, ntotal = 0;
   for (i = 0; i < length; i++){
      ray[i] += num;
      if (ray[i] >=0){
         ptotal += ray[i]; // after incrementing ray[i]
      }
      else{
         ntotal += ray[i];
      }
		if (DEBUG){
			printf("%ld, ", ray[i]);
		}
   }
   if (DEBUG){ printf("\n"); }
   //reduce number of calls to labs() to one
   return ptotal + labs(ntotal);
}

int main() {
   int arraysize, numqueries, q, i, currentnum;
   long total = 0;
   scanf("%d\n", &arraysize);
   long ray[arraysize];
   for (i = 0; i < arraysize; i++){
      scanf("%d ", &currentnum);
      ray[i] = currentnum;
      total += currentnum;
   }
   scanf("%d\n", &numqueries);
   for (i = 0; i < numqueries; i++){
      scanf("%d ", &q);
      // apply the query (q) to all array elements and add to total
      if (q == 0){
         printf("%ld\n", total);
      }
      else {
         total = query(ray, arraysize, q);
         printf("%ld\n", total);
      }
   }
   return 0;
}
