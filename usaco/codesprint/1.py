t=int(raw_input())
for x in range(0,t):
    n=int(raw_input())
    a=0
    for y in range(0,n):
        m=1
        if(y%2==1):
            m=-1
        print(float(1/(2*y+1)))
        a+=(m*(1/(2*y+1)))
    print(a)

