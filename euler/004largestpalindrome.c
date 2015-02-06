// Matt Piazza
// 3 FEB 2015
// solution to: https://www.hackerrank.com/contests/projecteuler/challenges/euler004

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 0

// write into a string of chars and return length of num
// alert: string will be backwards (obv doesn't matter for this palindrome problem)
int numtostr(char *out, int num){
   int i, x;
   for (i = 0; num != 0; i++){
      // grab lsd
      x = num % 10;
      // remove lsd from num
      if (num >= 10){
         num = (int) num / 10;
      } 
      else{
         // at the end of the num, set finish flag
         num = 0;
      }
      // put the ascii version of x in the char array
      // ascii 0 = 48
      if (x >= 0 && x <= 9){
         out[i] = x + 48;
      }
   }
   // don't forget to end your string
   out[i] = NULL;
   return i;
}

int is_pal(char *str, int length){
   // should I do it recursively?
   int i, good = 1;
   for (i = 0; good && i < (length/2); i++){
      if (DEBUG){
         //printf("comparing %c and %c\n", str[i], str[length - i - 1]);
      }
      if(str[i] != str[length - i - 1]){
         good = 0;
         
      }
   }
   return good;
}

// determine if the number is the product of two 3-digit nums
// couldn't find a more clever way to do this; could iterate ~800,000 times
int prodof3(int num){
   int i, j;
   for (i = 999; i >= 100; i--){
      for (j = 999; j >= 100; j--){
         if ((j * i) == num){
            return 1;
         }
      }
   }
   return 0; // ?
}

int main() {
   int cases, c, numdig, limit, i, done;
   char ascii[6];
   scanf("%d\n", &cases);
   
   for (c = 0; c < cases; c++){
      done = 0;
      scanf("%d\n", &limit);
      for (i = limit; i >= 100000 && !done; i-- ){
         numdig = numtostr(ascii, i);
         if (is_pal(ascii, numdig) && prodof3(i)){
            printf("%s\n", ascii);
            done = 1;
         }
      }
   }
   return 0;
}
