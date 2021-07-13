T = int(input())
for i in range(T):
    g, c = map(int, input().split())
    result = (c**2) // (2*g)
    print(result)
