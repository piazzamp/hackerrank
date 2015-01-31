// Matt Piazza
// 31 JAN 2015
// solution to: https://www.hackerrank.com/contests/101hack21/challenges/angry-professor

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 0

int main() {
   int c, s, cases, students, min, present = 0, time;
   scanf("%d\n", &cases);
   if (DEBUG){
      printf("picked up %d cases\n", cases);
   }
   for (c = 0; c < cases; c++){
      present = 0;
      scanf("%d %d", &students, &min);
      if (DEBUG){
         printf("students: %d, minimum attendance: %d\n", students, min);
      }
      //next line has <students> ints
      // this is a O(N) way to do it, but you could put all the times
      // in an array, qsort it, find the first num > 0 and determine
      // how many kids showed up before then
      for (s = 0; s < students; s++){
         scanf("%d ", &time);
         if(time <= 0){
            present++;
         }
      }
      if (DEBUG){
         printf("%d students present of %d required\n", present, min);
      }
      if (present >= min){
        printf("NO\n");
     }
     else{
        printf("YES\n");
     }
   }
   return 0;
}
