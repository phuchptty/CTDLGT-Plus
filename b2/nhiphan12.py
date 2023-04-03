if __name__ == "__main__":
    length = int(input())
    arr = []
    choices = [1,0]; # dao vi tri 2 cai nay la duoc

    # khoi tao mang mac dinh la None
    for i in range(0,length):
        arr.append(None)

    def backtracing(i = 0):
        # co 2 gia tri la 0 va 1
        for j in range(0,2):

            arr[i] = choices[j];
            
            if i == length - 1:
                show()
            else:
                backtracing(i + 1);


    def show():
        final = []

        for i in range(0,length):
            final.append(str(arr[i]))

        print("".join(final))

    # run
    backtracing()