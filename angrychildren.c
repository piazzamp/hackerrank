// Matt Piazza
// 29 JAN 2015
// solution to: https://www.hackerrank.com/challenges/angry-children

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000
#define MAX_VAL 1000000001

#define DEBUG 0

int candies[MAX];

void replacewithnone(int *ray, int rep){
  int i;
  for (i = 0; i < MAX && ray[i] != NULL; i++){
    if (ray[i] == rep){
      if (DEBUG){
        printf("replacing %d with -1\n", rep);
      }
      ray[i] = -1;
      break;
    }
  }
}

int min(int *uray){
  int min = MAX_VAL, i;
  for (i = 0; i < MAX && uray[i] != NULL; i++){
    if (DEBUG) {
      printf("%d, ", uray[i]);
    }
    if (uray[i] < min && uray[i] >= 0){
      min = uray[i];
    }
  }
  if (DEBUG) {
    printf("\nmin is %d\n", min);
  }
  return min;
}

int* linearsort(int *ray){
  int i;
  int *sorted = malloc(sizeof(int)*MAX);
  for (i = 0; i < MAX && ray[i] != NULL; i++){
    int lowest = min(ray);
    sorted[i] = lowest; // put the smallest remaining item in leftmost sorted slot
    replacewithnone(ray, lowest);
  }
  return sorted;
}
int lessthan(const void * p1, const void * p2){
	// requisite comparison function for qsort
	// take in two untyped pointers and return
	// a real number whose sign determined sort order
	// when p1 < p2, lessthan will return a negative number!
   return *(int*)p1 - *(int*)p2;
	// must typecast and dereference, need more stars
	}

int* calunf(int *ray, int length){
  int i, min = MAX_VAL;
  length = length - 1; //to choose the right item in the array
  for (i = 0; i < MAX && ray[length + i] != NULL; i++){
    // step through the sorted array in `length` chunks
    int current = ray[i + length] - ray[i];
    // compare items: ---[i]--------[i + length]---
    if (current < min){
      min = current;
    } 
    if (DEBUG){
      printf("comparing %d & %d: %d. min: %d\n", ray[i], ray[i+length], current, min);
    }
  }
  return min;
}
 
int main() {
    
    int N,K;
    int i;
    
    scanf("%d %d",&N,&K);
    //printf("n: %d\nk: %d\n", N, K);
    for(i = 0;i < N;i++)
        scanf("%d",candies + i); //candies is a pointer to item 0 in array, i sticks them in their spots
    
    // int *sortedcan = linearsort(candies);
	qsort(candies, N, sizeof(int), lessthan); // in-place quicksort from stdlib
    int unfairness = calunf(candies, K);
    /*int p;
    for (p=0; p < MAX && sortedcan[p] != NULL; p++){
      printf("%d, ", sortedcan[p]);
    }*/
  
    printf("%d\n",unfairness);
    return 0;
}

