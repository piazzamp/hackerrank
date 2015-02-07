// Matt Piazza
// 7 FEB 2015
// solution to: https://www.hackerrank.com/contests/projecteuler/challenges/euler011

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 0

// return product of diagonals if the given item is in the top left
// X ~ ~ ~ *
// ~ x ~ ~ *
// ~ ~ x ~ *
// ~ ~ ~ x
long topleft(int row, int col, int **grid){
   if (row > 16 || col > 16){
      // out of bounds
		if (DEBUG){
      	fprintf(stderr, "array index out of bounds: topleft(row:%d, col:%d)\n", row, col);
		}
      return 0;
   }
   return (long) (grid[row][col] * grid[row + 1][col + 1] * grid[row + 2][col + 2] * grid[row + 3][col + 3]);
}

// return product of diagonals if the given item is in the top right
// ~ ~ ~ X *
// ~ ~ x ~ *
// ~ x ~ ~ *
// x ~ ~ ~
long topright(int row, int col, int **grid){
   if (row > 16 || col < 3){
      if (DEBUG){
			fprintf(stderr, "array index out of bounds: topright(row:%d, col:%d)\n", row, col);
		}
      return 0;
   }
   return (long) grid[row][col] * grid[row + 1][col - 1] * grid[row + 2][col - 2] * grid[row + 3][col - 3];
}

// return product of vertically stacked elements
// ~ ~ X ~ *
// ~ ~ x ~ *
// ~ ~ x ~ *
// ~ ~ x ~
long down(int row, int col, int **grid){
   if (row > 16){
      if (DEBUG){
			fprintf(stderr, "array index out of bounds: down(row:%d, col:%d)\n", row, col);
		}
      return 0;
   }
   return (long) grid[row][col] * grid[row + 1][col] * grid[row + 2][col] * grid[row + 3][col];
}

// return product of horizontally stacked elements
// ~ ~ ~ ~ *
// X x x x *
// ~ ~ ~ ~ *
// ~ ~ ~ ~
long right(int row, int col, int **grid){
   if (col > 16){
      if (DEBUG){
			fprintf(stderr, "array index out of bounds: right(row:%d, col:%d)\n", row, col);
		}
      return 0;
   } 
   return (long) grid[row][col] * grid[row][col + 1] * grid[row][col + 2] * grid[row][col + 3];
}

int main() {
   int row, col, bestrow, bestcol, i;
   char method;
   long max = -1, r, d, tl, tr;
   int **grid = (int**) malloc(sizeof(int *) * 20); // grid has 20 pointers to int arrays
   for (i = 0; i < 20; i++){
      grid[i] = (int *) malloc(sizeof(int) * 20);
   }
   
   for (row = 0; row < 20; row++){
      for (col = 0; col < 20; col++){
         scanf("%d ", &(grid[row][col]));
      }
   }
   for (row = 0; row < 20; row++){
      for (col = 0; col < 20; col++){
         if (DEBUG){
            fprintf(stderr, "examining grid[%d][%d]: %d\n", row, col, grid[row][col]);
         } // WAHOO finally found the segfault where down() kicked out on row < 16 instead of row > 16
         if (grid[row][col] != 0){
            tr = topright(row, col, grid);
            tl = topleft(row, col, grid);
            d = down(row, col, grid);
            r = right(row, col, grid);
            if (tr > max){ max = tr; bestrow = row; bestcol = col; method = 'r'; }
            if (tl > max){ max = tl; bestrow = row; bestcol = col; method = 'l'; }
            if (d > max){ max = d; bestrow = row; bestcol = col; method = 'd'; }
            if (r > max){ max = r; bestrow = row; bestcol = col; method = 'g'; }
         }
      }
   }
   printf("%ld\n", max);
   if (DEBUG){
      printf("bestrow: %d, bestcol: %d by method %c\n", bestrow, bestcol, method);
   }
   return 0;
}
