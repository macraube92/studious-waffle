N = int(input())
n = ((8*N+1)**0.5 - 1) // 2
s = n * (n + 1) // 2

if N - s > 0:
    n += 1
    c = N - s
else:
    c = n

a = c
b = n - c + 1
print("%d/%d"%((b, a) if n%2 else (a, b)))