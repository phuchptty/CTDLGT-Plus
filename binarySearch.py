def binary_search(a, n, x):
    left = 0
    right = n - 1
    while left <= right:
        index = (left + right) // 2
        if x == a[index]:
            return index
        if x < a[index]:
            left = index + 1
        else:
            right = index - 1
    return -1

def sort_array(a, n):
    for i in range(n - 1):
        for j in range(n - 1, i, -1):
            if a[i] < a[j]:
                a[i], a[j] = a[j], a[i]

def main():
    n = int(input())
    a = list(map(int, input().split()))
    sort_array(a, n)
    for i in range(n):
        print(a[i], end=' ')
    print()
    t = int(input())
    while t > 0:
        x = int(input())
        index = binary_search(a, n, x)
        if index == -1:
            print("-1")
        else:
            print(index)
        t -= 1

if __name__ == '__main__':
    main()