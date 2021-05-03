N = int(input())


def find_square(n):
    while True:
        sqr = n ** 0.5
        if sqr % 1 == 0:
            return n
        n += 1


for i in range(N):
    m = input()
    l = len(m)
    sq = find_square(l)
    pad = sq - l
    m += "*" * pad

    l = len(m)
    out = ""
    for x in range(int(l**0.5), 0, -1):
        for z in range(int(l**0.5)):
            pos = int(-x - l**0.5 * z)
            if m[pos] != "*":
                out += m[pos]
    print(out)
