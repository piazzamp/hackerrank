// Matt Piazza
// 30 JAN 2015
// solution to: https://www.hackerrank.com/contests/projecteuler/challenges/euler059

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DEBUG 0

int inrange(char c){
    // can use a regexp for this?
    // took a while to realize that 'a' <= c <= 'z' neither throws a warning nor works
    if ('a' <= c && c <= 'z'){ 
        if (DEBUG){
            printf("(inrange()) --> \'a\' <= %c <= \'z\'\n", c);
        }
        return 1;
    }
    else if ('A' <= c && c <= 'Z'){
        if (DEBUG){
            printf("(inrange()) --> \'A\' <= %c <= \'Z\'\n", c);
        }
        return 1;
    }
    else if ('0' <= c && c <= '9'){
        if (DEBUG){
            printf("(inrange()) --> \'0\' <= %c <= \'9\'\n", c);
        }
        return 1;
    }
    else if (c == ' ' ||
        c == '(' ||
        c == ')' ||
        c == ':' ||
        c == ';' ||
        c == ',' ||
        c == '.' ||
        c == '!' ||
        c == '\'' ||
        c == '-' ||
        c == '?'){
            if (DEBUG){
                printf("(inrange()) --> %c accepted as special character\n", c);
            }
            return 1;
    }
    else {
        if (DEBUG){
            printf("(inrange()) --> char out of range!\n");
        }
        return 0;
    }
}

//test the key, return 1 if all 'decrypted' chars are valid
int testkey(char *instr, int length, char *key){
    int i;
    char test;
    
    if (DEBUG){
        printf("(testkey()) --> key: %c%c%c\n", key[0], key[1], key[2]);
    }
    // go through instr char by char to check xor'd value in range
    for (i = 0; i < length; i++){
        test = instr[i] ^ key[i % 3];
        if (DEBUG){
            printf("(testkey()) --> going through input at char: %d\n", i);
            //printf("decrypted char = %c\n", test);
        }
        if (!inrange(test)){
            if (DEBUG){
                printf("(testkey()) --> char out of range\n");
            }
            return 0;
            //if we see an invalid char then the key is bad and continue looping
        }
    }
    return 1;
    // if it didn't return by now then the key is valid
}

int main() {
    //char *possible_keys[26*26*26];
    // ascii values 97-122 (inclusive)
    char i, j, k, solved; 
    int length, iter;
    char key[3];
    
    scanf("%d\n", &length);
    if (DEBUG){
        printf("length: %d\n", length);
    }
    
    char *input = malloc(sizeof(char)*length);
    for (iter = 0; iter < length; iter++){
        scanf("%d ", &(input[iter]));
        if (DEBUG){
            // printf("grabbed %c\n", input[iter]);
        }
    }
    if (DEBUG){
        printf("out of input loop.\n");
    }
    for (i = 'a'; i <= 'z'; i++){
        for (j = 'a'; j <= 'z'; j++){
            for (k = 'a'; k <= 'z'; k++){
                char key[3] = {i, j, k};
                if (DEBUG){
                    printf("testing key : %c%c%c\n", key[0], key[1], key[2]);
                }
                solved = testkey(input, length, key);
                if (solved){
                    printf("%c%c%c\n", key[0], key[1], key[2]);
                    return 0;
                } else if (DEBUG){
                    printf("(main) --> key %c%c%c failed, iterating\n", key[0], key[1], key[2]);
                }
            }
        }
        
    }
    
    return 0;
}
