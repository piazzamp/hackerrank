# Matt Piazza
# 27 FEB 2015
# solution to: https://www.hackerrank.com/contests/zenhacks/challenges/funny-string

cases = eval(input())
for _ in range(cases):
   s = input()
   r = s[::-1]
   funny = False
   for i in range(len(s) - 1):
      # print("{} - {} = {} =?= {} = {} - {}".format(s[i+1], s[i], abs(ord(s[i + 1]) - ord(s[i])), abs(ord(r[i + 1]) - ord(r[i])),r[i+1], r[i]))
      if abs(ord(s[i + 1]) - ord(s[i])) == abs(ord(r[i + 1]) - ord(r[i])):
         funny = True
      else:
         funny = False
         break
      # ugh, should probably use a while loop
   if funny:
      print("Funny")
   else:
      print("Not Funny")
