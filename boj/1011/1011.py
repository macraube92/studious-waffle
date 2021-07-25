T = int(input())

for t in range(T):
    x, y = map(int, input().split())
    D = y - x
    n = int(D**0.5)
    a = D - n**2
    k = 2 * n - 1
    while a > n:
        a -= n
        k += 1
    if a > 0:
        k += 1
    print(k)