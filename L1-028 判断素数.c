from math import sqrt
def isprime(n):
    if n<=1:
        return False
    else:
        for i in range(2,int(sqrt(n)+1)):
            if n%i == 0:
                return False
        return True
s = int(input())
for i in range(s):
    x = int(input())
    if isprime(x):
        print("Yes")
    else:
        print("No")
