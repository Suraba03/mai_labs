from math import gcd
 
numbers = list()
f = open('nums.txt', 'r')

for l in f.readls():
    numbers.append(int(l))

k = 0
for n1 in numbers:
    for n2 in numbers:
        gcd_ = gcd(n1, n2)
        k += 1
        if gcd_ != 1 and n1 // gcd_ != 1:
            print(n1,' = ',gcd_,' * ',n1 // gcd_)
            break