// Matt Piazza
// 6 FEB 2015
// solution to: https://www.hackerrank.com/challenges/maxsubarray

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 0


// linear-time algo as explined by Ben Wright on youtube
long maxcontig(int *ray, int length){
   int i, j;
   long maxsum = -2147483645, max = -2147483645, sum = 0, tempsum;
   for (i = 0; i < length; i++){
      tempsum = sum + ray[i];
      if (tempsum > 0){
         //if (sum == 0){}
         sum = tempsum;
      }
      else{
         sum = 0;
      }
      if (sum > maxsum){
         maxsum = sum;
      }
      if (ray[i] > max){
         max = ray[i];
      }
   }
   if (maxsum !=0){
      return maxsum;
   }
   else{
      return max;
   }
}

// taken from angrychildren.c
int greaterthan(const void * p1, const void * p2){
	// requisite comparison function for qsort
	// take in two untyped pointers and return
	// a real number whose sign determined sort order
	// when p1 < p2, lessthan will return a negative number!
   return *(int*)p2 - *(int*)p1;
	// must typecast and dereference, need more stars
	}


long maxnoncontig(int *ray, int length){
   int o;
   qsort(ray, length, sizeof(int), greaterthan);
   if (DEBUG){
      for (o = 0; o < length; o++){
         printf("%d, ", ray[o]);
      }
      printf("\n");
   }
   
   // now the array is sorted max --> min
   if (ray[0] <= 0){
      return ray[0]; // if the max array item is negative, then it alone is the max
   }
   int i = 0;
   long total = 0;
   while (ray[i] > 0 && i < length){
      total += ray[i];
      if (DEBUG){
           printf("adding %d to the total\n", ray[i]);
      }
      i++;
   }
   return total;
}



int main() {
   int cases, c, len, i;
   long contig, noncontig;
   scanf("%d\n", &cases);
   for (c = 0; c < cases; c++){
      scanf("%d\n", &len);
      int ray[len];
      for (i = 0; i < len; i++){
         scanf("%d ", &(ray[i]));
      }
      contig = maxcontig(ray, len);
      noncontig = maxnoncontig(ray, len);
      printf("%ld %ld\n", contig, noncontig);
   }
   return 0;
}
