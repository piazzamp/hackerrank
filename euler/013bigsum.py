# Matt Piazza
# 25 FEB 2015
# solution to: https://www.hackerrank.com/contests/projecteuler/challenges/euler013

# C is not the language for this problem
n = eval(input())
tot = 0
for i in range(n):
   tot += eval(input())
   
print(str(tot)[:10])
