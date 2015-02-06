// Matt Piazza
// 30 JAN 2015
// solution to: https://www.hackerrank.com/contests/projecteuler/challenges/euler001

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// math says: sum of multiples of k below limit = k*n*(n+1)/2
// where n = floor((limit - 1)/k)
unsigned long sum(int step, unsigned long limit){
    limit = floor((limit - 1) / step); // hmm, doesn't floor return a double :/
    return step * limit * (limit + 1) / 2;
}

int main() {
    int count, i;
    scanf("%d\n", &count);
    for (i = 0; i < count; i++){
        unsigned long limit; // guaranteed to be < 10^9
        unsigned long total;
        scanf("%ld\n", &limit);
        //sum[3] + sum[5] - sum[15] -- help from project euler's wikipedia page
        total = sum(3, limit) + sum(5, limit) - sum(15, limit);
        printf("%lu\n", total);
    }
    return 0;
}

