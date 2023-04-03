n = int(input())
trees = list(map(int, input().split()))

trees.sort(reverse=True)

party_day = 0
for i in range(n):

    days_to_grow = trees[i]

    party_day = max(party_day, days_to_grow + i + 2)

print(party_day);