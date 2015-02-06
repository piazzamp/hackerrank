// Matt Piazza
// 30 JAN 2015
// solution to: https://www.hackerrank.com/contests/projecteuler/challenges/euler002

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 0
#define ARRAYSIZE 300

int main() {
    int cases, i, j;
    unsigned long total = 0, limit; // since N is guaranteed to be >= 10
    unsigned long fib[ARRAYSIZE];
    
    //initialize array
    fib[0] = 1;
    fib[1] = 2;
    for (i = 2; i < ARRAYSIZE; i++){
        fib[i] = 0;
    }
    
    scanf("%d\n", &cases);
    if (DEBUG){
        printf("reading %d cases\n", cases);
    }
    
    for (i = 0; i < cases; i++){
        total = 0;
        scanf("%lu\n", &limit);
        if (DEBUG){
            printf("limit is %lu\ntotal is %lu\n", limit, total);
        }
        
        for (j = 1; fib[j - 1] <= limit && j < ARRAYSIZE; j++){
            //calculate fib up to that point
            if (fib[j] == 0){ // uncalculated value
                fib[j] = fib[j - 1] + fib[j - 2];
                if (DEBUG){
                    printf("calculated fib up to %d --> %lu\n", j, fib[j]);
                }
            }
            
            // add to the total iff it's even and in range
            if (fib[j] % 2 == 0 && fib[j] <= limit){
                if (DEBUG){
                    printf("got even value %lu at index %d\n", fib[j], j);
                }
                total += fib[j];
            }
        }
        printf("%ld\n", total);
    }
    return 0;
}
