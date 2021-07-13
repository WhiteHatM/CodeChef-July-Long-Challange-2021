T = int(input())
i= 0
while i <= T:
    i += 1
    if i > T:
        break
    d, x, y, z  = map(int, input().split())
    a = 7*x
    if y > x:
        if d < 7:
            b = d * y
            if z < x:
                c = z * (7-d)
                sum = b + c
    
    print(max(a,sum))
