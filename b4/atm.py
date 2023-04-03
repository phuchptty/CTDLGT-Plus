import math

def atm_algorithm(w,c):

    # initialize variables
    menh_gia = [1000, 2000, 3000, 5000]

    # với mỗi test case
    for i in range(num_testcases):
        # kiểm tra có chia hết cho 1000 hay không, nếu không, thì dừng testcase và in ra 0 luôn
        if w[i] % 1000 != 0:
            print("0")
            continue
        
        count = 0
        money = w[i]
        l = 1
        
        # lặp từ dưới lên tìm mệnh giá to nhất
        for j in range(c[i], -1, -1):
            arrtmp = [0, 0, 0, 0] #mảng để xét các trường hợp đặc biệt có nhiều hơn 1 cách chia
            
            # loop through each possible bill value
            for k in range(len(menh_gia) - 1, -1, -1):
                # Example 5000 x 10^c
                tmp = menh_gia[k] * 10**j

                paper_needed = money // tmp #với mệnh giá này thì chả cho khách nhiều nhất bao nhiêu tờ

                count += paper_needed #cộng số tờ đã tính đc
                
                # Trong trường hợp số tiền không chia hết thì thêm 1 tờ
                if paper_needed != 0:
                    arrtmp[k] = 1

                # update số tiền mới sau khi chia
                money %= tmp
            
            # cập nhật l dựa trên số tiền sự dụng tại hàng 10^j
            if arrtmp[3] == 1 and arrtmp[2] == 1 and arrtmp[0] == 1: #9
                l *= 3
            elif arrtmp[3] == 1 and arrtmp[0] == 1: #6
                l *= 2
            elif arrtmp[3] == 0 and arrtmp[2] == 1 and arrtmp[0] == 1: #4
                l *= 2
        
        # print the result for this input value
        print(count, l)

# Read the number of testcases
num_testcases = int(input())

w = []
c = []

# Iterate over the testcases
for i in range(num_testcases):
    # Read the input parameters for the current testcase
    w_i = int(input()) # Amount to withdraw
    c_i = int(input()) # Number of available bills

    w.append(w_i)
    c.append(c_i)

atm_algorithm(w, c)