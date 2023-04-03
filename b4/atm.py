import math

def atm_algorithm(w,c):

    # initialize variables
    menh_gia = [1000, 2000, 3000, 5000]

    # loop through each input value
    for i in range(num_testcases):
        # check if input value is divisible by 1000
        if w[i] % 1000 != 0:
            print("0")
            continue
        
        count = 0
        money = w[i]
        l = 1
        
        # lặp từ dưới lên tìm mệnh giá to nhất
        for j in range(c[i], -1, -1):
            arrtmp = [0, 0, 0, 0]
            
            # loop through each possible bill value
            for k in range(len(menh_gia) - 1, -1, -1):
                # Example 5000 x 10^c
                tmp = menh_gia[k] * 10**j

                paper_needed = money // tmp

                count += paper_needed
                
                # Trong trường hợp số tiền không chia hết thì thêm 1 tờ
                if paper_needed != 0:
                    arrtmp[k] = 1

                # update số tiền mới sau khi chia
                money %= tmp
            
            # update l based on which bills were used
            if arrtmp[3] == 1 and arrtmp[2] == 1 and arrtmp[0] == 1:
                l *= 3
            elif arrtmp[3] == 1 and arrtmp[0] == 1:
                l *= 2
            elif arrtmp[3] == 0 and arrtmp[2] == 1 and arrtmp[0] == 1:
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