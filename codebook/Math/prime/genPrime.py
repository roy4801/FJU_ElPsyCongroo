import math
n = 10000
for i in range(1, n+1):
    pt = True
    for a in range(2, (int)(math.sqrt(n))+1):
        if i % a == 0:
            pt = False
    if pt:
        print(i, end=',')