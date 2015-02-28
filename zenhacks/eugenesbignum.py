# Matt Piazza
# 28 FEB 2015
# memory-inefficient solution to: https://www.hackerrank.com/contests/zenhacks/challenges/eugene-and-big-number


# perfect problem for python's string operations, right??
def main():
   cases = eval(input())
   for _ in range(cases):
      line = input().split(' ')
      a, n, m = line[0], line[1], line[2] # I bet there's a way more 'pythonic', crafty way to do this
      # they are strings for now, good
      x = a * (eval(n) % eval(m))
      print(str(eval(x) % eval(m)))
      
main()
