n = int(input())

a = [0] * n

check = [False] * (n+1)

def solve(i):
    if i == n:
        print(*a)
        return
        
    for j in range(n, 0, -1):
        if not check[j]:
            check[j] = True
            a[i] = j
            solve(i + 1)
            check[j] = False

solve(0)