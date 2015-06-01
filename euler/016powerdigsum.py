# Matt Piazza
# 30 MAY 2015
# solution to: https://www.hackerrank.com/contests/projecteuler/challenges/euler016

# Python is a dreamland where no one questions 100-bit integers 

def sumdig(number):
    total = 0
    while (number >= 10):
        dig = number % 10
        total += dig
        number //= 10
    ## we know at this point in < 10 && its value has not been counted yet
    total += number
    return total

def main():
    cases = eval(input())
    for i in range(cases):
        power = eval(input())
        num = 2 ** power
        print(sumdig(num))
        
main()
