// Matt Piazza
// 27 FEB 2015
// solution to: https://www.hackerrank.com/contests/zenhacks/challenges/strange-grid

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long getvoffset(unsigned long row){
   row = row - 1;
   return (row - (row % 2)) * 5 + (row % 2);
   // case: r = 2 -> 1 - 1 * 5 + 1 = 1 offset on row 2
   // or r = 3 -> 2 - 0 * 5 + 0 = 10 offset on row 3
} 

int main() {
   // odd rows have even nums
   // offsets by 10 every two rows
   int c;
   unsigned long r, num = 0, voffset = 0;
   scanf("%ld %d\n", &r, &c);
   voffset = getvoffset(r);
   num = voffset + (c - 1) * 2;
   printf("%ld\n", num);
   return 0;
}
