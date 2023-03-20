# x+(x^2)/2!+(x^3)/3!+(x^4)/4!+...+(x^n)/n!
import math


def sum(x, n):
    if n == 1:
        return x
    return (math.pow(x, n) / math.factorial(n)) + sum(x, n-1)


if __name__ == "__main__":
    t = int(input())
    i = 0
    arr = []
    while(1):
        x, n = input().split()
        arr.append(sum(float(x), int(n)))
        if i == t-1:
            break
        i += 1
    i = 0
    while(1):
        print('%.8f' % round(arr[i], 8))
        if i == t-1:
            break
        i += 1
