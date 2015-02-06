// Matt Piazza
// 4 FEB 2015
// solution to https://www.hackerrank.com/contests/projecteuler/challenges/euler008

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 0

// find max product of length consecutive digits
int findmax(char *in, int length){
   int max = -1, i = 0, j, prod = 1;
   if (DEBUG){
      printf("read in str: %s\n", in);
   }
   while (in[i + length] != NULL){ // i is starting char
      prod = 1;
      for (j = 0; j < length; j++){
         prod *= (in[j + i] - 48); // ascii 0 is has value 48
      }
      i++;
      if (prod > max){
         max = prod;
      }
   }
   return max;
}

int main() {
   int cases, c, numdig, k;
   scanf("%d\n", &cases);
   for (c = 0; c < cases; c++){
      scanf("%d %d\n", &numdig, &k);
      char *snum[numdig + 1];
      scanf("%s\n", &snum);
      printf("%d\n", findmax(snum, k));
   }
   
   return 0;
}
