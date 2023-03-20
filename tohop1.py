def try_func(i, j):
    global n, k, a
    for t in range(j, n+1):
        a[i] = t
        if i == k - 1:
            print(" ".join(str(x) for x in a))
        else:
            try_func(i + 1, t + 1)

if __name__ == '__main__':
    n, k = map(int, input().split())
    a = [0] * k
    try_func(0, 1)