import math

def nCr( M,N,D):
    top = math.factorial(M)
    down = math.factorial(N)*math.factorial(M-N)
    ans = top//down
    #while ans%D==0:  
    #    ans/=D

    return int(ans%D)

num = input()
M,N,D = [int(x) for x in num.split()]
print(nCr(M,N,D))


