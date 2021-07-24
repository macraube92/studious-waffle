from random import randrange

IS_RANDOM = False
N = 199999
M = 199999

if IS_RANDOM:
    def pick(i):
        return randrange(-1000000000, 1000000000);
else:
    def pick(i):
        return 200000-i;

with open("sample.txt", "w") as f:
    f.write("%d %d\n"%(N, M))

    for i in range(N):
        f.write("%d\n"%pick(i))

    for i in range(M):
        f.write("%d\n"%pick(i))