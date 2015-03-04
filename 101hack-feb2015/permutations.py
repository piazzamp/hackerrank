# Matt Piazza
# 4 MAR 2015
# solution to: https://www.hackerrank.com/contests/101hack22/challenges/permutation-of-natural-numbers
# but I ran out of time before I could figure this one out

import itertools

def satisfactory(letters, numbers):
   for x in range(len(letters) - 1):
      if [letters[numbers[x]]] == 'I' and numbers[x] > numbers[x + 1]:
         continue
      elif [letters[numbers[x]]] == 'D' and numbers[x] < numbers[x + 1]:
         continue
      else:
         return False
   return True

def getperms(letters):
   return list(itertools.permutations(letters))

def main():
   letters = input().split(' ')
   # make dictionary
   d_letters = dict()
   for x in range(len(letters)):
      d_letters[letters[x]] = x + 1
   mxs = ' '
   mxd = dict()
   for p in getperms(letters):
      s = ''.join(p.keys())
      if satisfactory(list(p.keys()), list(p.values())) and s > mxs:
         mxs = s
         mxd = p
   answer = ''
   for v in mxd.values():
      answer += ' ' + str(v)
   print(answer)
main()
