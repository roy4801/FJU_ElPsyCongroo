FAC = list()
MAXN = 100

OUTFILE = open("output.out","w")

# n!
def build_fac():
    global FAC
    FAC.append(1) # FAC[0] = 1
    for i in range(1,MAXN+5):
        FAC.append(FAC[i-1]*i)
    for i in range(1,MAXN):
        print(FAC[i],end=" ",file=OUTFILE)
        if i%10 == 0:
            print("",file=OUTFILE)

# !n
# !2 : (2,1)
# !3 : (3,1,2),(2,3,1)
# !4 : (2,1,4,3),(2,3,4,1),(2,4,1,3),(3,1,4,2),(3,4,1,2),
#      (3,4,2,1),(4,1,2,3),(4,2,1,2),(4,3,2,1)
SUBFAC = list()
def build_subfac() :
    global SUBFAC
    SUBFAC.append(1) # SUBFAC[0] = 1
    SUBFAC.append(0) # SUBFAC[1] = 0
    for i in range(2,MAXN+5):
        SUBFAC.append(0)
        for j in range(0,i+1):
            tmp = 1
            for k in range(i,j,-1):
                tmp *= k
            if j&1 :
                SUBFAC[i] -= tmp
            else :
                SUBFAC[i] += tmp

    for i in range(1,MAXN):
        print(SUBFAC[i],end=" ",file=OUTFILE)
        if i%10 == 0:
            print("",file=OUTFILE)

build_fac()
print("",file=OUTFILE)
print("",file=OUTFILE)
build_subfac()