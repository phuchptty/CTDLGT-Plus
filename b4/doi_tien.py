money_return = [500,100,50,10,5,1]
money = 1000
n = int(input())

while (n):
    pay = int(input())
    mark = 0
    count = 0
    remain = money - pay
    while True:
        if remain == 0:
            print(count)
            break
        
        if remain < money_return[mark]:
            mark += 1
        else:
            remain -= money_return[mark]
            count += 1
    n -= 1