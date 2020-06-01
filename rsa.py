#PB1 | ABHISHEK WAHANE | B1 BATCH

#RSA Algorithm | LAB B1 

from decimal import Decimal

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

print("Enter 2 Numbers:")
a = int(input())
b = int(input())
n = a * b
encr = 3       
p = (a - 1) * (b - 1)
k = 2

en = int(input("Enter data: "))

for encr in range(2, p ):
    if gcd(encr,p) == 1:
        break

for i in range(1,10):
    x = 1 + i*p
    if x % encr == 0:
        d = int(x/encr)
        break
ctt = Decimal(0)
ctt =pow(en,encr)
ct = ctt % n

dtt = Decimal(0)
dtt = pow(ct,d)
dt = dtt % n

print('Decrypted Key:',dt)